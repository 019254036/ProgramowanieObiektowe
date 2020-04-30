#include <iostream>
#include "testClass.cpp"

using namespace std;

void wskaznik();
void func(int *p);
void wektorTestowyJedno();
void wektorTestowyDwu();
void klasa();


int main(){
	system("clear");
	Tablica tablica(4,3);
	//tablica.wektor[2][1] = 11;
	//tablica.zapisz();
	tablica.wczytaj();
	for (int i = 0; i < tablica.iloscWierszy; i++){
		for (int j = 0; j < tablica.iloscKolumn; j++){
		std::cout<<tablica.wektor[i][j]<<' ';
		}
		std::cout<<std::endl;
	}
	//klasa();
	//wskaznik();
	//wektorTestowyJedno();
	//wektorTestowyDwu();
	
	return 0;
}


//test wskaznika
void wskaznik(){
	cout<<"\n\nTest wskaznika: "<<endl;
	int value = 0;
	cout<<"Testing.... Value = "<<value<<endl;
	func(&value);
	cout<<"Testing.... Value = "<<value<<endl;
}

void func(int *valuePointer){
		*valuePointer = 4;
}


//testy implementacji wektorow
void wektorTestowyJedno(){
	cout<<"Test wektora jednowymiarowego: "<<endl;
	//tworzenie wektora jednowymiarowego
	vector < float > wektorTestowy;
	cout<<"Stworzono wektor testowy"<<endl;
	cout<<"Rozmiar wektora testowego = "<<wektorTestowy.size()<<endl;

	//wprowadzenie wartosci na koniec wektora
	for(int i=0; i < 4; i++){
		wektorTestowy.push_back(i*2.5);
		cout<<"dodano wartosc "<<i*2.5<<endl;
	}

	wektorTestowy[0] = -1;
	cout<<"Zmieniono wartosc 0 na -1"<<endl;
	
	//wypisanie wartosci wektora
	for(int i = 0; i < wektorTestowy.size(); i++){
		cout<<"wektorTestowy ["<<i<<"] = "<<wektorTestowy[i]<<endl;
	}

	cout<<"Rozmiar wektora testowego = "<<wektorTestowy.size()<<endl;
	
	//usuwanie ostatniego elementu wektora
	while (wektorTestowy.size()){
		cout<<"usuwam wartosc "<<wektorTestowy.back()<<endl;
		wektorTestowy.pop_back();
	}
	cout<<"Rozmiar wektora testowego = "<<wektorTestowy.size()<<endl;
}


//testy implementacji wektorow wielowymiarowtych
void wektorTestowyDwu(){
	cout<<"\n\nTest wektora dwuwymiarowego: "<<endl;
	int iloscWierszy = 4;
	int iloscKolumn = 5;
	int dummyValue = 0;
	
	//stworzenie wektora -> wektor glowny zawiera iloscWierszy wektorow o dlugosci iloscKolumn
	vector< vector< int > > wektor(iloscWierszy, vector<int>(iloscKolumn));
	cout<<"Stworzono wektor wielowymiarowy o wymiarach "<<iloscWierszy<<" x "<<iloscKolumn<<endl;
	
	//przypisanie wartosci
	for(int i = 0; i < wektor.size(); i++){
		for(int i2 = 0; i2 < wektor[i].size(); i2++){
			wektor[i][i2] = dummyValue;
			dummyValue += 1;
		}
		cout<<"Przypisano wartosci do "<<i+1<<" wiersza"<<endl;
		dummyValue -= 4;
	}

	//wypisanie wartosci
	for(int i = 0; i < wektor.size(); i++){
		for(int i2 = 0; i2 < wektor[i].size(); i2++){
			cout<<wektor[i][i2]<<" ";
		}
		cout<<endl;
	}

	//zmiana wielkosci tablicy
	wektor.resize(iloscWierszy-2);
	for(int i = 0; i < wektor.size(); i++){
	wektor[i].resize(iloscKolumn-3);
	}
	cout<<"Zmieniono wielkosc wektora na "<<iloscWierszy-2<<" x "<<iloscKolumn-2<<endl;
	
	for(int i = 0; i < wektor.size(); i++){
		for(int i2 = 0; i2 < wektor[i].size(); i2++){
			cout<<wektor[i][i2]<<" ";
		}
		cout<<endl;
	}
	
	//usuwanie calej tablicy
	while(wektor.size()) wektor.pop_back();
	cout<<"Usunieto wszystkie elementy wektora glownego"<<endl;	
	cout<<"Wielkosc wektora glownego: "<<wektor.size()<<endl;
}

void klasa(){
	Tablica dupa(2, 3);
	Tablica dupa2;
	cout<<"Wielkosc konstuktora bezargumentowego: "<<dupa2.wektor.size()<<" x "<<dupa2.wektor[0].size()<<endl;
	dupa.test();
	dupa.stworz();
}
