#include <vector>
#include <fstream>


//zamiast nazwy 'tablica' stosuje 'arkusz', tak zaczalem i jeszcze nie znalazlem powodu zeby zmieniac
class Arkusz{
	public:
		//wielkosci zawierajace rozmiar arkusza (nie wiem czy sie przyda, zazwyczaj i tak stosuje .size())
		int iloscWierszy;
		int iloscKolumn;
		//wektor dwuwymiarowy bedacy arkuszem
		std::vector < std::vector<float> > arkusz;

		//konstruktory:
		Arkusz();
		Arkusz(int w, int k); //TODO:niewlasciwe wartosci

		//funkcje:
		void stworz(); // TODO: moze lepiej konstruktorem w main.cpp?
		void rysuj(); // TODO: rowne kolumny i wiersze
		void zmienRozmiar(); // TODO: ochrona przed wprowadzeniem niewlasciwej wartosci
		void zmienWartosc(); // TODO: --||--
		void zapisz(); // TODO: zapisywanie pod roznymi nazwami?
		void wczytaj(); // TODO: upewnienie sie ze ilosc danych odpowiada wielkosci tablicy (zwrocic blad/ poszerzyc tablice)
};

//konstruktor bez parametru, tworzy arkusz 1 x 1
Arkusz::Arkusz(){
	arkusz.resize(1);
	arkusz[0].resize(1);

	iloscWierszy = arkusz.size();
	iloscKolumn = arkusz[0].size();
}

//konstruktor z parametrem, tworzy arkusz w x k
Arkusz::Arkusz(int w, int k){
	iloscWierszy = w;
	iloscKolumn = k;
		
	arkusz.resize(w);
	for(int i = 0; i < arkusz.size();i++) arkusz[i].resize(k);
	std::cout<<"Stworzono arkusz "<<iloscWierszy<< " x "<<iloscKolumn<<std::endl;
}

void Arkusz::rysuj(){
	system("clear");
	for(int i1 = 0; i1 < iloscWierszy; i1++){
		for(int i2 = 0; i2 < iloscKolumn; i2++){
		std::cout<<arkusz[i1][i2]<<" ";
		}
		std::cout<<std::endl;
	}
}

void Arkusz::zmienRozmiar(){
	std::cout<<"Podaj nowe wymiary arkusza: "<<std::endl;
	std::cout<<"Wiersze: ";
	std::cin>>iloscWierszy;
	std::cout<<"Kolumny: ";
	std::cin>>iloscKolumn;
	arkusz.resize(iloscWierszy);
	for(int i = 0; i < iloscWierszy; i++) arkusz[i].resize(iloscKolumn);
}

void Arkusz::zmienWartosc(){
	int w;
	int k;
	float value;

	std::cout<<"Podaj wspolrzedne komorki: "<<std::endl;
	std::cout<<"Wiersz: ";
	std::cin>>w;
	std::cout<<"Kolumna: ";
	std::cin>>k;

	std::cout<<"Podaj wartosc ktora przypisac do komorki ("<<w<<" , "<<k<<")"<<std::endl;
	std::cin>>value;

	arkusz[w-1][k-1] = value;//w-1, k-1 -> dla uzytkownika nie ma 'zerowego' wiersza
}

void Arkusz::zapisz(){
	std::ofstream plik;
	plik.open ("dane.txt"/*, std::ios::out*/);
	//pierwsze dwie wartosci podaja ilosci wierszy i kolumn
	plik << iloscWierszy;
	plik << " ";
	plik << iloscKolumn;
	plik << " ";
	//plik << "\n";
	//dalej zapisywane sa kolejno wartosci poszczegolnych komorek
	for (int i = 0; i < arkusz.size(); i++){
		for(int j = 0; j < arkusz[i].size(); j++){
		plik << arkusz[i][j];
		plik << " ";
		}
	}
	std::cout<<"Zapisano! "<<std::endl;
	plik.close();
}


void Arkusz::wczytaj(){
	std::ifstream plik;
	std::string wartosc;//zamiast string'a moznaby uzyc zmiennych char[], string wydal mi sie wygodniejszy, implementacja char[] bylaby nieco inna
	plik.open("dane.txt");
	if (plik.is_open()){
		
		std::getline (plik, wartosc, ' ');
		iloscWierszy = std::stoi (wartosc);
		std::getline (plik, wartosc, ' ');
		iloscKolumn = std::stoi (wartosc);
		arkusz.resize(iloscWierszy);
		for (int i = 0; i < iloscKolumn; i++){
			arkusz[i].resize(iloscKolumn);
		}
		for (int i = 0; i < iloscWierszy; i++){
			for(int j = 0; j < iloscKolumn; j++){
				std::getline (plik, wartosc, ' ');
				arkusz[i][j] = std::stoi (wartosc);
			}
		}
	}
	plik.close();
	std::cout<<"Wczytano! "<<std::endl;
}
