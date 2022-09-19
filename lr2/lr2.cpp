// lr2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//#include <List>
using namespace std;

void nulVar() {
	//нулевая задача
	ifstream file0("input0.txt");
	string s, out = "";
	vector <string> v;
	file0 >> s;
	char simb = s[0];
	int k = 1;
	for (int i = 1; i < s.size(); i++)
		if (s[i] == simb)
			k++;
		else {
			if (k != 1)
				out += to_string(k) + simb;
			else out += simb;
			simb = s[i];
			k = 1;
		}
}
 vector <int> readFile(int & k)
{
	
	string strN, s;
	vector <int> m = {};
	ifstream file("input.txt");
	if (file.is_open())
	{
		file >> k;
		int b;
		//m = new int[k];
		for (int i = 0; i < k; i++)
		{
			file >> b;
			m.push_back(b);
		}
	}
	return m;
}

 bool haveNextBool(vector <bool> s)
 {	 
	int index = s.size() - 1;
	while (index != 0 && s[index] == true)
		if (s[index] == true)
			index--; 
	if (s[index] == true)
		 return false;
	 return true;
 }

 vector <bool> nextBool(vector < bool> s)
 {
	 int n = s.size() - 1;
	 while (s[n] == true)
		 n--;
	 s[n] = true;
	 for (int i = n + 1; i < s.size(); i++)
		 s[i] = false;
	 return s;
 }
 
int main()
{
	vector <int> m;
	int k=0;
	m=readFile( k);
	cout << "k = " << k<<endl;
	for (int i = 0; i < k; i ++)
	{
		cout << m[i] << endl;
	}
	vector <bool> s;
	vector <int> save;
	vector <vector <int>> res;
	for (int i = 0; i < k; i++)
		s.push_back(false);
	int sum = 0;
	
	while (haveNextBool(s))
	{
		s = nextBool(s);
		for (int j = 0; j < k; j++)
			cout << s[j] << "\t";
		cout << endl;
		sum = 0;
		save.clear();
		for (int j = 0; j < k; j++)
			if (s[j] == true) {
				sum += m[j];
				save.push_back(m[j]);
			}
		if (sum % k == 0)
			res.push_back(save);
	}
	ofstream output("output.txt");
	if (res.size() != 0)
	{
		output << "Yes\n";
		for (int i = 0; i < res.size(); i++)
		{
			for (int j = 0; j < res[i].size(); j++)
				output<< res[i][j] << "\t";

			output<<"\n";
		}
	}
	else output << "No";
}
