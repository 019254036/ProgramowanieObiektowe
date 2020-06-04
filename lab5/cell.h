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
	int inputValue();
	friend std::ostream& operator<<(std::ostream& os, Cell& cl);
	friend std::istream& operator>>(std::istream& is, Cell& cl);
};

