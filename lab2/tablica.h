#include <iostream>
#include <fstream>

using namespace std;

int **zmien_rozmiar(int **tab,int *iloscWierszy, int *iloscKolumn);

int aktualizuj_wartosc(int **tab, int iloscWierszy, int iloscKolumn);

int zapisz_tablice(int **tab, int iloscWierszy, int iloscKolumn);

int **wczytaj_tablice(int **tab, int *iloscWierszy, int *iloscKolumn);
