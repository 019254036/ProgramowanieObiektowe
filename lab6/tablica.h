#include <iostream>
#include <fstream>
#include "cell.h"
#include "intCell.h"
#pragma once

class Tablica{
	int sizeX;
	int sizeY;
	Cell **arr;

public:
	Tablica();
	~Tablica();

	int print();
	int setSize(int x, int y);
	int setIntType(int);
	int setValue(int x, int y, std::string value);
	int sum(int xy, bool x);
	int findMin(int xy, bool x);
	int findMax(int xy, bool x);
	int findCen(int xy, bool x);
	int save();
	int load();
};

