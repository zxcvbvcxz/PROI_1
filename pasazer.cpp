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
    if(obecny == true){
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


//pasazer::pasazer() {
//}
//
//pasazer::pasazer(const pasazer& orig) {
//}
//
//pasazer::~pasazer() {
//}

