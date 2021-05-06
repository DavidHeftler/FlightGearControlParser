#include "calcUtil.h"
#include <stack>



std::vector<std::string> CalcUtil::tknExp(std::string& str) {
		std::vector<std::string> vec;
		std::string s = stringUtil::strWithoutSpaces(str);
		std::string tmp = "";
		int i = 0;
		while (i < s.size()) {
			std::string token = std::string(1, s[i]);
			if (oprator(token)) {
				if (tmp.size()) {
					vec.push_back(tmp);
				}
				if (s[i + 1] == '=') {
					tmp = s[i];
					tmp += s[i + 1];
					vec.push_back(tmp);
					tmp = "";
					i+=2;
					continue;
				}
				tmp = s[i];
				vec.push_back(tmp);
				tmp = "";
				++i;
				continue;
			}
			if (s[i] == '(' || s[i] == ')') {
				if (tmp.size())
					vec.push_back(tmp);
				tmp = s[i];
				vec.push_back(tmp);
				tmp = "";
				++i;
				continue;
			}
			tmp += s[i];
			++i;
		}
		if (tmp.size())
			vec.push_back(tmp);
		return vec;
}



int CalcUtil::oprator(const std::string& op) {
		if (op == "!" || op == "=" || op == "!=" || op == "==" || op == "<" ||
			op == "<=" || op == ">" || op == ">=")
			return 1;
		if (op == "+" || op == "+=" || op == "-" || op == "-=")
			return 2;
		if (op == "*" || op == "*=" || op == "/" || op == "/=")
			return 3;
		return 0;
	}


std::vector<std::string> CalcUtil::shntngYrd(std::string& exp) {
		std::vector<std::string> v = tknExp(exp);
		std::stack<std::string> stk;
		std::stack<std::string> stk2;
		for (int i = 0; i < v.size(); i++) {
			if (oprator(v[i])) {
				while (!stk.empty() && oprator(stk.top()) >= oprator(v[i])) {
					stk2.push(stk.top());
					stk.pop();
				}
				stk.push(v[i]);
			}
			else if (v[i] == "(")
			{
				stk.push(v[i]);
			}
			else if (v[i] == ")")
			{
				while (!stk.empty() && stk.top()[0] != '(') {
					stk2.push(stk.top());
					stk.pop();
				}
				stk.pop();
			}
			else//token=number
			{
				stk2.push(v[i]);
			}
		}
		while (!stk.empty() && oprator(stk.top()))
		{
			stk2.push(stk.top());
			stk.pop();
		}
		std::vector<std::string> res;
		while (stk2.size()) {
			res.push_back(stk2.top());
			stk2.pop();
		}
		return res;
	}
