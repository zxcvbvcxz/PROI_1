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

int czolg::in_info() {
    return 0;
}

int czolg::out_info() {
    return 0;
}

int czolg::dodaj_amunicje(int ilosc) {
    amunicja += ilosc;
    cout << "Dodano " << ilosc << " amunicji" << endl;
    return 0;

}

int czolg::laduj() {
    if (zaladowany) {
        cout << "Działo jest juz załadowane" << endl;
    } else if (amunicja > 0) {
        int temp = 0;
        for (int i = 0; i < 4; i++) {
            if (zaloga[i].czy_obecny()) {
                temp++;
            }
        }
        if (temp < min_zaloga) {
            cout << "Nie ma wystarczająco dużo członków załogi by załadować" << endl;
            return 0;
        }
        amunicja--;
        zaladowany = true;
        cout << "Działo zostało załadowane" << endl;
    } else {
        cout << "Nie można załadować działa, nie ma amunicji" << endl;
    }
    return 0;
}

int czolg::strzelaj() {
    if (zaladowany) {
        int temp = 0;
        for (int i = 0; i < 4; i++) {
            if (zaloga[i].czy_obecny()) {
                temp++;
            }
        }
        if (temp < min_zaloga) {
            cout << "Nie ma wystarczająco dużo członków załogi by wystrzelić" << endl;
            return 0;
        }
        zaladowany = false;
        cout << "Działo wystrzeliło" << endl;
    } else {

        cout << "Działo nie jest załadowane" << endl;
    }
}

int czolg::dodaj_zaloge(int miejsce) {
    if (miejsce == 0 or miejsce == 1 or miejsce == 2 or miejsce == 3 or miejsce == 4) {
        zaloga[miejsce].in_pasazer();
    } else {
        cout << "Wybrano nieprawidłowe miejsce" << endl;
    }
    return 0;
}

int czolg::zwolnij_zaloge(int miejsce) {
    if (miejsce == 0 or miejsce == 1 or miejsce == 2 or miejsce == 3 or miejsce == 4) {
        zaloga[miejsce].usun_pasazer();
    } else {
        cout << "Wybrano nieprawidłowe miejsce" << endl;
    }
    return 0;
}

int czolg::out_zaloga(int miejsce) {
    if (miejsce == 0 or miejsce == 1 or miejsce == 2 or miejsce == 3 or miejsce == 4) {
        zaloga[miejsce].out_pasazer();
    } else {
        cout << "Wybrano nieprawidłowe miejsce" << endl;
    }
    return 0;
}

int czolg::out_all_zaloga() {
    out_kierowca();
    for (int i = 0; i < 4; i++) {
        cout << "VVVVV MIEJSCE NR " << i << "VVVVV" << endl;
        zaloga[i].out_pasazer();
    }
}
