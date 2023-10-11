#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale.h>

using namespace std;

int CountLinesInFile(string fileName) 
{
    ifstream file(fileName, ios::in);
    string value;
    int count = 0;

    if (!file)
        return -1;

    while (getline(file, value))
        count++;

    file.close();

    return count;
}

vector<string> GetArraySymbols(string fileName, int count)
{
    ifstream file(fileName, ios::in);
    vector<string> symbols(count);

    for (int i = 0; i < count; i++) 
    {
        getline(file, symbols[i]);
    }

    file.close();

    return symbols;
}

void WriteData(string fileName)
{
    ofstream file(fileName, ios::app);

    while (true)
    {
        cout << "\nEnter the data\n" << endl;

        string value = "";

        getline(cin, value);

        if (value.size() == 0)
            break;

        file << value << endl;
    }

    file.close();
}

void ReadData(vector<string> symbols) 
{
    cout << "" << endl;

    for (int i = 0; i < symbols.size(); i++)
    {
        cout << i << ":" << " " << symbols[i] << endl;
    }
}

int main()
{
    string name = "TextFile1.txt";

    int count = CountLinesInFile(name);

    if (count == -1) 
        return -1;
        
    WriteData(name);

    vector<string> symbols = GetArraySymbols(name, CountLinesInFile(name));

    ReadData(symbols);
}
