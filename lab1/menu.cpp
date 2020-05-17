#include "menu.h"
#include "tablica_wysw.h"

int przywitanie(){
	system("clear");
	cout<<"Witaj w prostym arkuszu kalkulacyjnym!"<<endl;
	cout<<"Co chcesz zrobic? (Wprowadz odpowiednia wartosc z klawiatury)"<<endl;
	return 0;
}

int menu(int* menuValue){
	cout<<"[1] Opcja 1"<<endl;
	cout<<"[2] Opcja 2"<<endl;
	cout<<"[3] Opcja 3"<<endl;
	cout<<"[4] Opcja 4"<<endl;
	cout<<"[0] Zakoncz"<<endl;
	cin>> *menuValue;
	return 0;
}
