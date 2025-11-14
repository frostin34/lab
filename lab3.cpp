#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

void dodaj_imiona_wynik_wiekszy_20(const unordered_map<string, int>& dane, vector<string>& wynik)
{
	for (const auto& [imie, score] : dane)  // C++17
	{
		if (score > 20)
			*back_inserter(wynik) = imie;
	}
}

int main()
{
	unordered_map<string, int> osoby =
	{
		{"Jacob", 23}, {"Jayden", 32}, {"William", 22}, {"Daniel", 25}, {"Noah", 22}, {"James", 53},
		{"Michael", 20}, {"Joseph", 23}, {"Logan", 44}, {"Mason", 21}, {"Jonathan", 32}, {"Landon", 32}
	};

	cout << "Osoby z wynikiem 20:\n";
	bool znaleziono = false;

	for (auto it = osoby.begin(); it != osoby.end(); ++it)
	{
		if (it->second == 20)
		{
			cout << it->first << " (" << it->second << ")\n";
			znaleziono = true;
		}
	}

	if (!znaleziono)
	{
		cout << "Brak osob z wynikiem 20.\n";
	}

	cout << "\nOsoby z wynikiem > 20:\n";

	for (auto it = osoby.begin(); it != osoby.end(); ++it)
	{
		if (it->second > 20)
		{
			cout << it->first << " (" << it->second << ")\n";
		}
	}

	for (auto it = osoby.begin(); it != osoby.end(); )
	{
		if (it->second > 30)
		{
			it = osoby.erase(it);
		}
		else
		{
			++it;
		}
	}
	cout << "\n Tablica po usunieciu osob z wynikiem > 30:\n";
	for (const auto& elem : osoby)
	{
		cout << elem.first << " (" << elem.second << ")\n";
	}

	vector<string> imiona;  

	dodaj_imiona_wynik_wiekszy_20(osoby, imiona);

	cout << "\nImiona osób z wynikiem > 20:\n";
	for (const auto& s : imiona)
	{
		cout << s << "\n";
	}

	vector<string> imiona;
	dodaj_imiona_wynik_wiekszy_20(osoby, imiona);

	cout << "\nImiona osób z wynikiem > 20 (z funkcji):\n";
	for (const auto& s : imiona)
		cout << s << "\n";

	return 0;
}