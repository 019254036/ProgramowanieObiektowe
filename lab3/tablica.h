#include <iostream>
#include <fstream>

#ifndef TABLICA_H
#define TABLICA_H
struct Tablica{
	int **tab;
	int iloscWierszy;
	int iloscKolumn;
};
#endif


int zmien_rozmiar(Tablica* arr);

int aktualizuj_wartosc(Tablica arr);

int zapisz_tablice(Tablica arr);

int wczytaj_tablice(Tablica* arr);

int suma_k(Tablica arr);

int suma_w(Tablica arr);

int find_min(Tablica arr, bool wiersz);

int find_max(Tablica arr, bool wiersz);

int find_cen(Tablica arr, bool wiersz);
