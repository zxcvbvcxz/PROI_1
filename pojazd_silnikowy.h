

#ifndef POJAZD_SILNIKOWY_H
#define POJAZD_SILNIKOWY_H
#include <string>
#include <iostream>
#include"kierowca.h"
#include "pasazer.h"
#include "bagaznik.h"
#include"bak.h"
#include"silnik.h"

using namespace std;

class pojazd_silnikowy
{
private:
    string marka;
    string model;
    int rocznik = 0;
    double spalanie_na_100km = 9;
    kierowca * kierowca_1 = nullptr;
    bak bak_1;
    silnik silnik_1;

public:

    pojazd_silnikowy(); //konstruktor
    virtual ~pojazd_silnikowy(); //destruktor
    pojazd_silnikowy(const pojazd_silnikowy& orig); //konstruktor kopiujący
    virtual pojazd_silnikowy &operator=(const pojazd_silnikowy & sam1); //operator przypisania

    virtual int in_info() = 0; //wpisuje podstawowe dane 
    virtual int out_info() = 0; //wypisuje podstawowe dane 

    int in_kierowca(); //wprowadza kierowcę do pojazdu
    int out_kierowca(); //wypisuje informacje o kierowcy
    int usun_kierowca(); //usuwa kierowcę z pojazdu
    bool out_prawo_jazdy(); //zwraca true jeśli kierowca ma prawo jazdy

    int in_bak(); //wpisuje ilość paliwa
    int out_bak(); //zwraca i wypisuje ilość paliwa w baku

    int on_silnik(); //włącza silnik
    int off_silnik(); //wyłącza silnik

    int przejedz(double kilometry); //przejeżdża daną liczbę kilometrów

    bool operator++(); //włącza silnik
    bool operator--(); //wyłącza silnik
    friend ostream & operator<<(ostream & os, pojazd_silnikowy &pojazd1); //wypisuje podstawowe informacje
    friend istream & operator>>(istream & is, pojazd_silnikowy &pojazd1);

};

#endif /* POJAZD_SILNIKOWY_H */

