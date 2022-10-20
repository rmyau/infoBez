// lr4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <math.h>
using namespace std;

bool indexOf(vector <int> s, int ind)
{
    for (int i = 0; i < s.size(); i++)
        if (s[i] == ind) return true;
    return false;
}
static bool hasNextSochet(vector <int> s, int m)
{
    for (int i = s.size() - 1; i > 0; i--)
        if (s[i] != s[i - 1] + 1) return true;
    if (s[s.size() - 1] == m - 1) return false;
    return true;
}

vector <int> NextSochet(vector <int> s, int m, int k)
{
    if (s[k - 1] != (m - 1)) s[k - 1] += 1;
    else
    {
        int index = k - 1;
        while (s[index] == s[index - 1] + 1 && index > 0)
            index--;
        s[index - 1]++;
        for (int i = index; i < k; i++)
            s[i] = s[i - 1] + 1;
    }
    return s;
}
vector <int> Connect(vector <int> sochet, vector <int> word, int alf, int m)
{
    int Index = 0;
    for (int i = 0; i < m; i++)
        if (word[i] == 0)
        {
            if (indexOf(sochet,Index))
                word[i] = alf;
            Index++;
        }
    return word;
}

void nul() {

    vector <int> word;
    int k = 2;
    vector <int> sochet2 = { 0,0 };
    vector <int> sochet5;
    ofstream output("output.txt");

    while (hasNextSochet(sochet2, 8))
    {
        sochet2 = NextSochet(sochet2, 8, 2);
        /* for (int i = 0; i < 2; i++)
             cout << sochet2[i];
         cout << endl;*/
        sochet5 = { 0,0 };
        while (hasNextSochet(sochet5, 6))
        {
            word.clear();
            word = { 0,0,0,0,0,0,0,0 };
            sochet5 = NextSochet(sochet5, 6, 2);
            word = Connect(sochet2, word, 2, 8);
            word = Connect(sochet5, word, 5, 8);
            for (int i = 0; i < 8; i++)
            {
                if (word[i] == 0) word[i] = 7;
            }
            //string w = "";
            for (int i = 0; i < 8; i++)
                output << word[i];
            output << "\n";
        }
    }
}
bool prost(int n)
{
    if (n == 1) return false;
    for (int i = 2; i < sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}
int mult(int n)
{
    int k = 1;
    while (n != 0)
    {
        k *= n % 10;
        n /= 10;
    }
    return k;
}
int main()
{
    for (int i = 1111; i < 9999; i++)
        if (mult(i) == 243 && prost(i))
            cout << i<<endl;
    
}