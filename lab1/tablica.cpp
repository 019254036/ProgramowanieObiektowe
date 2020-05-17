#include "tablica.h"


int **zmien_rozmiar(int **tab, int *iloscWierszy, int *iloscKolumn){
	if(*iloscWierszy){
		int wiersze = *iloscWierszy;
		while(wiersze){
			wiersze--;	
			delete [] tab[wiersze];
		}
		delete [] tab;
	}
	
	cout<<"Podaj nowa ilosc wierszy: ";
	cin>>*iloscWierszy;
	cout<<"Podaj nowa ilosc kolumn: ";
	cin>>*iloscKolumn;

	tab = new int* [*iloscWierszy];
		for(int i = 0; i < *iloscWierszy; i++){
			tab[i] = new int [*iloscKolumn];
			for(int j = 0; j < *iloscKolumn; j++){
				tab[i][j] = 0;
			}
		}
	cout<<"Stworzono tablice "<<*iloscWierszy<<" na " <<*iloscKolumn<<endl;
	return tab;
}

int aktualizuj_wartosc(int **tab,int iloscWierszy, int iloscKolumn){
	int wiersz;
	int kolumna;
	int wartosc;

	cout<<"Podaj wiersz komorki: ";
	cin>>wiersz;
	cout<<"Podaj kolumne komorki: ";
	cin>>kolumna;
	if(wiersz-1 < iloscWierszy && kolumna-1 < iloscKolumn){
		cout<<"Wybrales komorke "<<wiersz<<" x "<<kolumna<<endl;
		cout<<"Podaj wartosc, ktora ma zostac wpisana do komorki: ";
		cin>>wartosc;
		tab[wiersz-1][kolumna-1] = wartosc;
		return 0;
	}	
	else{
		cout<<"Blad komorki: niepoprawna komorka"<<endl;
	}
}
