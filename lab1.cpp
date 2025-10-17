#include <iostream>


template <typename T>
class Stos
{
	T* dane;
	int gora;
	int pojemnosc;
public:
	Stos(int rozmiar)
	{
		pojemnosc = rozmiar;
		dane = new T(pojemnosc);
		gora = -1;
	}
	~Stos()
	{
		delete[] dane;
	}
	bool isempty() const
	{
		return gora == -1;
	}
	bool isfull() const
	{
		return gora == pojemnosc - 1;
	}
	void push(const T& wartosc)
	{
		if (isfull())
		{
			std::cout << "Stos jest pelny\n";
			return;
		}
		dane[gora++] = wartosc;
	}
	T pull()
	{
		if (isempty())
		{
			std::cout << "Stos jest pusty\n";
			return T{};
		}
		return dane[gora--];
	}
	int sum() const
	{
		int wynik = 0;
		for (int i = 0; i <= gora; i++)
		{
			wynik = wynik + dane[i];
		}
		return wynik;
	}
};

int main()
{
	Stos<int> s(3);
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	std::cout << "Zsumowana wartosc tablicy to: " << s.sum();

	while (!s.isempty())
	{
		std::cout << s.pull() << " ";
	}
	return 0;
}