#include "menu.h"
#include "tablica.h"
#include "tablica_wysw.h"
#include <iostream>


int main(){
	int menuValue=0;
	int **tab;
	int iloscWierszy;
	int iloscKolumn;

		cin>>iloscWierszy;
		cin>>iloscKolumn;

/* dziala jak marzenie, pozniejsze rysowanie tablicy z funkcji tez sztosik:
		tab = new int* [iloscWierszy];
		for(int i = 0; i < iloscWierszy; i++){
			tab[i] = new int [iloscKolumn];
			for(int j = 0; j < iloscKolumn; j++){
				tab[i][j] = 0;
			}
		}
*/

		zmien_rozmiar(tab, iloscWierszy, iloscKolumn);//w funkcji ten sam kod co wyzej, nie dziala :v
		rysuj_tablice(tab, iloscWierszy, iloscKolumn);//funkcja rysuje i tyle, dopiero przy probie rysowania wywala segmentation faulta...

	//usuniecie tablicy
	while(iloscWierszy){
		iloscWierszy--;	
		delete [] tab[iloscWierszy];
	}
	delete [] tab;

	cout<<"Usunieto"<<endl;

	return 0;
}

