#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int sumaCyfr(int liczba)
{
    int suma = 0;

    while (liczba > 0)
    {
        suma += liczba % 10;
        liczba /= 10;
    }

    return suma;
}

vector<int> wczytajLiczby()
{
    ifstream plik("plik1.txt");
    vector<int> liczby;
    int x;

    while (plik >> x)
    {
        liczby.push_back(x);
    }

    plik.close();
    return liczby;
}

void sortujWedlugSumyCyfr(vector<int> &liczby)
{
    sort(liczby.begin(), liczby.end(), [](int a, int b)
    {
        return sumaCyfr(a) > sumaCyfr(b);
    });
}

void zapiszWynik(vector<int> liczby)
{
    ofstream wynik("wynik.txt");

    for (int i = 0; i < liczby.size(); i++)
    {
        wynik << liczby[i] << " suma cyfr = " << sumaCyfr(liczby[i]) << endl;
    }

    wynik.close();
}

int main()
{
    vector<int> liczby = wczytajLiczby();

    sortujWedlugSumyCyfr(liczby);

    zapiszWynik(liczby);

    cout << "Gotowe. Wynik zapisano w pliku wynik.txt" << endl;

    return 0;
}