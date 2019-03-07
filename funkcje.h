#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <queue>

using namespace std;

struct zamowienie
{
	int termin_dostepnosci;  //r
	int czas_obslugi;		 //p
	int czas_dostarczenia;   //q 
};

//do ukladania kolejki priorytetowej
struct porownaj_termin_dostepnosci
{
	bool operator()(const zamowienie & proces1, const zamowienie & proces2)
	{
		return proces1.termin_dostepnosci > proces2.termin_dostepnosci;
	}
};

struct porownaj_czas_dostarczenia
{
	bool operator()(const zamowienie & proces1, const zamowienie & proces2)
	{
		return proces1.czas_dostarczenia < proces2.czas_dostarczenia;
	}
};

void wyswietlanie_danych(int liczba_zamowien, vector <zamowienie> tablica_zamowien);
void pobieranie_danych(int &liczba_zamowien, vector <zamowienie> &tablica_zamowien);
void algorytm_Shrage(const int &liczba_zamowien,
					 const vector<zamowienie> &tablica_zamowien, 
					 vector <zamowienie> & kolejnosc, 
					 int &Cmax);
void wyswietlanie_kolejnosci(vector <zamowienie>& kolejnosc, int & Cmax);