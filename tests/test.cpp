#include <iostream>
#include "test.h"

using namespace std;
void test_header(){
	std::cout<<"Successfully entered header's function"<<std::endl;
}

void tablica_Dynamiczna_Jedno(){
	//tworzenie tablicy dynamicznej (tablicy wskaznikow):
	int * tablica = new int[3];
	cout<<"Stworzono tablice dynamiczna jednowymiarowa dlugosci 3!"<<endl;
	cout<<tablica[0]<<" "<<tablica[1]<<" "<<tablica[2]<<endl;
	//tablice nalezy usunac (jak kazdy obiekt dynamiczny):
	delete [] tablica;
	cout<<"Usunieto dotychczasowa tablice!"<<endl;
	
	int size = 4;
	tablica = new int[size];
	cout<<"Stworzono tablice dynamiczna jednowymiarowa dlugosci "<<size<<"!"<<endl;
	cout<<"Rozmiar *tablica*: "<<sizeof(tablica)<<endl;//*tablica* jest wskaznikiem, wiec sizeof() zawasze bedzie rowny 8 :v
	delete [] tablica;
	cout<<"Usunieto dotychczasowa tablice!"<<endl;

	//cin>>size;
	tablica = new int [size];
	for(int i=0; i < size; i++){
		cout<<tablica[i]<<" ";
	}
	cout<<endl;
}
