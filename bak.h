

#ifndef BAK_H
#define BAK_H

#include <iostream>

using namespace std;

class bak
{
private:

    enum skrajne_wartosci
    {
        pusty = 0, pelny = 50
    };
    double stan_bak = 25;


public:

    int zatankuj(double litry);
    double spal(double litry);
    double info_bak();
    bool operator++();
    bool operator--();
    bool operator<=(bak bak1);
    bool operator<(bak bak1);
    bool operator>=(bak bak1);
    bool operator>(bak bak1);
    bool operator==(bak bak1);
    const bak & operator+(bak bak1);
    const bak & operator+(double litry);
    const bak & operator-(bak bak1);
    const bak & operator-(double litry);
    friend ostream & operator<<(ostream & os, bak &bak1);
    friend istream & operator>>(istream & is, bak &bak1);

};

#endif /* BAK_H */

