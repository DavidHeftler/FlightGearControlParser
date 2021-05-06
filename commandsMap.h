#pragma once
#include <map>
#include <string>
#include "commands.h"



class CmdMap {
	CmdMap(){}
	~CmdMap();

	std::map<std::string, Command*> map = {
		{"openDataServer", new OpenDataServer},
		{"connect", new Connect },
		{"var" , new Var},
		{"while", new Loop},
		{"sleep", new sleep},
		{"print", new Print}
	};

public:
	Command* get(std::string key);
	void set(std::string key, Command* val);
	void printAll();

	//singleton stuff
	static CmdMap& Instance();
	CmdMap& operator=(CmdMap&) = delete;
	CmdMap(CmdMap&) = delete;
};
