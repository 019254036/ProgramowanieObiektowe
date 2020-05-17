#include "menu.h"
#include "tablica.h"
#include "tablica_wysw.h"
#include <iostream>

/*
	Z powodu problemow w trakcie wykonywania polecen (po konsultacjach 5 maja caly projekt zaczalem od poczatku i zmagalem sie z dobrym zrozumieniem alokacji pamieci) -> brak docblokow (nigdy wczesniej ich nie robilem i nie zdazylem ich opanowac na tyle zeby zrobic je dobrze)
	Brak obslugi wyjatkow 
	Bardzo duzo czasu pochlonely prace nad opanowaniem i zrozumieniem wykorzystywania pamieci  przez tablice dynamiczne oraz zlokalizowanie i zalatanie memory leakow
*/

int main(){
	int menuValue=0;
	Tablica arr;
	arr.iloscWierszy = 0;
	arr.iloscKolumn = 0;
	
	przywitanie();
	while(true){
		menu(&menuValue);
		system("clear");
		if(!menuValue) break;

		switch(menuValue){

			case 1:
				rysuj_tablice(arr);
				break;
			case 2:
				zmien_rozmiar(&arr);
				break;
			case 3:
				aktualizuj_wartosc(arr);
				break;
			case 4:
				zapisz_tablice(arr);
				break;
			case 5:
				wczytaj_tablice(&arr);
				break;
			case 6:
				suma_k(arr);
				break;
			case 7:
				suma_w(arr);
				break;
			case 8:
				find_min(arr, 0);
				break;
			case 9:
				find_min(arr, 1);
				break;
			case 10:
				find_max(arr, 0);
				break;
			case 11:
				find_max(arr, 1);
				break;
			case 12:
				find_cen(arr, 0);
				break;
			case 13:
				find_cen(arr, 1);
				break;
			default:
				std::cout<<"Opcja niedostepna"<<std::endl;	
		}
			
	}
	//usuniecie tablicy
	while(arr.iloscWierszy){
		arr.iloscWierszy--;	
		delete [] arr.tab[arr.iloscWierszy];
	}
	delete [] arr.tab;
	
	return 0;
}

