#include "menu.h"
#include "tablica.h"
#include "cell.h"
#include "intCell.h"
#include <iostream>

using namespace std;
/*
class StrCell : public Cell
{
private:
	string value;
public:
	IntCell();
	int inputValue();
//	int showValue();
	std::string showValue();
	int setValue(std::string);
	int setValue(int);
};
*/
int main(){

//	Tablica tab;	
//	przywitanie();
//	choose(&tab);

	Tablica lab6;
	lab6.setSize(12, 3);
	lab6.setIntType(6);
	lab6.print();


	return 0;
}

