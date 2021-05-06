#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>




class stringUtil {

public:
	//tokenizes a string to words
	static std::vector<std::string> lexStr(std::string& str);

	//tokenizes a file to lines
	static std::vector<std::string> lexFile(std::string& fileName);

	static bool isNumber(const std::string& s);

	static bool isDouble(const std::string& s);

	static int strToInt(std::string& to_cnvrt);

	static double strToDouble(std::string& s);

	//takes a string and deletes all spaces from it
	static std::string strWithoutSpaces(std::string& str);

	static std::string getFileTxt(const std::string& dir);

	//sets each curly-brace of a string in a seperate line
	static std::string delimitBraces(const std::string& str);
};