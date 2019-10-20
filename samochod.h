
#ifndef SAMOCHOD_H
#define SAMOCHOD_H
#include <string>
#include <iostream>

using namespace std;

class samochod{
private:
    string marka;
    string model;
    int rocznik;
    
    int wmarka();//wpisywanie danych
    int wmodel();
    int wrocznik();    
    int rmarka();//wypisywanie danych
    int rmodel();
    int rrocznik();
    
public:    
    int rinfo();
    int winfo();
    
    
};



#endif /* SAMOCHOD_H */

