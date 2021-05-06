#pragma once
#include<string>
#include <map>


#define KEY_NOT_FOUND -11111
#define NOT_A_DIR "not a directory"

class VarMap {
	VarMap(){}
	~VarMap() {} // Prevent unwanted destruction

	//maps flightGear directories to variables
	std::map<std::string, std::string> dirMap;
	//maps numbers to variables
	std::map<std::string, double> valueMap;

public:	
	void setDir(std::string& key, std::string& value);
	void setValue(std::string& key, double value);
	std::string getDir(std::string& key);
	double getValue(std::string& key);	
	void printDirMap();

	//singleton stuff
	static VarMap& Instance();
	VarMap(const VarMap&) = delete;
	VarMap& operator=(const VarMap&) = delete;
};