#pragma once
#include <string> 
#include <vector>



class Command {
public:
	virtual void doCommand(std::vector<std::string>& args) = 0;
	virtual ~Command() {}
};



class OpenDataServer : public Command {
public:
	void doCommand(std::vector<std::string>& args);
};




class Connect: public Command {
public:
	void doCommand(std::vector<std::string>& args);
};





class Assign : public Command {
public:
	void doCommand(std::vector<std::string>& args);
};



class Bind :public Command {
public:
	void doCommand(std::vector<std::string>& args);
};



class Var : public Command {
public:
	void doCommand(std::vector<std::string>& args);
};



class Print: public Command {
public:
	void doCommand(std::vector<std::string>& args);
};


class sleep : public Command {
public:
	void doCommand(std::vector<std::string>& args);
};


class Loop: public Command {
public:
	void doCommand(std::vector<std::string>& args);
};


