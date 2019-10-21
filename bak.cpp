/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bak.cpp
 * Author: Bogusław Malewski
 * 
 * Created on 21 października 2019, 17:08
 */

#include "bak.h"
#include <string>
#include <iostream>

using namespace std;
//bak::bak() {
//}
//
//bak::bak(const bak& orig) {
//}
//
//bak::~bak() {
//}

int bak::zatankuj(double litry) {
    if (stan_bak == pelny) {
        cout << "Nie można dolać plaiwa" << endl << "Bak jest pełny" << endl;
        return 0;
    }
    if (litry + stan_bak <= pelny) {
        stan_bak += litry;
        cout << "Dolano " << litry << "L paliwa do baku" << endl;
    } else {
        stan_bak = pelny;
        cout << "Dolano " << pelny - stan_bak << "L paliwa do baku" << endl;
        cout << "Bak jest teraz pełny" << endl;
    }
    return 0;
}

double bak::spal(double litry) {
    double temp_d = stan_bak;
    if (stan_bak - litry >= 0) {
        stan_bak = stan_bak - litry;
        cout << "Spalono " << litry << "L paliwa z baku" << endl;
        return litry;
    } else {
        stan_bak = 0;
        cout << "Spalono " << temp_d << "L paliwa z baku" << endl;
        cout << "Bak jest teraz pusty" << endl;
        return temp_d;
    }

    return 0;
}

double bak::info_bak() {
    cout << "W baku jest " << stan_bak << "L paliwa" << endl;
    return stan_bak;
}