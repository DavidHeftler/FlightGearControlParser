#include "variablsMap.h"
#include "DataMap.h"
#include <iostream>




VarMap& VarMap::Instance() {
	static VarMap instance;
	return instance;
}








void VarMap::setDir(std::string& key, std::string& value) {
	dirMap[key] = value;
	return;
}



void VarMap::setValue(std::string& key, double value) {
	valueMap[key] = value;
	return;
}


double VarMap::getValue(std::string& key) {
	//look in the dirMap first
	if (dirMap.find(key) != dirMap.end()) //key was found there
	{
		std::string dir = dirMap[key];
		return DataMap::Instance().get(dir.c_str());
	}
	if (valueMap.find(key) != valueMap.end())
		return valueMap[key];
	
	return KEY_NOT_FOUND;
}



std::string VarMap::getDir(std::string& key) {
	if (dirMap.find(key) == dirMap.end()) //key wasn't found in dirMap
	{
		return NOT_A_DIR;
	}
	return dirMap[key];
}




void VarMap::printDirMap() {
	for (const auto& [key, value] : this->dirMap)
	{
		std::cout << key << " = " << value << ";" << std::endl;
	}
}