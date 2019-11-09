

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
    bool czy_zaladowany();//zwraca true jeśli bagażnik jest załadowany
    int set_otwarty(int &stan);
    int set_zaladowany(int &stan);
    friend ostream & operator<<(ostream & os, bagaznik &bag1); //wypisuje stan bagażnika
};

#endif /* BAGAZNIK_H */

