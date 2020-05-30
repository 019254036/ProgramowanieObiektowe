#include "menu.h"

using namespace std;

int przywitanie(){
	system("clear");
	cout<<"Witaj w prostym arkuszu kalkulacyjnym!"<<endl;
	return 0;
}

int menu(){	
	cout<<"\n------------------------------------------"<<endl;
	cout<<"[1] Wyswietl tablice"<<endl;
	cout<<"[2] Zmien rozmiar tablicy"<<endl;
	cout<<"[3] Przypisz wartosc do komorki"<<endl;
	cout<<"[4] Zapisz tablice"<<endl;
	cout<<"[5] Wczytaj tablice"<<endl;
	cout<<"[6] Suma (wiersz lub kolumna)"<<endl;
	cout<<"[7] Znajdz najmniejsza (wiersz lub kolumna)"<<endl;
	cout<<"[8] Znajdz najwieksza (wiersz lub kolumna)"<<endl;
	cout<<"[9] Wyznacz srednia (wiersz lub kolumna)"<<endl;
	cout<<"[0] Zakoncz"<<endl;
	return 0;
}

int choose(Tablica* tab){
	int option = 0;
	int x;
	int y;
	int value;
	bool w;
	do
	{
		menu();
		cin>>option;
		system("clear");
		switch(option){
			case 0:
				break;
			case 1:
				tab->print();
				break;
			case 2:
				cout<<"Podaj ilosc wierszy: ";
				cin>>x;
				cout<<"Podaj ilosc kolumn: ";
				cin>>y;
				tab->setSize(x, y);
				break;
			case 3:
				cout<<"Podaj wiersz komorki: ";
				cin>>x;
				cout<<"Podaj kolumne komorki: ";
				cin>>y;
				cout<<"Podaj wartosc: ";
				cin>>value;
				tab->setValue(x, y, value);
				break;
			case 4:
				tab->save();
				break;
			case 5:
				tab->load();
				break;
			case 6:
				tab->print();
				cout<<"[1]Wiersz"<<endl;
				cout<<"[2]Kolumna"<<endl;
				cin>>y;
				if(y == 1)
				{
					w = 1;
					cout<<"Podaj numer wiersza: ";
					cin>>x;
				}
				else if(y == 2)
				{
					w = 0;
					cout<<"Podaj numer kolumny: ";
					cin>>x;
				}
				else
				{
					cout<<"Blad wielkosci"<<endl;
					break;
				}
				tab->sum(x, w);
				break;
			case 7:
				tab->print();
				cout<<"[1]Wiersz"<<endl;
				cout<<"[2]Kolumna"<<endl;
				cin>>y;
				if(y == 1)
				{
					w = 1;
					cout<<"Podaj numer wiersza: ";
					cin>>x;
				}
				else if(y == 2)
				{
					w = 0;
					cout<<"Podaj numer kolumny: ";
					cin>>x;
				}
				else
				{
					cout<<"Blad wielkosci"<<endl;
					break;
				}
				tab->findMin(x, w);
				break;
			case 8:
				tab->print();
				cout<<"[1]Wiersz"<<endl;
				cout<<"[2]Kolumna"<<endl;
				cin>>y;
				if(y == 1)
				{
					w = 1;
					cout<<"Podaj numer wiersza: ";
					cin>>x;
				}
				else if(y == 2)
				{
					w = 0;
					cout<<"Podaj numer kolumny: ";
					cin>>x;
				}
				else
				{
					cout<<"Blad wielkosci"<<endl;
					break;
				}
				tab->findMax(x, w);
				break;
			case 9:
				tab->print();
				cout<<"[1]Wiersz"<<endl;
				cout<<"[2]Kolumna"<<endl;
				cin>>y;
				if(y == 1)
				{
					w = 1;
					cout<<"Podaj numer wiersza: ";
					cin>>x;
				}
				else if(y == 2)
				{
					w = 0;
					cout<<"Podaj numer kolumny: ";
					cin>>x;
				}
				else
				{
					cout<<"Blad wielkosci"<<endl;
					break;
				}
				tab->findCen(x, w);
				break;
			default:
				cout<<"Opcja niedostepna, sprobuj ponownie"<<endl;
				break;
		}
	}while(option);
	cout<<"See you soon!"<<endl;
	return 0;
}
