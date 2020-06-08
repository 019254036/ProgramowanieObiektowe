#include <iostream>
#include <sstream>
#pragma once


class Cell
{
private:
	std::string value;
	int intValue;
	bool iValue;
public:
	Cell();
	bool ghostIValue(); //diagnostic purpose only
	std::string inputValue();
	std::string Value();
	int IValue();
	std::string setValue(std::string v);
};

