#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
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
			cout << LS[i] << "\t" << LO[j] << endl;
			if (A[i][j][0] == 1)
				if (LS[i] < LO[j]) {
					cout << "notSave" << endl; return false;
				}
			if (A[i][j][1] == 1)
				if (LS[i] > LO[j]) { cout << "notSave" << endl; } return false;
		}
	cout << "save" << endl;
	return true;
}
void first()
{
	vector <int> p;
	ifstream input("input.txt");

	vector < vector <vector <int>>> A;

	vector <int> LS;
	vector <int> LO;
	int n, m;
	input >> n;
	input >> m;
	for (int i = 1; i <= n; i++)
	{
		int lev; input >> lev;
		LS.push_back(lev);
	}
	for (int i = 1; i <= m; i++)
	{
		int lev; input >> lev;
		LO.push_back(lev);
	}
	for (int i = 0; i < n; i++)
	{
		vector <vector<int>>b;
		A.push_back(b);
	}
	for (int i = 0; i < n; i++)
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
bool second() {
	vector <int> p;
	ifstream input2("input2.txt");

	vector < vector <vector <int>>> A;


	int n, m;
	input2 >> n;
	input2 >> m;
	vector <int> LS(n);
	vector <int> LO(m);

	for (int i = 0; i < n; i++) {
		LS[i] = (rand() % 3 + 1);
	}
	for (int j = 0; j < m; j++)
		LO[j] = 1;
	for (int i = 0; i < n; i++)
	{
		vector <vector<int>>b;
		A.push_back(b);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			int matr;
			input2 >> matr;
			//cout << "matr" << matr << endl;
			A[i].push_back(inter(matr));
		}

	for (int j = 0; j < m; j++)
	{
		int maxW = -1, minR = 4;
		for (int i = 0; i < n; i++)
			if (A[i][j][0] == 1)
			{
				if (minR > LS[i])
					minR = LS[i];
			}
		for (int i = 0; i < n; i++)
			if (A[i][j][1] == 1)
			{
				if (maxW < LS[i])
					maxW = LS[i];
			}
		if (minR < maxW)
			return false;
		if (maxW != -1)
			LO[j] = maxW;

		else
			LO[j] = minR;

	}
	for (int i = 0; i < n; i++)
		cout << LS[i] << "\t";
	cout << endl;
	for (int j = 0; j < m; j++)
		cout << LO[j] << "\t";
	cout << endl;
	input2.close();
	return true;
}
int main()
{
	setlocale(LC_ALL, "Russian");

	if (second() == false)
		cout << "Система не удовлетворяет критерию";
}