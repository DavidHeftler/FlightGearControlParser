#pragma once
#include "expressionFactory.h"
#include <stack>


class ExpTree {
	Expression* root = nullptr;
	//a stack to let us know which node should we add a new expession to
	std::stack<Expression*> stk;
public:
	void add(Expression* toAdd);
	Expression* getRoot() { return root; }
	~ExpTree() { delete root; }
};



