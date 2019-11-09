

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

    int zatankuj(double litry);//wlewa do baku paliwo
    double spal(double litry);//spala paliwo z baku
    double info_bak();//wypisuje ile jest litrów paliwa w baku
    double info_bak_v();//zwraca ile jest litrów paliwa w baku
    int set(double litry);
    bool operator++();//dodaje litr paliwa do baku
    bool operator--();//usuwa litr paliwa z baku
    bool operator<=(bak bak1);//porównuje ilość paliwa w bakach
    bool operator<(bak bak1);//porównuje ilość paliwa w bakach
    bool operator>=(bak bak1);//porównuje ilość paliwa w bakach
    bool operator>(bak bak1);//porównuje ilość paliwa w bakach
    bool operator==(bak bak1);//porównuje ilość paliwa w bakach
    const bak & operator+(bak bak1);//dodaje ilość paliwa z baku drugiego do pierwszego UWAGA modyfikuje tylko lewy operand
    const bak & operator+(double litry);//dodaje podaną ilość paliwa do pierwszego baku UWAGA modyfikuje tylko lewy operand
    const bak & operator-(bak bak1);//odejmuje ilość paliwa z baku drugiego do pierwszego UWAGA modyfikuje tylko lewy operand
    const bak & operator-(double litry);//odejmuje ilość paliwa z baku drugiego do pierwszego UWAGA modyfikuje tylko lewy operand
    friend ostream & operator<<(ostream & os, bak &bak1);//wlewa do baku paliwo
    friend istream & operator>>(istream & is, bak &bak1);//spala paliwo z baku

};

#endif /* BAK_H */

