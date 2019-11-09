
#ifndef KIEROWCA_H
#define KIEROWCA_H

#include <string>
#include <iostream>

using namespace std;

class kierowca
{
private:
    string imie;
    string nazwisko;
    int wiek = 0;
    bool prawo_jazdy = false;

public:

    int in_kierowca(); //wprowadzenie danych do klasy
    int out_kierowca(); //wypisywanie danych
    bool czy_prawo_jazdy(); //zwraca true jeśli kierowca ma prawo jazdy

    string rimie();
    string rnazwisko();
    int rwiek();
    bool rfprawo_jazdy();

    int wimie(string &imie1);
    int wnazwisko(string &nazwisko1);
    int wwiek(int& wiek1);
    int wfprawo_jazdy(bool prawo1);

    bool operator++(); //zwiększa wiek kierowcy o 1
    bool operator--(); //zmniejsza wiek kierowcy o 1
    bool operator<=(kierowca kier1); //porównuje wieki kierowców
    bool operator<(kierowca kier1); //porównuje wieki kierowców
    bool operator>=(kierowca kier1); //porównuje wieki kierowców
    bool operator>(kierowca kier1); //porównuje wieki kierowców
    bool operator==(kierowca kier1); //porównuje wieki kierowców
    friend ostream & operator<<(ostream & os, const kierowca &kier1); //wypisywanie danych klasy
    friend istream & operator>>(istream & is, kierowca &kier1); //wprowadzenie danych do klasy
};
#endif /* KIEROWCA_H */

