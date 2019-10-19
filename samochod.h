
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
    
public:
    int wmarka();
    int wmodel();
    int wrocznik();
    int rmarka();
    int rmodel();
    int rrocznik();
    int rinfo();
    int winfo();
    
    
};



#endif /* SAMOCHOD_H */

