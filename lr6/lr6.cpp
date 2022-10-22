// lr6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
//в первой строке - размерности
//во второй - уровни доступа для субъектов
//в третьей - уровни доступа для объектов
//далее идет матрица nxm
vector <int> inter(int n)
{
	vector <int> p;
	switch (n)
	{
	case 0: p.push_back(0);
		p.push_back(0);
		  break;
	case 1:
		p.push_back(0);
		p.push_back(1);
		break;
	case 2:
		p.push_back(1);
		p.push_back(0);
		break;
	case 3:
		p.push_back(1);
		p.push_back(1);
		break;
	}
	//cout << "psixze = " << p.size() << endl;
	return p;
}
bool saveMatr(vector<vector<vector<int>>> A, vector<int> LS, vector<int>LO)
{
	for (int i = 0; i < LS.size(); i++)
		for (int j = 0; j < LO.size(); j++)
		{
			if (A[i][j][0] == 1)
				if (LS[i] < LO[j]) return false;
			if (A[i][j][1] == 1)
				if (LS[i] > LO[j]) return false;
		}

	return true;
			
}
int main()
{
	setlocale(LC_ALL, "Russian");
	vector <int> p;
	ifstream input("input.txt");

	vector < vector <vector <int>>> A;
	
	vector <int> LS;
	vector <int> LO;
	int n,m;
	input >> n;
	input >> m;
	for (int i = 1; i <= n; i++)
	{
		int lev; input >> lev;
		LS.push_back(lev);
	}
	for (int i = 1; i <= n; i++)
	{
		int lev; input >> lev;
		LO.push_back(lev);
	}
	for (int i = 0; i < n; i++)
	{
		vector <vector<int>>b;
		A.push_back(b);
	}
	for (int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			int matr;
			input >> matr;
			//cout << "matr" << matr << endl;
			A[i].push_back(inter(matr));			
		}
	
	/*for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < 2; k++)
				cout << A[i][j][k] << "\t";
			cout << endl;
		}*/
	if (saveMatr(A, LS, LO))
		cout << "Система безопасна";
	else
		cout << "Система не безопасна";
		
	input.close();
	

	


}
