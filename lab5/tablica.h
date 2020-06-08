#include <iostream>
#include <fstream>
#include "cell.h"
#pragma once

class Tablica{
	int sizeX;
	int sizeY;
public:	
	Cell **arr;

//public:
	Tablica();
	~Tablica();

	int print();
	int setSize(int x, int y);
	int setValue(int x, int y, std::string value);
	int sum(int xy, bool x);
	int findMin(int xy, bool x);
	int findMax(int xy, bool x);
	int findCen(int xy, bool x);
	int save();
	int load();
};

