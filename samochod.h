
#ifndef SAMOCHOD_H
#define SAMOCHOD_H
#include <string>
#include <iostream>
#include"kierowca.h"
#include "pasazer.h"
#include "bagaznik.h"
#include"bak.h"
#include"silnik.h"

using namespace std;

class samochod
{
private:
    string marka;
    string model;
    int rocznik = 0;
    int miejsca_dla_pasazerow = 0;
    double spalanie_na_100km = 9;
    kierowca * kierowca_1 = nullptr;
    pasazer * pasazerowie = nullptr;
    bagaznik bagaznik_1;
    bak bak_1;
    silnik silnik_1;


public:
    samochod(); //konstruktor
    ~samochod(); //destruktor
    samochod(const samochod & sam1); //konstruktor kopiujący
    samochod &operator=(const samochod & sam1); //operator przypisania
    int in_info(); //wpisuje podstawowe dane o samochodzie
    int out_info(); //wypisuje podstawowe dane o samochodzie

    int in_kierowca(); //wprowadza kierowcę do auta
    int out_kierowca(); //wypisuje informacje o kierowcy
    int usun_kierowca(); //usuwa kierowcę z auta
    bool out_prawo_jazdy(); //zwraca true jeśli kierowca ma prawo jazdy

    int in_pasazer(int miejsce); //wprowadza pasażera na dane miejsce
    int out_pasazer(int miejsce); //wypisuje dane pasażera z danego miejsca
    int out_all_pasazer(); //wypisuje dane wszystkich pasażerów z auta
    int usun_pasazer(int miejsce); //usuwa pasażera z danego miejsca
    int usun_all_pasazer();//usuwa wszystkich pasażerów z auta

    int open_bagaznik(); //otwiera bagażnik
    int close_bagaznik(); //zamyka bagażnik
    int zaladuj_bagaznik(); //ładuje bagażnik
    int rozladuj_bagaznik(); //rozładowuje bagżnik

    int in_bak(); //wpisuje ilość paliwa
    int out_bak(); //zwraca i wypisuje ilość paliwa w baku

    int on_silnik(); //włącza silnik
    int off_silnik(); //wyłącza silnik

    int przejedz(double kilometry); //przejeżdża daną liczbę kilometrów

    bool operator++(); //włącza silnik
    bool operator--(); //wyłącza silnik
    friend ostream & operator<<(ostream & os, samochod &samochod1); //wypisuje podstawowe informacje
};



#endif /* SAMOCHOD_H */

