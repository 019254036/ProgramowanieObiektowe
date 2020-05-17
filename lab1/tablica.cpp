#include "tablica.h"


int zmien_rozmiar(int **tab, int iloscWierszy, int iloscKolumn){	

/*	
	int iW = iloscWierszy;
	//usuniecie starej tablicy, jesli istnieje
	while(iW){
		iW--;		
		delete [] tab[iW];
	}
	delete [] tab;
*/
	tab = new int* [iloscWierszy];
	for(int i = 0; i < iloscWierszy; i++){
		tab[i] = new int [iloscKolumn];
		for(int j = 0; j < iloscKolumn; j++){
			tab[i][j] = 0;
		}
	}
	return 0;
}

int aktualizuj_wartosc(int **tab,int wiersz, int kolumna, int wartosc,int iloscWierszy, int iloscKolumn){
	if(wiersz <= iloscWierszy && kolumna <= iloscKolumn){
		tab[wiersz-1][kolumna-1] = wartosc;
		return 0;
	}
}
