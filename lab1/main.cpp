#include "menu.h"
#include "tablica.h"
#include "tablica_wysw.h"
#include <iostream>

int main(){
	int menuValue=0;
	int **tab;
	int iloscWierszy;
	int iloscKolumn;

	przywitanie();
	while (true){
		menu(&menuValue);
		if(menuValue==0) break;
		zmien_rozmiar(tab, &iloscWierszy, &iloscKolumn);
		cout<<iloscWierszy<<iloscKolumn<<endl;
		
	}
	for(int i = 0; i < iloscWierszy; i++){
	delete [] tab[i];
	}
	delete [] tab;
	return 0;
}
