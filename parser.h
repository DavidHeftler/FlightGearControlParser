#pragma once
#include <iostream>
#include <vector>

#define MAX_WORDS_IN_LINE 20
#define END_OF_ARGS "jvwunvwt" 
#define MAX_LINES 40


class Parser {
	Parser() {}
	Parser(const Parser&) {} // Prevent construction by copying
	Parser& operator=(const Parser&) {} // Prevent assignment
	~Parser() {}
public:
	void doParse(std::vector<std::string>& file);
	static Parser& Instance();
};





