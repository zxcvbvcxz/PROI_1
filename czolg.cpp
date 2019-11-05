/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   czołg.cpp
 * Author: Bogusław Malewski
 * 
 * Created on 3 listopada 2019, 17:36
 */

#include "czolg.h"

czolg::czolg() {
}

czolg::czolg(const czolg& orig) {
}

czolg::~czolg() {
}

int czolg::dodaj_amunicje(int ilosc) {
    amunicja += ilosc;

}

int czolg::laduj() {
    if (zaladowany) {
        cout << "działo jest juz załadowane" << endl;
    } else if (amunicja > 0) {
        amunicja--;
        zaladowany = true;
        cout << "działo zostało załadowane" << endl;
    }else {
        cout << "nie można załadować działa, nie ma amunicji" << endl;
    }
}

int czolg::strzelaj() {
    if (zaladowany){
        zaladowany= false;
        cout <<"Działo wystrzeliło" << endl;
    }
    }
