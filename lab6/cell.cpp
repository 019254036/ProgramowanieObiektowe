#include "cell.h"

using namespace std;

Cell::Cell()
{
	std::string value = "";
	int intValue = 0;
	bool iValue = false;
}

int Cell::inputValue()
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
	return 0;
}

ostream& operator<<(ostream& os, Cell& cl)
{
	return os<< cl.value << " " << cl.intValue << " " << cl.iValue;
}

istream& operator>>(istream& is, Cell& cl)
{
	is >> cl.value;
	std::stringstream convertor;
	convertor<<cl.value;
	convertor>>cl.intValue; //if unable to, intValue = 0 by default
	if(!convertor.fail()) cl.iValue = true;
	else cl.iValue = false;
	return is;
}

