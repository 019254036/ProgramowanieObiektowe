#include "menu.h"
#include "tablica.h"
#include "cell.h"
#include <iostream>

int main(){
	Tablica tab;	
	przywitanie();
	choose(&tab);

//Tablica&Cell function test:
/*
	Tablica test2;
	test2.load();
	test2.print();
	test2.setSize(2, 2);
	test2.setValue(1, 1, "3");
	test2.print();
	test2.sum(1, 1);
	test2.findMin(1, 0);
	test2.findMax(1, 1);
	test2.findCen(2, 1);
	test2.save();
	test2.load();
*/
	
//Cell class test
/* 
	Cell test1;
	test1.inputValue();
	std::cout<<test1.printValue()<<std::endl;
	std::cout<<test1.ghostIValue()<<std::endl;
	test1.setValue("hehe xd");
	std::cout<<test1.printValue()<<std::endl;
	std::cout<<test1.ghostIValue()<<std::endl;
	test1.setValue("4");
	std::cout<<test1.printValue()<<std::endl;
	std::cout<<test1.ghostIValue()<<std::endl;
*/
	return 0;
}

