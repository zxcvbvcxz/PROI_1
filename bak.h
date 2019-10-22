/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bak.h
 * Author: Bogusław Malewski
 *
 * Created on 21 października 2019, 17:08
 */

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
    //    bak();
    //    bak(const bak& orig);
    //    virtual ~bak();
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
    friend ostream & operator<<(ostream & os,const bak &bak1);
    friend istream & operator>>(istream & is, bak &bak1);

};

#endif /* BAK_H */

