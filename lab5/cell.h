#include <iostream>

#pragma once


class Cell
{
public:
	bool math;
	int mathValue;
	std::string value;

	Cell();
	void get_value();
	friend std::ostream& operator<<(std::ostream& os, Cell& cl);
};

class intValue : public Cell
{
public:
	void get_value();
};

class strValue : public Cell
{
public:
	void get_value();
};


