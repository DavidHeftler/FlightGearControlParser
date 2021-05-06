#include "commandsMap.h"
#include <iostream>


CmdMap::~CmdMap() {
	for (auto const& val : map)
	{
		delete val.second;
	}
}




CmdMap& CmdMap::Instance() {
	static CmdMap instance;
	return instance;
}

Command* CmdMap::get(std::string key) {
	return map[key];
}


void CmdMap::set(std::string key, Command* val) {
	map[key] = val;
	return;
}


void CmdMap::printAll() {
	for (const auto& [key, value] : this->map)
	{
		std::cout << key << " = " << value << ";" << std::endl;
	}
}


