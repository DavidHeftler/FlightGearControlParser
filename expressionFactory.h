#pragma once
#include "expression.h"
#include <iostream>



class ExpFactory {
public:
	static Expression* createExp(std::string str); 
};