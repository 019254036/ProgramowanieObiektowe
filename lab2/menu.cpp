#include "menu.h"

int przywitanie(){
	system("clear");
	cout<<"Witaj w prostym arkuszu kalkulacyjnym!"<<endl;
	cout<<"Co chcesz zrobic? (Wprowadz odpowiednia wartosc z klawiatury)"<<endl;
	return 0;
}

int menu(int *menuValue){
	int value;
	cout<<"[1] Wyswietl tablice"<<endl;
	cout<<"[2] Zmien rozmiar tablicy"<<endl;
	cout<<"[3] Przypisz wartosc do komorki"<<endl;
	cout<<"[4] Zapisz tablice"<<endl;
	cout<<"[5] Wczytaj tablice"<<endl;
	cout<<"[0] Zakoncz"<<endl;
	cin>>value;
	*menuValue = value;
	return 0;
}
