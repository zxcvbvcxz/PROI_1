
#ifndef SAMOCHOD_H
#define SAMOCHOD_H
#include <string>
#include <iostream>
#include"kierowca.h"
#include "pasazer.h"

using namespace std;

class samochod
{
private:
    string marka;
    string model;
    int rocznik = 0;
    int miejsca_dla_pasazerow = 0;
    kierowca * kierowca_1 = nullptr;
    pasazer * pasazerowie = nullptr;




public:
    int in_info();
    int out_info();

    int in_kierowca();
    int out_kierowca();
    int usun_kierowca();
    
    int in_pasazer(int miejsce);
    int out_pasazer(int miejsce);
    int out_all_pasazer();
};



#endif /* SAMOCHOD_H */

