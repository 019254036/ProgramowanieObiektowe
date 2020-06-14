#pragma once

#include <iostream>
#include <sstream>
#include "cell.h"

class IntCell:public Cell
{
private:
	int value;
public:
	IntCell();
	int inputValue();
	int showValue();
//	std::string showValue();
	int setValue(std::string);
	int setValue(int);
};
