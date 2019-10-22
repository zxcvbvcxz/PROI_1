

#ifndef BAGAZNIK_H
#define BAGAZNIK_H

#include <iostream>

using namespace std;

class bagaznik
{
private:
    bool otwarty = false;
    bool zaladowany = false;
public:
    int otworz(); //otwiera bagażnik
    int zamknij(); //zamyka bagażnik
    int zaladuj(); //ładuje bagażnik
    int rozladuj(); //rozładowuje bagażnik
    bool czy_otwarty(); //zwraca true jeśli otwarty bagażnik
    friend ostream & operator<<(ostream & os, bagaznik &bag1); //wypisuje stan bagażnika
};

#endif /* BAGAZNIK_H */

