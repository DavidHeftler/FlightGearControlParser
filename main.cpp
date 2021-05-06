#include "parser.h"
#include "stringUtil.h"
#include "servThread.h"

#include <iostream>

#define DIR "C:/Users/deftl/source/repos/drone/commands.txt"


int main() {
	std::string directory = DIR;
	std::vector<std::string> file = stringUtil::lexFile(directory);
    Parser::Instance().doParse(file);

	ServerThread::Instance().t->join();
	return 0;
}

