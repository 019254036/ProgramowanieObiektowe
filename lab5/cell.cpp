#include "cell.h"

using namespace std;

Cell::Cell()
{
	std::string value = "";
	int intValue = 0;
	bool iValue = false;
}

bool Cell::ghostIValue() 
{
	return iValue;
}

string Cell::inputValue()
{
//getting an input
	cout<<"Input your desired value: ";
	getline(cin, value);
	
//checking if value is viable for mathematical operations
	std::stringstream convertor;
	convertor<<value;
	convertor>>intValue; //if unable to, intValue = 0 by default
	if(!convertor.fail()) iValue = true;
	else iValue = false;
	return value;
}

string Cell::Value()
{
	return value;
}

int Cell::IValue()
{
	if(iValue) return intValue;
	else return 0;
}

string Cell::setValue(string v)
{
	value = v;
	std::stringstream convertor;
	convertor<<value;
	convertor>>intValue; //if unable to, intValue = 0 by default
	if(!convertor.fail()) iValue = true;
	else iValue = false;
	return value;
}


