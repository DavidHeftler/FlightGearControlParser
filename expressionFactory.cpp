#include "expressionFactory.h"


Expression* ExpFactory::createExp(std::string str) {
	if (str == "+")
	{
		return new Plus;
	}
	if (str == "-")
	{
		return new Minus;
	}
	if (str == "*")
	{
		return new Mul;
	}
	if (str == "/")
	{
		return new Div;
	}
	if (str == "<")

	{
		return new SmallerThan;
	}
	if (str == "<=")
	{
		return new SmallerOrEqual;
	}


	if (str == ">")
	{
		return new GreaterThan;
	}
	if (str == "==")
	{
		return new Equal;
	}
	if (str == "!=")
	{
		return new NotEqual;
	}
	
	return new Number(str);//if not one of the above, we should treat it as a number
	
}