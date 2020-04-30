#include <iostream>

using namespace std;


void menu(int *menuPointer){
	//int dummyValue;
	cout<<"[1]Hello Tablice!"<<endl;
	cout<<"[2]Stworz Tablice"<<endl;
	cout<<"[3]Edytuj Tablice"<<endl;
	cout<<"[4]Aktualizuj Tablice"<<endl;
	cout<<"[5]Narysuj Tablice"<<endl;
	cout<<"[0]Wyjdz"<<endl;
	//petla wymuszajaca podanie poprawnego typu wartosci
	//TODO: naprawic, nie dziala, probowalem na kilka sposobow
	/*
	do{
		cin>>dummyValue;
		if(cin.fail()){
			cout<<"Niepoprawna wartosc"<<endl;
			dummyValue = 0;
			break;}
		else{
			*menuPointer = dummyValue;
			break;}
	}while(! cin.fail());
	*/
	//zastepcza dzialalnosc, wrazliwa na wprowadzenie blednej wartosci
	cin>>*menuPointer;
}
