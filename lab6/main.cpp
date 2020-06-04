#include "menu.h"
#include "tablica.h"
#include "cell.h"
#include <iostream>

int main(){
//	Tablica tab;
	
//	przywitanie();
//	choose(&tab);

	IntCell intTest;
	StrCell strTest;
	
	intTest.inputValue();
	strTest.inputValue();

	std::cout<<"intTest: "<<intTest<<std::endl;
	std::cout<<"strTest: "<<strTest<<std::endl;
	return 0;
}

