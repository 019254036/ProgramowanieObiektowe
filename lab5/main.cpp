#include "menu.h"
#include "tablica.h"
#include "cell.h"
#include <iostream>

int main(){
//	Tablica tab;
	
//	przywitanie();
//	choose(&tab);

	Cell test1;
	intValue test2;	
	strValue test3;

	test1.get_value();
	test2.get_value();
	test3.get_value();
	
	std::cout<<test1<<std::endl;
	std::cout<<test2<<std::endl;
	std::cout<<test3<<std::endl;
	return 0;
}

