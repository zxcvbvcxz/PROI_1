/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pasazer.h
 * Author: Bogusław Malewski
 *
 * Created on 21 października 2019, 15:09
 */

#ifndef PASAZER_H
#define PASAZER_H

#include <string>
#include <iostream>

using namespace std;

class pasazer
{
private:
    bool obecny = false;
    string imie;
    string nazwisko;
    int wiek = 0;

public:

    int in_pasazer();
    int out_pasazer();
    bool operator++();
    bool operator--();
    bool operator<=(pasazer pas1);
    bool operator<(pasazer pas1);
    bool operator>=(pasazer pas1);
    bool operator>(pasazer pas1);
    bool operator==(pasazer pas1);
    friend ostream & operator<<(ostream & os, const pasazer &pas1);    
    friend istream & operator>>(istream & is, pasazer &pas1);

};

#endif /* PASAZER_H */

