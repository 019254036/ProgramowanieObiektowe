#include "menu.h"
#include "tablica.h"
#include "tablica_wysw.h"
#include <iostream>


int main(){
	int menuValue=0;
	int **tab;
	int iloscWierszy = 0;
	int iloscKolumn;

	przywitanie();
	while(true){
		menu(&menuValue);
		system("clear");
		if(!menuValue) break;

		switch(menuValue){

			case 1:
				rysuj_tablice(tab, iloscWierszy, iloscKolumn);
				break;
			case 2:
				tab = zmien_rozmiar(tab, &iloscWierszy, &iloscKolumn);
				break;
			case 3:
				aktualizuj_wartosc(tab, iloscWierszy, iloscKolumn);
				break;
			case 4:
				zapisz_tablice(tab, iloscWierszy, iloscKolumn);
				break;
			case 5:
				tab = wczytaj_tablice(tab, &iloscWierszy, &iloscKolumn);
				break;
			default:
				std::cout<<"Opcja niedostepna"<<std::endl;	
		}
			
	}
	//usuniecie tablicy
	while(iloscWierszy){
		iloscWierszy--;	
		delete [] tab[iloscWierszy];
	}
	delete [] tab;
	
	return 0;
}

