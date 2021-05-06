#pragma once
#include "stringUtil.h"
#include <vector>

class CalcUtil {
public:
	static std::vector<std::string> tknExp(std::string& str);
	static int oprator(const std::string& op);
	static std::vector<std::string> shntngYrd(std::string& exp);
};
