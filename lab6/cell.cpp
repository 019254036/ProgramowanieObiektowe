#include "cell.h"

using namespace std;
/*
Cell::Cell()
{
	std::string value = "";
	int intValue = 0;
	bool iValue = false;
}
*/
int IntCell::inputValue()
{
	cout<<"Input your int value: ";
	cin>>value;
	return 0;
}

int StrCell::inputValue()
{
	cout<<"Input your string value: ";
	cin>>value;
	return 0;
}


//overloading operators for IntCell
ostream& operator<<(ostream& os, IntCell& cl)
{
	return os<< cl.value;
}

istream& operator>>(istream& is, IntCell& cl)
{
	is >> cl.value;
	std::stringstream convertor;
	convertor<<cl.value;
	convertor>>cl.value;
	return is;
}

//overloading operators for StrCell
ostream& operator<<(ostream& os, StrCell& cl)
{
	return os<< cl.value;
}

istream& operator>>(istream& is, StrCell& cl)
{
	is >> cl.value;
	std::stringstream convertor;
	convertor<<cl.value;
	convertor>>cl.value;
	return is;
}
