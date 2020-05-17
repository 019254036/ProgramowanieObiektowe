#include "tablica.h"

using namespace std;

int zmien_rozmiar(Tablica* arr){
	if(arr->iloscWierszy){
		int wiersze = arr->iloscWierszy;
		while(wiersze){
			wiersze--;	
			delete [] arr->tab[wiersze];
		}
		delete [] arr->tab;
	}
	
	cout<<"Podaj nowa ilosc wierszy: ";
	cin>>arr->iloscWierszy;
	cout<<"Podaj nowa ilosc kolumn: ";
	cin>>arr->iloscKolumn;

	arr->tab = new int* [arr->iloscWierszy];
		for(int i = 0; i < arr->iloscWierszy; i++){
			arr->tab[i] = new int [arr->iloscKolumn];
			for(int j = 0; j < arr->iloscKolumn; j++){
				arr->tab[i][j] = 0;
			}
		}
	cout<<"Stworzono tablice "<<arr->iloscWierszy<<" na " <<arr->iloscKolumn<<endl;
	return 0;
}

int aktualizuj_wartosc(Tablica arr){
	int wiersz;
	int kolumna;
	int wartosc;

	cout<<"Podaj wiersz komorki: ";
	cin>>wiersz;
	cout<<"Podaj kolumne komorki: ";
	cin>>kolumna;
	if(wiersz-1 < arr.iloscWierszy && kolumna-1 < arr.iloscKolumn){
		cout<<"Wybrales komorke "<<wiersz<<" x "<<kolumna<<endl;
		cout<<"Podaj wartosc, ktora ma zostac wpisana do komorki: ";
		cin>>wartosc;
		arr.tab[wiersz-1][kolumna-1] = wartosc;
		return 0;
	}	
	else{
		cout<<"Blad komorki: niepoprawna komorka"<<endl;
	}
}

int zapisz_tablice(Tablica arr){
	ofstream plik;
	plik.open ("dane.txt");
	plik << arr.iloscWierszy;
	plik << "\n";
	plik << arr.iloscKolumn;
	plik << "\n";
	for (int i = 0; i < arr.iloscWierszy; i++){
		for(int j = 0; j < arr.iloscKolumn; j++){
			plik << arr.tab[i][j];
			plik << ",";
		}
		plik << "\n";
	}
	plik.close();
	cout<<"Zapisano tablice do pliku dane.txt"<<endl;
	return 0;
}

int wczytaj_tablice(Tablica* arr){
	
	//usuniecie z pamieci istniejacej tablicy
	if(arr->iloscWierszy){
		int wiersze = arr->iloscWierszy;
		while(wiersze){
			wiersze--;	
			delete [] arr->tab[wiersze];
		}
		delete [] arr->tab;
	}
	
	ifstream plik;
	string wartosc;
	
	//pobranie wymiarow tablicy
	plik.open("dane.txt");
	getline(plik, wartosc, '\n');
	arr->iloscWierszy = stoi(wartosc);
	getline(plik, wartosc, '\n');
	arr->iloscKolumn = stoi(wartosc);
	
	//stworzenie tablicy o odpowiednich wymiarach
	arr->tab = new int* [arr->iloscWierszy];
	for(int i = 0; i < arr->iloscWierszy; i++){
		arr->tab[i] = new int [arr->iloscKolumn];
		for(int j = 0; j < arr->iloscKolumn; j++){
			arr->tab[i][j] = 0;
		}
	}

	//przypisanie odpowiednich wartosci do tablicy
	for(int i = 0; i < arr->iloscWierszy; i++){
		for(int j = 0; j < arr->iloscKolumn; j++){
			getline(plik, wartosc, ',');
			if(wartosc == "\n") getline(plik, wartosc, ',');
			arr->tab[i][j] = stoi (wartosc);
		}
	}
	plik.close();
	cout<<"Wczytano tablice"<<endl;
	return 0;
}

int suma_k(Tablica arr){
	int sum = 0;
	int k;
	cout<<"Wybierz kolumne: ";
	cin>> k;
	if(k < arr.iloscKolumn){
		for(int i = 0; i < arr.iloscWierszy; i++){
			sum += arr.tab[i][k-1];
		}
		cout<<"Suma wartosci komorek "<<k<<" kolumny: "<<sum<<endl;
		return 0;
	}
	cout<<"Blad niepoprawna wartosc"<<endl;
	return 1;
}

