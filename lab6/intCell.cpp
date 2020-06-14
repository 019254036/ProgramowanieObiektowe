#include "intCell.h"

using namespace std;

IntCell::IntCell()
{
	int value = 0;
}

int IntCell::inputValue()
{
	string v;
	cout<<"Wprowadz wartosc typu int: ";
	while(true)
	{
		getline(cin, v);
		std::stringstream convertor;
		convertor<<v;
		convertor>>value; //if unable to, intValue = 0 by default
		if(!convertor.fail()) break;
		else
		{
		cout<<"Niepoprawna wartosc, wprowadz ponownie: ";
		}
	}	
	return 0;
}

int IntCell::showValue()
{
	return value;
}
/*
string IntCell::showValue()
{
	stringstream ss;
	ss << value;
	string s = ss.str();
	return s;
}
*/
int IntCell::setValue(std::string v)
{
	std::stringstream convertor;
	convertor<<v;
	convertor>>value; //if unable to, intValue = 0 by default
	if(convertor.fail())value = 0;cout<<"Niepoprawna wartosc, przypisano '0'"<<endl;
	return 0;
}

int IntCell::setValue(int v)
{
	value = v;
	return 0;
}
