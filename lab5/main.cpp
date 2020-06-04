#include "menu.h"
#include "tablica.h"
#include "cell.h"
#include <iostream>

int main(){
//	Tablica tab;
	
//	przywitanie();
//	choose(&tab);

	Cell test1;
	test1.inputValue();
	std::cout<<"temporary cout output (value | intValue | iValue): \n"<<test1<<std::endl;
	std::cout<<"Input another value: ";
	std::cin>>test1;
	std::cout<<test1<<std::endl;

	return 0;
}

