// lr3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
//нулевая задача

void nul()
{
    ifstream file0("input0.txt");
    string s, out = "";
    vector <string> v;
    file0 >> s;
    char simb = s[0];
    int size = s.size();
    int i = 1;
    while(i < size)
        if (s[i] == simb)
        {
            s.erase(i - 1, 2);
            size -= 2;
            if (i - 2 < 0)
                simb = s[i - 1];
            else
            {
                simb = s[i - 2];
                i--;
            }
        }
        else
        {
            simb = s[i];
            i++;
        }
    cout << s;
}
//генерация кодов грея произвольнольной длины в файл 
void Gray(int k, int n, vector <int> g)
{
    if (k == n)
    {
        for (int i = 0; i < n; i++)
            cout<<g[i];
        cout <<endl;
    }
    else
    {
        Gray(k + 1,n,g);
        g[k] = 1 - g[k];
        Gray(k + 1, n, g);
    }
}
int main()
{ 
    nul();
    int n;
    cout << "Input n: " << endl;
    cin >> n;
    vector <int> g;
    for (int i = 0; i < n; i++)
        g.push_back(0);
   
    ofstream file("output.txt");
    string out = "";
    Gray(0, n, g);
    cout << out;
    file.close();

    
}

