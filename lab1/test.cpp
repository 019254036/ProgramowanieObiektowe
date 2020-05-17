#include <iostream>

using namespace std;

int main(){
	int menuValue=0;
	int **tab;
	int iloscWierszy = 6;
	int iloscKolumn = 5;

	tab = new int* [iloscWierszy];
	for(int i = 0; i < iloscWierszy; i++){
		tab[i] = new int [iloscKolumn];
	}

	for(int i = 0; i < iloscWierszy; i++){
		delete [] tab[i];
	}
	delete [] tab;

	iloscWierszy = 16;
	iloscKolumn = 3;
	tab = new int* [iloscWierszy];
	for(int i = 0; i < iloscWierszy; i++){
		tab[i] = new int [iloscKolumn];
	}


	for(int i1 = 0; i1 < iloscWierszy; i1++){
		for(int i2 = 0; i2 < iloscKolumn; i2++){
			std::cout<<tab[i1][i2]<<" ";	
		}
		std::cout<<std::endl;
	}

	while(iloscWierszy){
		iloscWierszy--;	
		delete [] tab[iloscWierszy];
	}
	delete [] tab;

	cout<<"Usunieto"<<endl;
	return 0;
}
