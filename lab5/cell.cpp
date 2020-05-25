#include "cell.h"

using namespace std;

Cell::Cell()
{
	bool math = 0;
	int mathValue = 0;
	string value = " ";
}

void Cell::get_value()
{
	cout<<"Enter your value: ";
	cin>>value;
}

void intValue::get_value()
{
	if(math)
	{
		mathValue = stoi(value);
		math = 1;
	}
	else
	{
		cout<<"Enter you numerical value: ";
		cin>>mathValue;
	}
}

void strValue::get_value(){
	cout<<"Enter your string value: ";
	cin>>value;
}

ostream& operator<<(ostream& os, Cell& cl)
{
	if(cl.mathValue) os << cl.mathValue; return os;
	os << cl.value;
	return os;
}
