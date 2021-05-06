#include "stringUtil.h"
#include <sstream>
#include <stdlib.h>
#include <regex>


std::vector<std::string> stringUtil::lexStr(std::string& str)
{
	std::vector<std::string> v;
	std::stringstream strm(str);
	std::string word;
	while (strm >> word) {
		v.push_back(word);
	}
	return v;
}


std::vector<std::string> stringUtil::lexFile(std::string& fileName) {
	std::string content = getFileTxt(fileName);
	content = delimitBraces(content);
	std::vector<std::string> v;
	std::string line = "";
	for (char c : content) {
		if (c == '\n')
		{
			if (line.size())
				v.push_back(line);
			line = "";
		}
		else 
		{
			line += c;
		}
	}
	return v;
}


bool stringUtil::isNumber(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}


bool stringUtil::isDouble(const std::string& s)
{
	char* end = nullptr;
	double val = strtod(s.c_str(), &end);
	return end != s.c_str() && *end == '\0' && val != HUGE_VAL;
}

int stringUtil::strToInt(std::string& toConvert) {

	// object from the class stringstream 
	std::stringstream s(toConvert);


	int x = 0;
	s >> x;
	return x;
}


double stringUtil::strToDouble(std::string& s) {
	char* p;
	return strtod(s.c_str(), &p);
}


std::string stringUtil::strWithoutSpaces(std::string& s) {
	std::string str = s;
	str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
	return str;
}


std::string stringUtil::getFileTxt(const std::string& dir) {
	std::ifstream file(dir);
	std::string content = "";
	std::string tmp = "";
	while (getline(file, tmp))
	{
		content += tmp + "\n";
	}
	return content;
}


std::string stringUtil::delimitBraces(const std::string& str) {
	std::regex re("\\{");
	std::string res = std::regex_replace(str, re, "\n{\n");
	re = "\\}";
	res = std::regex_replace(res, re, "\n}\n");
	//now make sure we didn't get to end-lines one after the other
	re = "\\n\\n";
	res = std::regex_replace(res, re, "\n");
	return res;
}








