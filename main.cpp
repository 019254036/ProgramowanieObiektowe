#include "menu.cpp"
#include "tablice.cpp"
#include <iostream>

using namespace std;

int main(){
	int menuValue = 0;
	//int dummyValue = 0;
	Arkusz karkusz(1, 1);
	system("clear");
	do{
		menu(&menuValue);
		system("clear");
		switch(menuValue){
			case 0:
				endSpeach();	
				break;		
			case 1:
				karkusz.rysuj();
				break;
			case 2:
				karkusz.zmienWartosc();
				break;
			case 3:
				karkusz.zmienRozmiar();
				break;
			case 4:
				karkusz.zapisz();
				break;
			case 5:
				karkusz.wczytaj();
				break;
			default:
				cout<<"Opcja niedostepna"<<endl;
				break;
		}
	}while(menuValue != 0);
	return 0;
}
