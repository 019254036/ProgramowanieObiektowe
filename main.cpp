#include "menu.cpp"
#include "tablice.cpp"
#include <iostream>

using namespace std;

int main(){
	system("clear");
	system("clear");
	
	Arkusz karkusz(2,3);
	karkusz.rysuj();
	while(true){
		karkusz.zmienWartosc();
		karkusz.rysuj();
	}
	return 0;
}
