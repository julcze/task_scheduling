#include "funkcje.h"

void wyswietlanie_danych(int liczba_zamowien, vector <zamowienie> tablica_zamowien)
{
	cout << "Liczba zlecen na jutrzejszy dzien wynosi: " << liczba_zamowien << endl;
	for (int i = 0; i < liczba_zamowien;i++)
	{
		cout << tablica_zamowien[i].termin_dostepnosci << "\t" << tablica_zamowien[i].czas_obslugi
			<< "\t" << tablica_zamowien[i].czas_dostarczenia << endl;
	}

	cout << endl;
}

void pobieranie_danych(int &liczba_zamowien, vector <zamowienie> &tablica_zamowien)
{
	fstream inFile;
	inFile.open("SCHRAGE2.DAT");
	inFile >> liczba_zamowien;
	zamowienie zamowienie_tymczasowe = { 0,0,0 };

	for (int i = 0; i < liczba_zamowien;i++)
	{
		inFile >> zamowienie_tymczasowe.termin_dostepnosci;
		inFile >> zamowienie_tymczasowe.czas_obslugi;
		inFile >> zamowienie_tymczasowe.czas_dostarczenia;

		tablica_zamowien.push_back(zamowienie_tymczasowe);
	}
}

void algorytm_Shrage(const int & liczba_zamowien, const vector<zamowienie> & tablica_zamowien, vector <zamowienie> & kolejnosc, int &Cmax)
{
	int chwila_czasu = 0; //t
	int pozycja_w_permutacji = 0; //k 


	priority_queue <zamowienie, vector<zamowienie>, porownaj_czas_dostarczenia > zadania_gotowe_do_realizacji;
	priority_queue <zamowienie, vector<zamowienie>, porownaj_termin_dostepnosci > zadania_nieuszeregowane;

	for (int i = 0;i < liczba_zamowien; i++)
	{
		zadania_nieuszeregowane.push(tablica_zamowien[i]);
	}

	while (!zadania_nieuszeregowane.empty() or !zadania_gotowe_do_realizacji.empty())
	{
	miejsce_skoku:
		while (!zadania_nieuszeregowane.empty() and ((zadania_nieuszeregowane.top().termin_dostepnosci) <= chwila_czasu))
		{
			zadania_gotowe_do_realizacji.push(zadania_nieuszeregowane.top());
			zadania_nieuszeregowane.pop();
		}
		if (zadania_gotowe_do_realizacji.empty())
		{
			chwila_czasu = zadania_nieuszeregowane.top().termin_dostepnosci;
			goto miejsce_skoku;
		}
		kolejnosc.push_back(zadania_gotowe_do_realizacji.top());
		chwila_czasu = chwila_czasu + zadania_gotowe_do_realizacji.top().czas_obslugi;
		Cmax = max(Cmax, chwila_czasu + zadania_gotowe_do_realizacji.top().czas_dostarczenia);

		zadania_gotowe_do_realizacji.pop();
		pozycja_w_permutacji = pozycja_w_permutacji + 1;

	}
}
	void wyswietlanie_kolejnosci(vector <zamowienie> & kolejnosc, int & Cmax)
	{
		for (int i = 0;i < kolejnosc.size();i++)
		{
			cout << " Zamowienie " << i + 1 << "  r: " << kolejnosc[i].termin_dostepnosci << "  p: " << kolejnosc[i].czas_obslugi
				<< "  q: " << kolejnosc[i].czas_dostarczenia << endl;
		}

		cout <<endl << "Funkcja celu wynosi: " << Cmax << endl;
	}
