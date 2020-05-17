#include "tablica_wysw.h"
#include <iostream>

int rysuj_tablice(int **tab, int iloscWierszy, int iloscKolumn){
	
	for(int i1 = 0; i1 < iloscWierszy; i1++){
		for(int i2 = 0; i2 < iloscKolumn; i2++){
			std::cout<<tab[i1][i2]<<" ";	
		}
		std::cout<<std::endl;
	}
	return 0;
}
