// lr1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
vector <string> readFile()
{
    ifstream file("file.txt");
    vector <string> m;
    if (!file.is_open())
    {
        cout << "Ошибка открытия файла!";
    }
    else
    {
        char c1, c2;
        string word = "";
        file.get(c1);
        if (c1 != ' ') word += c1;
        while (file.get(c2))
        {
            if (c2 == ' ')
            {
                if (c1 != ' ')
                {
                    m.push_back(word);

                    word = "";
                }
            }
            else 
                word += c2;
               
            c1 = c2;
        }
        if (c2 != ' ')
            m.push_back(word);
    }
    file.close();
    return m;
}
void outFile(string s) 
{
    ofstream f(u8"output.txt");
    cout << s;
    f  << s;
    f.close();
}

string left(string s)
{
    char s1 = s[s.size()-1];
    s.erase(s.size()-1);
    //cout <<  s1+s << "     in left  -- --"<<endl;
    return s1+s;
}
void decode()
{
    string out = "";
    vector <string> m = readFile();
    string word ;
    for (int i = 0; i < m.size(); i++)
    {
        word = m[i];
        for (int j = 0; j < 3; j++)
            word=left(word);
        
        out += word;
        
        if (i != m.size() - 1)
            out += " ";
    }
   // cout << out << endl;
    outFile(out);
    
}
int main()
{
    setlocale(LC_ALL, "ru");
    decode();
}
