#include "parser.h"
#include "stringUtil.h"
#include "servThread.h"

#include <iostream>


//add a proper path for your commands file
#define DIR "../exampleCommands.txt"


int main() {
	std::string directory = DIR;
	std::vector<std::string> file = stringUtil::lexFile(directory);
    Parser::Instance().doParse(file);

	ServerThread::Instance().t->join();
	return 0;
}

