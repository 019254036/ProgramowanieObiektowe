#include <iostream>

using namespace std;

int **test_rozmiar(int **tab, int iloscWierszy, int iloscKolumn){

	tab = new int* [iloscWierszy];
		for(int i = 0; i < iloscWierszy; i++){
			tab[i] = new int [iloscKolumn];
			for(int j = 0; j < iloscKolumn; j++){
				tab[i][j] = 0;
			}
		}
	return tab;
}


int main(){
	int menuValue=0;
	int **tab;
	int iloscWierszy = 16;
	int iloscKolumn = 6;

	tab = test_rozmiar(tab, iloscWierszy, iloscKolumn);
	cout<<tab[8][7];
	

	while(iloscWierszy){
		iloscWierszy--;	
		delete [] tab[iloscWierszy];
		cout<<"Usuwanie: "<<iloscWierszy<<endl;
	}
	delete [] tab;

	cout<<"Usunieto"<<endl;
	return 0;
}
