#include "calculator.h"
#include "expTree.h"




double Calculator::doCalculate(std::string& exp) {
		std::vector<std::string> v = CalcUtil::shntngYrd(exp);
		ExpTree tree;
		for (int i = 0; i < v.size(); i++) {
			Expression* e = ExpFactory::createExp(v[i]);
			tree.add(e);
		}
		return tree.getRoot()->calculate();
}
