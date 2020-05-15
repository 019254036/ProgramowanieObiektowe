#include <iostream>

using namespace std;



void menu(int *menuPointer){
	cout<<"[1]Wyswietl arkusz"<<endl;
	cout<<"[2]Zmien wartosc komorki"<<endl;
	cout<<"[3]Zmien rozmiar arkusza"<<endl;
	cout<<"[4]Zapisz arkusz"<<endl;
	cout<<"[5]Wczytaj arkusz"<<endl;
	cout<<"[0]Wyjdz"<<endl;
	cin>>*menuPointer;
}

void endSpeach(){
	cout<<"Zamykam program"<<endl;
}
