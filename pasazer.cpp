/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pasazer.cpp
 * Author: Bogusław Malewski
 * 
 * Created on 21 października 2019, 15:09
 */

#include "pasazer.h"
#include <string>
#include <iostream>
#include"Funkcje_pomocnicze.h"

using namespace std;

int pasazer::in_pasazer() {
    if (obecny == true) {
        cout << "Miejsce jest już zajęte" << endl;
        return 0;
    }

    cout << "Podaj imię pasażera" << endl;
    getline(cin, imie);

    cout << "Podaj nazwisko pasażera" << endl;
    getline(cin, nazwisko);


    double temp_double;
    while (true) {
        cout << "Podaj wiek pasażera" << endl;
        if (wczytaj_double(temp_double)) {
            wiek = (int) temp_double;
            break;
        }
    }
    obecny = true;


}

int pasazer::out_pasazer() {
    if (obecny == false) {
        cout << "Nie ma pasażera na danym miejscu" << endl;
        return 0;
    }
    cout << "--------------------------------------" << endl;

    if (imie.empty()) {
        cout << "Pole imię jest puste" << endl;
    } else
        cout << "Imię pasażera:" << imie << endl;

    if (nazwisko.empty()) {
        cout << "Pole nazwisko jest puste" << endl;
    } else
        cout << "Nazwisko pasażera:" << nazwisko << endl;

    if (wiek == 0) {
        cout << "Pole wiek jest puste" << endl;
    } else
        cout << "Wiek pasażera:" << wiek << endl;

    cout << "--------------------------------------" << endl;
    return 0;
}

bool pasazer::operator++() {
    this->wiek++;
}

bool pasazer::operator--() {
    this->wiek--;
}

bool pasazer::operator<=(pasazer pas1) {
    return (this->wiek <= pas1.wiek);
}

bool pasazer::operator<(pasazer pas1) {
    return (this->wiek < pas1.wiek);
}

bool pasazer::operator>=(pasazer pas1) {
    return (this->wiek >= pas1.wiek);
}

bool pasazer::operator>(pasazer pas1) {
    return (this->wiek > pas1.wiek);
}

bool pasazer::operator==(pasazer pas1) {
    return (this->wiek == pas1.wiek);
}

ostream & operator<<(ostream & os, const pasazer &pas1) {
    if (pas1.obecny == false) {
        cout << "Nie ma pasażera na danym miejscu" << endl;
        return os;
    }
    cout << "--------------------------------------" << endl;

    if (pas1.imie.empty()) {
        cout << "Pole imię jest puste" << endl;
    } else
        cout << "Imię pasażera:" << pas1.imie << endl;

    if (pas1.nazwisko.empty()) {
        cout << "Pole nazwisko jest puste" << endl;
    } else
        cout << "Nazwisko pasażera:" << pas1.nazwisko << endl;

    if (pas1.wiek == 0) {
        cout << "Pole wiek jest puste" << endl;
    } else
        cout << "Wiek pasażera:" << pas1.wiek << endl;

    cout << "--------------------------------------" << endl;
    return os;
}

istream & operator>>(istream & is, pasazer &pas1) {
if (pas1.obecny == true) {
        cout << "Miejsce jest już zajęte" << endl;
        return is;
    }

    cout << "Podaj imię pasażera" << endl;
    getline(cin, pas1.imie);

    cout << "Podaj nazwisko pasażera" << endl;
    getline(cin, pas1.nazwisko);


    double temp_double;
    while (true) {
        cout << "Podaj wiek pasażera" << endl;
        if (wczytaj_double(temp_double)) {
            pas1.wiek = (int) temp_double;
            break;
        }
    }
    pas1.obecny = true;
    return is;

}

//pasazer::pasazer() {
//}
//
//pasazer::pasazer(const pasazer& orig) {
//}
//
//pasazer::~pasazer() {
//}

