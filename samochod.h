
#ifndef SAMOCHOD_H
#define SAMOCHOD_H
#include <string>
#include <iostream>
#include"kierowca.h"

using namespace std;

class samochod
{
private:
    string marka;
    string model;
    int rocznik = 0;
    kierowca * kierowca_1 = nullptr;




public:
    int in_info();
    int out_info();
    
    int in_kierowca();
    int out_kierowca();
    int usun_kierowca();
};



#endif /* SAMOCHOD_H */

