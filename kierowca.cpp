/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   kierowca.cpp
 * Author: Bogusław Malewski
 * 
 * Created on 21 października 2019, 12:58
 */

#include "kierowca.h"
#include"Funkcje_pomocnicze.h"

//kierowca::kierowca() {
//}
//
//kierowca::kierowca(const kierowca& orig) {
//}
//
//kierowca::~kierowca() {
//}

kierowca::in_kierowca() {
    cout << "Podaj imię kierowcy" << endl;
    getline(cin, imie);

    cout << "Podaj nazwisko kierowcy" << endl;
    getline(cin, nazwisko);


    double temp_double;
    while (true) {
        cout << "Podaj wiek kierowcy" << endl;
        if (wczytaj_double(temp_double)) {
            wiek = (int) temp_double;
            break;
        }
    }


    cout << "Czy kierowca ma prawo jazdy?" << endl;
    cout << " Wpisz 1 jeśli tak, wpisz 0 jeśli nie." << endl;
    wczytaj_double(temp_double);
    prawo_jazdy = temp_double;
}

kierowca::out_kierowca() {
    cout << "--------------------------------------" << endl;

    if (imie.empty()) {
        cout << "Pole imię jest puste" << endl;
    } else
        cout << "Imię kierowcy:" << imie << endl;

    if (nazwisko.empty()) {
        cout << "Pole nazwisko jest puste" << endl;
    } else
        cout << "Nazwisko kierowcy:" << nazwisko << endl;

    if (wiek == 0) {
        cout << "Pole wiek jest puste" << endl;
    } else
        cout << "Wiek kierowcy:" << wiek << endl;

    cout << "Prawo jazdy:";
    if (prawo_jazdy == true) {
        cout << "Tak" << endl;
    } else {
        cout << "Nie" << endl;
    }
    cout << "--------------------------------------" << endl;
}

