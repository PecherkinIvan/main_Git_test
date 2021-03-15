#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    system("chcp 1251");  system("cls");
    
    ifstream in("input.txt");
 
	if (in.is_open())
	{
		int count = 0, temp;
 
		while (!in.eof())
		{
			in >> temp;
			count++;
		}
 
		in.seekg(0, ios::beg);
		in.clear();
 
		int count_space = 0;
		char symbol;
		while (!in.eof())
		{
			in.get(symbol);
			if (symbol == ' ') count_space++;
			if (symbol == '\n') break;
		}
 
		in.seekg(0, ios::beg);
		in.clear();
 
		int n = count / (count_space + 1); 
		int m = count_space + 1; 
		double **x=new double*[n];
		for (int i = 0; i<n; i++) x[i] = new double[m];
 
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				in >> x[i][j];
 
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				cout << x[i][j] << "\t";
			cout << "\n";
		}
 
		for (int i = 0; i<n; i++) delete[] x[i];
		delete[] x;
 
		in.close();
	}
	else
	{
		cout << "Файл не найден.";
	}
 
	system("pause");
}
