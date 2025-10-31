#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <numeric>

using namespace std;

struct RandFill
{
	void operator()(vector<int>& row) const
	{
		for_each(row.begin(), row.end(), [](int& val)
			{
				val = rand() % 20;
			});
	
	}
};

struct PrintMatrixRow {
	void operator()(const vector<int>& row) const {
		for_each(row.begin(), row.end(), [](int val) {
			cout << left << setw(4) << val;
			});
		cout << endl;
	}
};

vector<int> increment(const vector<int>& row)
{
	vector<int> newRow(row.size());
	transform(row.begin(), row.end(), newRow.begin(), [](int val) 
		{
			return val + 1;
		});
	return newRow;
}


int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	const int rows = 6;
	const int cols = 3;

	vector<vector<int>> matrix(rows, vector<int>(cols));
	for_each(matrix.begin(), matrix.end(), RandFill());

	cout << "Macierz wypisana przy uzyciu funktora:" << endl;
	for_each(matrix.begin(), matrix.end(), PrintMatrixRow());

	cout << endl << "Macierz wypisana przy uzyciu wyrazenia lambda:" << endl;
	for_each(matrix.begin(), matrix.end(), [](const vector<int>& row) 
	{
	for_each(row.begin(), row.end(), [](int val) 
	{
		cout << left << setw(4) << val;
	});
	cout << endl;
	});
	
	vector<vector<int>> matrixT(cols, vector<int>(rows));
	for (int i = 0; i < rows; ++i) 
	{
		for (int j = 0; j < cols; ++j) 
		{
			matrixT[j][i] = matrix[i][j];
		}
	}

	transform(matrixT.begin(), matrixT.end(), matrixT.begin(), increment);

	cout << endl << "Transpozycja macierzy wypisana przy uzyciu lambdy:" << endl;
	for_each(matrixT.begin(), matrixT.end(), [](const vector<int>& row) 
		{
			for_each(row.begin(), row.end(), [](int val) 
				{
					cout << left << setw(4) << val;
				});
			cout << endl;
		});

	vector<int> firstRowT = matrixT.front();
	sort(firstRowT.begin(), firstRowT.end(), [](int a, int b) 
		{
			return a > b; 
		});

	cout << endl << "Pierwszy rzad macierzyT po sortowaniu malejaco:" << endl;
	for_each(firstRowT.begin(), firstRowT.end(), [](int val) {
		cout << left << setw(4) << val;
		});
	cout << endl;

	transform(firstRowT.begin(), firstRowT.end(), firstRowT.begin(), [](int val) 
		{
			return val * val;
		});

	cout << endl << "Pierwszy rzad macierzyT po podniesieniu elementow do kwadratu:" << endl;
	for_each(firstRowT.begin(), firstRowT.end(), [](int val) 
		{
			cout << left << setw(4) << val;
		});
	cout << endl;

	firstRowT.erase(
		remove_if(firstRowT.begin(), firstRowT.end(), [](int val) 
		{
				return val % 2 != 0; // usuñ nieparzyste
		}),
		firstRowT.end()
		);

	cout << endl << "Pierwszy rzad macierzyT po usunieciu elementow nieparzystych:" << endl;
	for_each(firstRowT.begin(), firstRowT.end(), [](int val) 
		{
			cout << left << setw(6) << val;
		});
	cout << endl;

	int suma = accumulate(firstRowT.begin(), firstRowT.end(), 0);

	cout << endl << "Suma elementow: " << suma << endl;

	return 0;
}