#include <iostream>
#include <sstream>
#pragma once


class Cell
{
/*
private:
	std::string value;
	int intValue;
	bool iValue;
	*/
public:
//	Cell();
	virtual int inputValue() = 0;
//	friend std::ostream& operator<<(std::ostream& os, Cell& cl);
//	friend std::istream& operator>>(std::istream& is, Cell& cl);
};

class IntCell : public Cell
{
private:
	int value;
public:
	int inputValue();
	friend std::istream& operator>>(std::istream& is, IntCell& cl);
	friend std::ostream& operator<<(std::ostream& os, IntCell& cl);
};

class StrCell : public Cell
{
private:
	std::string value;
public:
	int inputValue();
	friend std::istream& operator>>(std::istream& is, StrCell& cl);
	friend std::ostream& operator<<(std::ostream& os, StrCell& cl);
};
