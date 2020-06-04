#include <iostream>
#include <fstream>
#include "cell.h"
#pragma once

class Tablica{
	int sizeX;
	int sizeY;
	int **arr;

public:
	Tablica();
	~Tablica();

	int print();
	int setSize(int x, int y);
	int setValue(int x, int y, int value);
	int sum(int xy, bool x);
	int findMin(int xy, bool x);
	int findMax(int xy, bool x);
	int findCen(int xy, bool x);
	int save();
	int load();
};

