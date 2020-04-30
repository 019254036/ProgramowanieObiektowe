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

		//konstruktor:
		Arkusz(int w, int k);

		//funkcje:
		void stworz(); // TODO: moze lepiej konstruktorem w main.cpp?
		void rysuj(); // TODO: rowne kolumny i wiersze
		void zmienRozmiar(); // TODO: ochrona przed wprowadzeniem niewlasciwej wartosci
		void zmienWartosc(); // TODO: --||--
		void zapisz(); // TODO: zapisywanie pod roznymi nazwami?
		void wczytaj(); // TODO: zdiagnozowac i naprawic blad -> chyba sie udalo -> posprzatac
};

//konstruktor z parametrem, tworzy arkusz w x k
Arkusz::Arkusz(int w, int k){
	iloscWierszy = w;
	iloscKolumn = k;
		
	arkusz.resize(w);
	for(int i = 0; i < arkusz.size();i++) arkusz[i].resize(k);
	//std::cout<<"Stworzono arkusz "<<iloscWierszy<< " x "<<iloscKolumn<<std::endl;
}

void Arkusz::rysuj(){
	system("clear");
	std::cout<<"Aktualny arkusz ("<<iloscWierszy<<" x "<<iloscKolumn<<")"<<std::endl;
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

	//wczytywanie danych czasem crashuje program, proba diagnozy: (nie dziala, program podczas wczytywania czasem wywala 'losowo' bledy)
/*	
	std::getline (plik, wartosc, ' ');
	try{
		iloscWierszy = std::stoi (wartosc);//stoi -> wartosci musza byc calkowite
	}catch(std::exception &e){
		std::cout<<"Standard exception was caught with message "<<e.what()<<std::endl;
	}
	
	std::getline (plik, wartosc, ' ');
	try{
		iloscKolumn = std::stoi (wartosc);
	}catch(std::exception &e){
		std::cout<<"Standard exception was caught with message "<<e.what()<<std::endl;
	}
*/

	std::getline (plik, wartosc, ' ');
	iloscWierszy = std::stoi (wartosc);
	std::getline (plik, wartosc, ' ');
	iloscKolumn = std::stoi (wartosc);
	arkusz.resize(0);//proba zmiany sposobu powiekszania wektora glownego, zdaje sie czesciowo pomoc, nie eliminuje problemu... XD ocochodzi... Dlaczego niby dziala, ale w sumie to nie....Edit:Po zmianie stoi na stof blad wydaje sie znikac Edit2: po przepisaniu wszystkiego od poczatku wydaje sie dzialac poprawnie

	//std::cout<<iloscWierszy<<iloscKolumn<<std::endl; //szukanie bladu wartosci
	if (iloscWierszy == 1){
	arkusz.push_back(std::vector<float>()); 
	arkusz[0].resize(iloscKolumn);
	}
	else{
		for (int i=0; i < iloscWierszy; i++){
			arkusz.push_back(std::vector <float>());
			arkusz[i].resize(iloscKolumn);
		}	
	}

/*
	if (iloscKolumn = 1)
	for (int i = 0; i < iloscKolumn; i++){
		arkusz[i].resize(iloscKolumn);
	}
*/
	for (int i = 0; i < iloscWierszy; i++){
		for(int j = 0; j < iloscKolumn; j++){
			std::getline (plik, wartosc, ' ');
			arkusz[i][j] = std::stof (wartosc);//stof -> wartosci moga byc float'ami
		}
	}
	plik.close();
	std::cout<<"Wczytano! "<<std::endl;
}
