
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
    bool czy_prawo_jazdy(); //zwraca true jeśli kierowca ma prawo jazdy i wypisuje komentarz

    string rimie(); //zwraca imie kierowcy
    string rnazwisko(); //zwraca nazwisko kierowcy
    int rwiek(); //zwraca wiek kierowcy
    bool rfprawo_jazdy(); //zwraca true jeśli kierowca ma prawo jazdy

    int wimie(string &imie1); //ustawia podane imie 
    int wnazwisko(string &nazwisko1); //usatwia podane nazwisko
    int wwiek(int& wiek1); //ustawia podany wiek
    int wfprawo_jazdy(bool prawo1); //ustawia prawo_jazdy na podaną wartość

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

