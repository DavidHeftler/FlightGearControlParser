#include "commands.h"
#include "stringUtil.h"
#include "dataServer.h"
#include "client.h"
#include "servThread.h"
#include "commandsMap.h"
#include "variablsMap.h"
#include "parser.h"
#include "calculator.h"



void OpenDataServer::doCommand(std::vector<std::string>& args) {
	if (args.size() != 3) {
		std::cout << "ilegal num of parameters for OpenServerCommand: 2 required" << std::endl;
		return;
	}
	if (!(stringUtil::isNumber(args[1]) && stringUtil::isNumber(args[2]))) {
		std::cout << "parameters of OpenServerCommand must be numbers" << std::endl;
		return;
	}
	std::cout << "openning dataReaderServer" << std::endl;
	short port = stringUtil::strToInt(args[1]);
	short timesPerSec = stringUtil::strToInt(args[2]);
	DataServer::Instance().waitForConnection(port);
	ServerThread::Instance().t = new std::thread(&DataServer::receive,
		&DataServer::Instance(),
		   timesPerSec);
	return;
}


void Connect::doCommand(std::vector<std::string>& args) {
	if (args.size() != 3) {
		std::cout << "ilegal num of parameters for ConnectCommand " << std::endl;
		return;
	}
	//wait for flightGear to connect to DataServer
	while (DataServer::Instance().getStatus() == false);
	std::cout << "ready to start connection with sumilator" << std::endl;
	short port = stringUtil::strToInt(args[2]);
	flightGearClient::Instance().startConnection(port);
	return;
}


void Var::doCommand(std::vector<std::string>& args) {
	if (args[2] != "=")
	{
		std::cout << "Var error: 3rd token must be '='" << std::endl;
		return;
	}

	if (args[3] == "bind")
	{
		std::vector<std::string> vec = { args[1], args[4] };
		Bind bind;
		bind.doCommand(vec);
		return;
	}

	//we have to call the assignment command. 
	//asign the right hand side expression with the variable on the left hand side
	std::string exp = "";
	int i = 3; //the expression starts at args[3]
	while (i < args.size()) {
		exp += args[i++];
	}
	std::vector<std::string> vec = { args[1], args[2], exp };
	Assign assign;
	assign.doCommand(vec);
	return;
}



void Bind::doCommand(std::vector<std::string>& args) {
	if (args.size() != 2)
	{
		std::cout << "bind command error: illegal number of args" << std::endl;
		return;
	}
	//binding means that now args[0] stands for the directory args[1]
	std::string dir = args[1];
	dir.erase(0, 1);
	dir.erase(dir.size()-1, 1);
	VarMap::Instance().setDir(args[0], dir);

	//since declared as a variable, args[0] now may appear in a begining of a Command. 
	//so attach it to the Assignment command  
	CmdMap::Instance().set(args[0], new Assign);
	return;
}

void Assign::doCommand(std::vector<std::string>& args) {
	if (args[1] != "=")
	{
		std::cout << "Assign error: 2nd arg must be '='\n";
		return;
	}
	std::string exp = "";
	int i = 2;
	while (i < args.size())
		exp += args[i++];

	double d = Calculator::doCalculate(exp);

	//is args[0] a filghtGear directory? or just a variable? 
	//let's check it, so we can know what kind of 'assignment' we are doing 
	std::string str = VarMap::Instance().getDir(args[0]);
	if (str != NOT_A_DIR) 
	//args[0] was a key in the flightGear directories map
	//this means that we want to assign the number 'd' to the flightGear directory placed under the key str   
	{
		std::string num = std::to_string(d);

		std::string msg = "set ";
		msg += str;
		msg += " ";
		msg += num;
		msg += "\r\n";
		const char* c = msg.c_str();
		flightGearClient::Instance().sendMsg(c, strlen(c));
		return;
	}
	//if not, just set args[0] value in valueMap to the number d
	VarMap::Instance().setValue(args[0], d);
	return;
}



void Print::doCommand(std::vector<std::string>& args) {
	if (args.size() != 2)
	{
		std::cout << "illegal number of arguments for Print command" << std::endl;
		return;
	}
	std::string var = args[1];
	double val = VarMap::Instance().getValue(var);
	if (val == KEY_NOT_FOUND)
	{
		//args[1] is not a known variable. So just print it as is
		std::cout <<args[1]<<std::endl;
		return;
	}
	std::cout << var << " = " << val << std::endl;
	return;
}




void sleep::doCommand(std::vector<std::string>& args) {
	if (args.size() != 2)
	{
		std::cout << "illegal number of arguments for Sleep command" << std::endl;
		return;
	}
	double miliSecs = stringUtil::strToDouble(args[1]);
	Sleep(miliSecs);
	return;
}


void Loop::doCommand(std::vector<std::string>& args) {
	//first we set the loop condition: 
	//that is, the first string of 'args', starts after the word "while" 
	std::string cond = "";
	for (int i = 6; i<args[0].size(); i++)
		cond += args[0][i];

	//now set a vector for the loop commands
	std::vector<std::string> loopComands;
	//push in all lines, begin right after the line "{" and ends befor the last line "}"
	for (int i = 2; i < args.size() -1; i++)
		loopComands.push_back(args[i]);

	while (Calculator::doCalculate(cond)) {
		Parser::Instance().doParse(loopComands);
	}
	return;
}











