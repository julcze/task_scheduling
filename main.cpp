#include "funkcje.h"
#include <vector>

int main()
{
	int liczba_zamowien=0;
	vector <zamowienie> tablica_zamowien = {};
		
	pobieranie_danych(liczba_zamowien, tablica_zamowien);
	wyswietlanie_danych(liczba_zamowien, tablica_zamowien);
	vector <zamowienie> kolejnosc = {};
	int czas_zakonczenia = 0;
	algorytm_Shrage(liczba_zamowien, tablica_zamowien, kolejnosc, czas_zakonczenia);
	wyswietlanie_kolejnosci(kolejnosc, czas_zakonczenia);	

	system("pause");
	return 0;
 }

