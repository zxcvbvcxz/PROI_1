

#ifndef SILNIK_H
#define SILNIK_H

#include <iostream>
#include <string>

using namespace std;

class silnik
{
private:
    bool wlaczony = false;
public:
    int wlacz();//włącza silnik
    int wylacz();//wyłącza silnik
    bool operator++();//włącza silnik
    bool operator--();//wyłącza silnik
    friend ostream & operator<<(ostream & os,const silnik &silnik1);//wypisuje stan silnika
};

#endif /* SILNIK_H */

