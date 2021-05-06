#include "expTree.h"



void ExpTree::add(Expression* toAdd) {
	if (root == nullptr)
	{
		root = toAdd;
	}
	else
	{
		//were shall we add?
		if (stk.top()->type == BINARY) {
			BinaryExpression* top = static_cast<BinaryExpression*>(stk.top());
			if (top->right == nullptr)
				top->right = toAdd;
			else
				top->left = toAdd;
		}
		else if (stk.top()->type == UNARY)
		{
			UnaryExpression* top = static_cast<UnaryExpression*>(stk.top());
			top->exp = toAdd;
		}
	}
	if (toAdd->type == NUMBER) {
		//we just added a number. so let's see what can we remove from the stack
		while (stk.size()) {
			if (stk.top()->type == BINARY) {
				BinaryExpression* top = static_cast<BinaryExpression*>(stk.top());
				if (top->left && top->right) //top has now 2 sons, he should be removed
					stk.pop();
				else
					return;
			}
			else if (stk.top()->type == UNARY)
			{
				UnaryExpression* top = static_cast<UnaryExpression*>(stk.top());
				if (top->exp)
					stk.pop();
				else
					return;
			}
		}
	}
	//we added an operator, so we should push it into stak
	stk.push(toAdd);
	return;
}


