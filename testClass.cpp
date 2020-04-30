#include <vector> // wektory :v
#include <fstream>// zapis/odczyt plikow

class Tablica{
	public:
		int iloscWierszy;
		int iloscKolumn;
		std::vector< std::vector < int > > wektor;

		void test();
		void stworz();	
		void rysuj();
		void zapisz();
		void wczytaj(); //TODO: weryfikacja czy ilosc danych zgada sie z wielkoscia tablicy

		Tablica(int W, int K);
		Tablica();
};

Tablica::Tablica(int W, int K){
	iloscWierszy = W;
	iloscKolumn = K;
	wektor.resize(iloscWierszy);
	for(int i = 0; i < wektor.size();i++){ //wektor.size() == iloscWierszy
		wektor[i].resize(iloscKolumn);
	}
}

Tablica::Tablica(){
	wektor.resize(1);
	wektor[0].resize(1);
}


void Tablica::test(){

	//test dostepu do funkcji wektorowych
	std::cout<<"------Test dostepu-------------------------"<<std::endl;
	wektor.resize(2);
	wektor[0].resize(2);
	wektor[0][0] = 1;
	std::cout<<wektor[0][0]<<std::endl;
	
	//testy wielkosci
	std::cout<<"--------Test wielkosci----------------------"<<std::endl;
	std::cout<<"Zmiana ilosci wektorow na 0"<<std::endl;
	wektor.resize(0);
	std::cout<<"Wielkosc wektora: "<<wektor.size()<<std::endl;
	std::cout<<"Wielkosc [0][0]: "<<wektor[0].size()<<std::endl;
	
	std::cout<<"Zmiana ilosci i dlugosci wektorow na 1"<<std::endl;
	wektor.resize(1);
	wektor[0].resize(1);
	std::cout<<"Wielkosc wektora: "<<wektor.size()<<std::endl;
	std::cout<<"Wielkosc [0][0]: "<<wektor[0].size()<<std::endl;
	
	try{
		std::cout<<"Proba zmiany ilosci wektorow na wartosc ujemna"<<std::endl;
		wektor.resize(-1);
	}catch(std::exception &e){
		std::cout<<"Exception: "<<e.what()<<std::endl;
	}

	//test pamieci
	std::cout<<"-------Test pamieci:----------------------"<<std::endl;
	wektor.resize(1);
	std::cout<<"Ilosc wektorow: "<<wektor.size()<<std::endl;
	std::cout<<"Dlugosc wektorow: "<<wektor[0].size()<<std::endl;
	wektor[0].resize(3);
	std::cout<<"Ilosc wektorow: "<<wektor.size()<<std::endl;
	std::cout<<"Dlugosc wektorow: "<<wektor[0].size()<<std::endl;
	wektor[0][2] = 5;
	wektor[0].resize(1);
	std::cout<<"Ilosc wektorow: "<<wektor.size()<<std::endl;
	std::cout<<"Dlugosc wektorow: "<<wektor[0].size()<<std::endl;
	try{
		std::cout<<"Wartosc komorki spoza dlugosci wektora [0][2]: "<<wektor[0][2]<<std::endl;
	} catch(std::exception &e){
		std::cout<<"Exception: "<<e.what()<<std::endl;
	}
	try{
		std::cout<<"Proba zmiany wartosci komorki spoza dlugosci wektora [0][2] na 3"<<std::endl;
		wektor[0][2] = 3;
	} catch(std::exception &e){
		std::cout<<"Exception: "<<e.what()<<std::endl;
	}
	std::cout<<"Wartosc komorki spoza wektora [0][2]: "<<wektor[0][2]<<std::endl;
	wektor[0].resize(3);
	std::cout<<"Ilosc wektorow: "<<wektor.size()<<std::endl;
	std::cout<<"Dlugosc wektorow: "<<wektor[0].size()<<std::endl;
	std::cout<<"Wartosc [0][2]: "<<wektor[0][2]<<std::endl;
	//TODO: Opracowac sposob czyszczenia pamieci lub upewniania sie, ze index jest w dziedzinie



	std::cout<<"-------------------------------"<<std::endl;
}


void Tablica::stworz(){
	std::cout<<"Podaj ilosc wierszy: 2"<<std::endl;
	iloscWierszy = 2; //std::cin>>iloscWierszy;
	if (iloscWierszy > 0){
		std::cout<<"Podaj ilosc kolumn: 3"<<std::endl;
		iloscKolumn = 3; //std::cin>>iloscKolumn;
	}

	wektor.resize(iloscWierszy);
	if(iloscWierszy == 0) wektor[0].resize(0);
	else{
		for(int i = 0; i < wektor.size();i++){ //wektor.size() = iloscWierszy
			wektor[i].resize(iloscKolumn);
		}
	}

	iloscWierszy = wektor.size();
	iloscKolumn = wektor[0].size();

	std::cout<<"Wielkosc wektora glownego: "<<wektor.size()<<"(size()), "<<iloscWierszy<<" (iloscWierszy)"<<std::endl;
	std::cout<<"Wielkosc wektorow wartosci: "<<wektor[0].size()<<"(size()), "<<iloscKolumn<<" (iloscKolumn)"<<std::endl;
}

//metoda zapisu do pliku txt TODO:binarnie wygladaloby estetyczniej, 
void Tablica::zapisz(){
	std::ofstream plik;
	plik.open ("test.txt", std::ios::out);
	//pierwsze dwie wartosci podaja ilosci wierszy i kolumn
	plik << iloscWierszy;
	plik << " ";
	plik << iloscKolumn;
	plik << " ";
	//plik << "\n";
	//dalej zapisywane sa kolejno wartosci poszczegolnych komorek
	for (int i = 0; i < wektor.size(); i++){
		for(int j = 0; j < wektor[i].size(); j++){
		plik << wektor[i][j];
		plik << " ";
		}
	}
	std::cout<<"Zapisano do pliku"<<std::endl;
	plik.close();
}


void Tablica::wczytaj(){
	std::ifstream plik;
	std::string var;
	plik.open("test.txt", std::ios::in);
	if (plik.is_open()){
		
		std::getline (plik, var, ' ');
		iloscWierszy = std::stoi (var);
		std::getline (plik, var, ' ');
		iloscKolumn = std::stoi (var);
		wektor.resize(iloscWierszy);
		for (int i = 0; i < iloscKolumn; i++){
			arkusz[i].resize(iloscKolumn);
		}
		for (int i = 0; i < iloscWierszy; i++){
			for(int j = 0; j < iloscKolumn; j++){
				std::getline (plik, var, ' ');
				arukusz[i][j] = std::stoi (var);
			}
		}
	}
	
}
/*
void rysuj(){
	for (int i = 0; i < iloscWierszy; i++){
		for (int j = 0; j < iloscKolumn; j++){
		std::cout<<wektor[i][j];
		std::cout<<std::endl;
		}
	}
}*/
