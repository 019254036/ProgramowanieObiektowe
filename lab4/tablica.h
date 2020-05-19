#include <iostream>
#include <fstream>

/*
//niepoprawne zastosowanie klasy: krytyczne wlasciwosci umieszczone jako publiczne
class Array{
public:
	int sizeX;
	int sizeY;
	int **arr;

	int setSize(int x, int y);
	int setValue(int x, int y, int value);
		//...
};
*/

#ifndef TABLICA_H
#define TABLICA_H

//poprawne zastosowanie klasy: dostep tylko do metod, ktore wplywaja na pozostale parametry
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

#endif
