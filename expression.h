#pragma once
#include <iostream>

#define NUMBER 0
#define UNARY  1
#define BINARY 2
 



class Expression {
public:
	short type;
	virtual double calculate() = 0;
	virtual ~Expression() {}
};


class Number : public Expression {
	std::string num;
public:
	Number(std::string& n) {
		num = n;
		type = NUMBER;
	}
	double calculate();
};


class BinaryExpression : public Expression {
public:
	BinaryExpression() { type = BINARY; }
	Expression* left = nullptr;
	Expression* right = nullptr;
	virtual double calculate() = 0;
};



class Plus : public BinaryExpression {
public:
	double calculate();
	~Plus();
};

class Minus : public BinaryExpression {
public:
	double calculate();
	~Minus();
};


class Mul : public BinaryExpression {
public:
	double calculate();
	~Mul();
};


class Div : public BinaryExpression {
public:
	double calculate(); 
	~Div();
};



class GreaterThan : public BinaryExpression {
public:
	double calculate();
	~GreaterThan();
};



class SmallerThan : public BinaryExpression {
public:
	double calculate();
	~SmallerThan();
};





class Equal : public BinaryExpression {
public:
	double calculate();
	~Equal();
};



class NotEqual : public BinaryExpression {
public:
	double calculate();
	~NotEqual();
};


class SmallerOrEqual : public BinaryExpression {
public:
	double calculate();
	~SmallerOrEqual();
};



class UnaryExpression : public Expression {
public:
	UnaryExpression() { type = UNARY; }
	Expression* exp = nullptr;
	virtual double calculate() = 0;
};




class Not : public UnaryExpression {
public:
	double calculate();
	~Not();
};