int suma_w(Tablica arr){
	int sum = 0;
	int w;
	cout<<"Wybierz wiersz: ";
	cin>> w;
	if(w < arr.iloscWierszy){
		for(int i = 0; i < arr.iloscWierszy; i++){
			sum += arr.tab[w-1][i];
		}
		cout<<"Suma wartosci komorek "<<w<<" wiersza: "<<sum<<endl;
		return 0;
	}
	cout<<"Blad niepoprawna wartosc"<<endl;
	return 1;
}


int find_min(Tablica arr, bool wiersz){
	int wartosc;	
	int kw;
	if(!wiersz){
		cout<<"Podaj kolumne: ";
		cin>>kw;
		if(kw < arr.iloscKolumn){
			wartosc = arr.tab[0][kw-1];
			for(int i = 1; i < arr.iloscWierszy; i++){
				if(wartosc > arr.tab[i][kw-1]) wartosc = arr.tab[i][kw-1];
			}
			cout<<"Najmniejsza wartosc w "<<kw<<" kolumnie: "<<wartosc<<endl;
			return 0;
		}
		cout<<"Blad: nieprawidlowa wartosc "<<endl;
	}
	else{
		cout<<"Podaj wiersz: ";
		cin>>kw;
		if(kw < arr.iloscWierszy){
			wartosc = arr.tab[kw-1][0];
			for(int i = 1; i < arr.iloscKolumn; i++){
				if(wartosc > arr.tab[kw-1][i]) wartosc = arr.tab[kw-1][i];
			}
			cout<<"Najmniejsza wartosc w "<<kw<<" wierszu: "<<wartosc<<endl;
			return 0;
		}
		cout<<"Blad: nieprawidlowa wartosc "<<endl;
	}
}

int find_max(Tablica arr, bool wiersz){
	int wartosc;	
	int kw;
	if(!wiersz){
		cout<<"Podaj kolumne: ";
		cin>>kw;
		if(kw < arr.iloscKolumn){
			wartosc = arr.tab[0][kw-1];
			for(int i = 1; i < arr.iloscWierszy; i++){
				if(wartosc < arr.tab[i][kw-1]) wartosc = arr.tab[i][kw-1];
			}
			cout<<"Najwieksza wartosc w "<<kw<<" kolumnie: "<<wartosc<<endl;
			return 0;
		}
		cout<<"Blad: nieprawidlowa wartosc "<<endl;
	}
	else{
		cout<<"Podaj wiersz: ";
		cin>>kw;
		if(kw < arr.iloscWierszy){
			wartosc = arr.tab[kw-1][0];
			for(int i = 1; i < arr.iloscKolumn; i++){
				if(wartosc < arr.tab[kw-1][i]) wartosc = arr.tab[kw-1][i];
			}
			cout<<"Najwieksza wartosc w "<<kw<<" wierszu: "<<wartosc<<endl;
			return 0;
		}
		cout<<"Blad: nieprawidlowa wartosc "<<endl;
	}
}

int find_cen(Tablica arr, bool wiersz){
	double cen = 0;
	int kw;
	if(!wiersz){
		cout<<"Wybierz kolumne: ";
		cin>> kw;
		if(kw < arr.iloscKolumn){
			for(int i = 0; i < arr.iloscWierszy; i++){
				cen += arr.tab[i][kw-1];
			}
			cout<<"Srednia wartosci komorek "<<kw<<" kolumny: "<<cen/arr.iloscWierszy<<endl;
			return 0;
		}
	}
	else{
		cout<<"Wybierz wiersz: ";
		cin>>kw;
		if(kw < arr.iloscWierszy){
			for(int i = 0; i < arr.iloscKolumn; i++){
				cen += arr.tab[kw-1][i];
			}
			cout<<"Srednia wartosci komorek "<<kw<<" kolumny: "<<cen/arr.iloscKolumn<<endl;
			return 0;
		}
	}
	cout<<"Blad: nieprawidlowa wartosc "<<endl;
}
