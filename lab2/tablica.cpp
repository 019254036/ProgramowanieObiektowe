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

int zapisz_tablice(int **tab, int iloscWierszy, int iloscKolumn){
	ofstream plik;
	plik.open ("dane.txt");
	plik << iloscWierszy;
	plik << "\n";
	plik << iloscKolumn;
	plik << "\n";
	for (int i = 0; i < iloscWierszy; i++){
		for(int j = 0; j < iloscKolumn; j++){
			plik << tab[i][j];
			plik << ",";
		}
		plik << "\n";
	}
	plik.close();
	cout<<"Zapisano tablice do pliku dane.txt"<<endl;
	return 0;
}

int **wczytaj_tablice(int **tab, int *iloscWierszy, int *iloscKolumn){
	
	//usuniecie z pamieci istniejacej tablicy
	if(*iloscWierszy){
		int wiersze = *iloscWierszy;
		while(wiersze){
			wiersze--;	
			delete [] tab[wiersze];
		}
		delete [] tab;
	}
	
	ifstream plik;
	string wartosc;
	
	//pobranie wymiarow tablicy
	plik.open("dane.txt");
	getline(plik, wartosc, '\n');
	*iloscWierszy = stoi(wartosc);
	getline(plik, wartosc, '\n');
	*iloscKolumn = stoi(wartosc);
	
	//stworzenie tablicy o odpowiednich wymiarach
	tab = new int* [*iloscWierszy];
	for(int i = 0; i < *iloscWierszy; i++){
		tab[i] = new int [*iloscKolumn];
		for(int j = 0; j < *iloscKolumn; j++){
			tab[i][j] = 0;
		}
	}

	//przypisanie odpowiednich wartosci do tablicy
	for(int i = 0; i < *iloscWierszy; i++){
		for(int j = 0; j < *iloscKolumn; j++){
			getline(plik, wartosc, ',');
			if(wartosc == "\n") getline(plik, wartosc, ',');
			tab[i][j] = stoi (wartosc);
		}
	}
	plik.close();
	cout<<"Wczytano tablice"<<endl;
	return tab;
}
