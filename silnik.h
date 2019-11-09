

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
    bool rwlaczony();
    int wlacz();//włącza silnik
    int wylacz();//wyłącza silnik
    int set(int &stan);
    bool operator++();//włącza silnik
    bool operator--();//wyłącza silnik
    friend ostream & operator<<(ostream & os,const silnik &silnik1);//wypisuje stan silnika
};

#endif /* SILNIK_H */

