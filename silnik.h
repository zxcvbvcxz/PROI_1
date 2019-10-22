/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   silnik.h
 * Author: Bogusław Malewski
 *
 * Created on 21 października 2019, 17:35
 */

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

