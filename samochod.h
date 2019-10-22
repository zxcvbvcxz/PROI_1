
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
    samochod();
    ~samochod();
    samochod(const samochod & sam1);
    samochod &operator=(const samochod & sam1);
    int in_info();
    int out_info();

    int in_kierowca();
    int out_kierowca();
    int usun_kierowca();
    bool out_prawo_jazdy();

    int in_pasazer(int miejsce);
    int out_pasazer(int miejsce);
    int out_all_pasazer();

    int open_bagaznik();
    int close_bagaznik();
    int zaladuj_bagaznik();
    int rozladuj_bagaznik();

    int in_bak();
    int out_bak();

    int on_silnik();
    int off_silnik();

    int przejedz(double kilometry);

    bool operator++();
    bool operator--();
    friend ostream & operator<<(ostream & os, samochod &samochod1);
};



#endif /* SAMOCHOD_H */

