
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
    int in_info();
    int out_info();  
};



#endif /* SAMOCHOD_H */

