#include "tablica_wysw.h"

int rysuj_tablice(Tablica arr){
	for(int i1 = 0; i1 < arr.iloscWierszy; i1++){
		for(int i2 = 0; i2 < arr.iloscKolumn; i2++){
			std::cout<<arr.tab[i1][i2]<<" ";	
		}
		std::cout<<std::endl;
	}
	return 0;
}
