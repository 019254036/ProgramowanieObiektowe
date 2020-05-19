#include "tablica.h"

Tablica::Tablica(){
	int sizeX = 0;
	int sizeY = 0;	
	int** arr;
}

Tablica::~Tablica(){
	for (int i = 0; i < sizeX; i++)
	{
		delete [] arr[i];
	}
	delete [] arr;
}

int Tablica::print(){
	for (int i = 0; i < sizeX; i++){
		for(int j = 0; j < sizeY; j++){
			std::cout<<arr[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}
int Tablica::setSize(int x, int y){

	if(sizeX){
		for(int i = 0; i < sizeX; i++){
			delete [] arr[i];
		}
		delete [] arr;
	}
		
	sizeX = x;
	sizeY = y;
	
	arr = new int* [sizeX];
	for(int i = 0; i < sizeX; i++){
		arr[i] = new int [sizeY];
		for(int j = 0; j < sizeY; j++){
			arr[i][j] = 0;
		}
	}
	std::cout<<"Zmieniono rozmiar tablicy"<<std::endl;
	return 0;
}

int Tablica::setValue(int x, int y, int value){
	if(x > sizeX || y > sizeY){
		std::cout<<"Blad rozmiaru"<<std::endl;
		return -1;
	}
	
	arr[x-1][y-1] = value;
	return 0;
}

int Tablica::sum(int xy, bool x){
	int sum = 0;
	if (x){
		if (xy > sizeX){
			std::cout<<"Blad rozmiaru"<<std::endl;
			return -1;
		}
		for (int i = 0; i < sizeY; i++){
			sum += arr[xy-1][i];
		}
		std::cout<<"Suma dla "<<xy<<" wiersza: "<<sum<<std::endl;
		return 0;
	}
	if (xy > sizeY){
			std::cout<<"Blad rozmiaru"<<std::endl;
			return -1;
		}
		for (int i = 0; i < sizeX; i++){
			sum += arr[i][xy-1];
		}
		std::cout<<"Suma dla "<<xy<<" kolumny: "<<sum<<std::endl;
		return 0;
}

int Tablica::findMin(int xy, bool x){
	int value = 0;
	if(x){
		if(xy > sizeX){
			std::cout<<"Blad wielkosci"<<std::endl;
			return -1;
		}
		value = arr[xy-1][0];
		for(int i = 1; i < sizeY; i++){
			if(value > arr[xy-1][i]) value = arr[xy-1][i];
		}
		std::cout<<"Najmniejsza wartosc dla "<<xy<<" wiersza: "<<value<<std::endl;
		return 0;
	}
	
	if(xy > sizeY){
		std::cout<<"Blad wielkosci"<<std::endl;
		return -1;
	}
	value = arr[0][xy-1];
	for(int i = 1; i < sizeX; i++){
		if(value > arr[i][xy-1]) value = arr[i][xy-1];
	}
	std::cout<<"Najmniejsza wartosc dla "<<xy<<" kolumny: "<<value<<std::endl;
	return 0;
}

int Tablica::findMax(int xy, bool x){
	double value = 0;
	if(x){
		if(xy > sizeX){
			std::cout<<"Blad wielkosci"<<std::endl;
			return -1;
		}
		value = arr[xy-1][0];
		for(int i = 1; i < sizeY; i++){
			if(value < arr[xy-1][i]) value = arr[xy-1][i];
		}
		std::cout<<"Najwieksza wartosc dla "<<xy<<" wiersza: "<<value<<std::endl;
		return 0;
	}
	
	if(xy > sizeY){
		std::cout<<"Blad wielkosci"<<std::endl;
		return -1;
	}
	value = arr[0][xy-1];
	for(int i = 1; i < sizeX; i++){
		if(value < arr[i][xy-1]) value = arr[i][xy-1];
	}
	std::cout<<"Najwieksza wartosc dla "<<xy<<" kolumny: "<<value<<std::endl;
	return 0;
}

int Tablica::findCen(int xy, bool x){
	int value = 0;
	if(x){
		if(xy > sizeX){
			std::cout<<"Blad wielkosci"<<std::endl;
			return -1;
		}
		for(int i = 0; i < sizeY; i++){
			value += arr[xy-1][i];
		}
		std::cout<<"Srednia wartosc dla "<<xy<<" wiersza: "<<value/sizeY<<std::endl;
		return 0;
	}
	
	if(xy > sizeY){
		std::cout<<"Blad wielkosci"<<std::endl;
		return -1;
	}
	for(int i = 0; i < sizeX; i++){
		value += arr[i][xy-1];
	}
	std::cout<<"Srednia wartosc dla "<<xy<<" kolumny: "<<value/sizeX<<std::endl;
	return 0;
}

int Tablica::save(){
	std::ofstream plik;
	plik.open ("dane.txt", std::fstream::out);
	plik << sizeX;
	plik << "\n";
	plik << sizeY;
	plik << "\n";
	for (int i = 0; i < sizeX; i++){
		for(int j = 0; j < sizeY; j++){
			plik << arr[i][j];
			plik << ",";
		}
		plik << "\n";
	}
	plik.close();
	std::cout<<"Zapisano tablice do pliku dane.txt"<<std::endl;
	return 0;
}

int Tablica::load(){
	if(sizeX){
		for (int i = 0; i < sizeX; i++){
			delete [] arr[i];
		}
		delete [] arr;
	}

	std::ifstream plik;
	std::string wartosc;

	plik.open("dane.txt");
	getline(plik, wartosc, '\n');
	std::cout<<wartosc<<std::endl;
	sizeX = stoi(wartosc);
	getline(plik, wartosc, '\n');
	sizeY = stoi(wartosc);

	arr = new int* [sizeX];
	for(int i = 0; i < sizeX; i++){
		arr[i] = new int [sizeY];
	}
	
	for(int i = 0; i < sizeX; i++){
		for(int j = 0; j < sizeY; j++){
			getline(plik, wartosc, ',');
			if(wartosc == "\n") getline(plik, wartosc, ',');
			arr[i][j] = stoi (wartosc);
		}
	}
	plik.close();
	std::cout<<"Wczytano tablice"<<std::endl;
	return 0;
}
