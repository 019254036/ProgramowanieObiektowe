#include "menu.h"

using namespace std;

int przywitanie(){
	system("clear");
	cout<<"Witaj w prostym arkuszu kalkulacyjnym!"<<endl;
	return 0;
}

int menu(int *menuValue){
	int value;	
	cout<<endl;
	cout<<"[1] Wyswietl tablice"<<endl;
	cout<<"[2] Zmien rozmiar tablicy"<<endl;
	cout<<"[3] Przypisz wartosc do komorki"<<endl;
	cout<<"[4] Zapisz tablice"<<endl;
	cout<<"[5] Wczytaj tablice"<<endl;
	cout<<"[6] Suma kolumny"<<endl;
	cout<<"[7] Suma wiersza"<<endl;
	cout<<"[8] Znajdz najmniejsza w kolumnie"<<endl;
	cout<<"[9] Znajdz najmniejsza w wierszu"<<endl;
	cout<<"[10] Znajdz najwieksza w kolumnie"<<endl;
	cout<<"[11] Znajdz najwieksza w wierszu"<<endl;
	cout<<"[12] Wyznacz srednia kolumny"<<endl;
	cout<<"[13] Wyznacz srednia wiersza"<<endl;
	cout<<"[0] Zakoncz"<<endl;
	cin>>value;
	*menuValue = value;
	return 0;
}
