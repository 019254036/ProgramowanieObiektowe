#pragma once

#include <iostream>
#include <sstream>

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
	std::string showValue();
	int IValue();
	std::string setValue(std::string);
};

