#include "parser.h"
#include "stringUtil.h"
#include "commands.h"
#include "commandsMap.h"

#include <iostream>
#include <string>



Parser& Parser::Instance() {
	static Parser instance;
	return instance;
}




void Parser::doParse(std::vector<std::string>& fileTxt) {
	int line = 0;
	while (line < fileTxt.size())
	{
		std::vector<std::string> tokens = stringUtil::lexStr(fileTxt[line]);
		if (tokens[0] != "while")
		{
			Command* cmd = CmdMap::Instance().get(tokens[0]);
			cmd->doCommand(tokens);
			++line;
		}
		else
		{
			std::vector<std::string> loopLines = { fileTxt[line], fileTxt[line+1] };
			int openBraces = 1;
			int i = line + 2;
			while (i < fileTxt.size() && openBraces)
			{
				if (fileTxt[i] == "{")
					openBraces++;
				if (fileTxt[i] == "}")
					openBraces--;
				loopLines.push_back(fileTxt[i++]);
			}
			Loop loop;
			loop.doCommand(loopLines);
			//finished with the loop, let's get back to the rest of the script
			line = i;
		}
	}
	return;
}
















