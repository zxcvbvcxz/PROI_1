/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   silnik.cpp
 * Author: Bogusław Malewski
 * 
 * Created on 21 października 2019, 17:35
 */

#include "silnik.h"
#include <string>
#include <iostream>

using namespace std;
//silnik::silnik() {
//}
//
//silnik::silnik(const silnik& orig) {
//}
//
//silnik::~silnik() {
//}

int silnik::wlacz() {
    if (wlaczony) {
        cout << "Silnik jest już włączony" << endl;
    } else {
        wlaczony = true;
        cout << "Silnik został włączony" << endl;
    }
    return 0;
}

int silnik::wylacz() {
    if (wlaczony) {
        wlaczony = false;
        cout << "Silnik został wyłączony" << endl;
    } else {
        cout << "Silnik jest już wyłączony" << endl;
    }
    return 0;
}

bool silnik::operator++() {
    wlacz();
}

bool silnik::operator--() {
    wylacz();
}

ostream & operator<<(ostream & os, const silnik &silnik1) {
    if (silnik1.wlaczony) {
        cout << "Silnik jest włączony" << endl;
    } else {
        cout << "Silnik jest wyłączony" << endl;
    }
}