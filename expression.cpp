#include "expression.h"
#include "stringUtil.h"
#include "variablsMap.h"
#include <iostream>


#define CALCULATE_ERROR -111111111



double Number::calculate() {
	if(stringUtil::isDouble(num))
		return stringUtil::strToDouble(num);
	return VarMap::Instance().getValue(num);
}



double Plus::calculate() { 
	return left->calculate() + right->calculate();
}


Plus::~Plus() {
	delete left; delete right;
}


double Minus::calculate() {
	if (left == nullptr)
		return -right->calculate();
	return left->calculate() - right->calculate();
}

	
Minus::~Minus() {
	if (left != nullptr)
		delete left;
	delete right;
}



double Mul::calculate() { 
	return left->calculate() * right->calculate(); 
}



Mul::~Mul() {
		delete left; 
		delete right;
}


double Div::calculate() { 
	return left->calculate() / right->calculate();
}


Div::~Div() {
		delete left;
		delete right;
}



double GreaterThan::calculate() { 
	return left->calculate() > right->calculate(); 
}
	

GreaterThan::~GreaterThan() {
		delete left; 
		delete right;
}



double SmallerThan::calculate() { 
	return left->calculate() < right->calculate(); 
}
	

SmallerThan::~SmallerThan() {
		delete left; 
		delete right;
}




double Equal::calculate() { 
	return left->calculate() == right->calculate(); 
}
	
Equal::~Equal() {
		delete left; 
		delete right;
}




double NotEqual::calculate() { 
	return left->calculate() != right->calculate(); 
}


NotEqual::~NotEqual() {
		delete left; 
		delete right;
}




double SmallerOrEqual::calculate() {
	return left->calculate() <= right->calculate();
}


SmallerOrEqual::~SmallerOrEqual() {
	delete left;
	delete right;
}



double Not::calculate() {
	return exp->calculate() == false;
}



Not::~Not() {
	delete exp;
}