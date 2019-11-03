/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pojazd_silnikowy.cpp
 * Author: Bogusław Malewski
 * 
 * Created on 3 listopada 2019, 15:53
 */


#include <string>
#include <iostream>
#include "pojazd_silnikowy.h"
#include"kierowca.h"
#include"bak.h"
#include"silnik.h"
#include "Funkcje_pomocnicze.h"

using namespace std;


pojazd_silnikowy::pojazd_silnikowy() {
    rocznik = 0;
    spalanie_na_100km = 9;
    kierowca_1 = nullptr;
}

pojazd_silnikowy::~pojazd_silnikowy() {
    if (kierowca_1 != nullptr) {
        delete kierowca_1;
    }
}

pojazd_silnikowy::pojazd_silnikowy(const pojazd_silnikowy & sam1) {
    marka = sam1.marka;
    model = sam1.model;
    rocznik = sam1.rocznik;
    spalanie_na_100km = sam1.spalanie_na_100km;
    if (sam1.kierowca_1 == nullptr) {
        kierowca_1 = nullptr;
    } else {
        kierowca_1 = new kierowca;
        *kierowca_1 = *sam1.kierowca_1;
    }
    bak_1 = sam1.bak_1;
    silnik_1 = sam1.silnik_1;
}

pojazd_silnikowy& pojazd_silnikowy::operator=(const pojazd_silnikowy & sam1) {
    marka = sam1.marka;
    model = sam1.model;
    rocznik = sam1.rocznik;
    spalanie_na_100km = sam1.spalanie_na_100km;
    if (sam1.kierowca_1 == nullptr) {
        kierowca_1 = nullptr;
    } else {
        kierowca_1 = new kierowca;
        *kierowca_1 = *sam1.kierowca_1;
    }
    bak_1 = sam1.bak_1;
    silnik_1 = sam1.silnik_1;
}

int pojazd_silnikowy::in_info() {

    cout << "Podaj markę pojazdu:" << endl;
    getline(cin, marka);

    cout << "Podaj model pojazdu:" << endl;
    getline(cin, model);

    while (true) {
        cout << "Podaj rocznik pojazdu:" << endl;
        double temp_double;
        if (wczytaj_double(temp_double)) {
            if (temp_double >= 1885 and temp_double <= 2019 and (temp_double - int(temp_double)) == 0) {
                rocznik = (int) temp_double;
                break;
            } else {
                cout << "Rocznik musi być liczbą całkowitą z zakresu 1885-2019" << endl;
            }
        }
    }
    while (true) {
        cout << "Podaj spalanie (w litrach paliwa na  100km) pojazdu:" << endl;
        double temp_double;
        if (wczytaj_double(temp_double)) {
            spalanie_na_100km = temp_double;
            break;

        }
    }

    return 0;
}

int pojazd_silnikowy::out_info() {
    cout << "--------------------------------------" << endl;

    if (marka.empty()) {
        cout << "Pole marka jest puste" << endl;
    } else
        cout << "Marka:" << marka << endl;

    if (model.empty()) {
        cout << "Pole model jest puste" << endl;
    } else
        cout << "Model:" << model << endl;

    if (rocznik == 0) {
        cout << "Pole rocznik jest puste" << endl;
    } else
        cout << "Rocznik:" << rocznik << endl;

    cout << "Spalanie na 100 km:" << spalanie_na_100km << "L" << endl;

    cout << "--------------------------------------" << endl;
    return 0;
};

int pojazd_silnikowy::in_kierowca() {
    if (kierowca_1 == nullptr) {
        kierowca_1 = new kierowca;
    }
    kierowca_1->in_kierowca();
    return 0;
}

int pojazd_silnikowy::out_kierowca() {
    if (kierowca_1 == nullptr) {
        cout << "Nie ma kierowcy" << endl;
        return 0;
    }
    kierowca_1->out_kierowca();
    return 0;
}

int pojazd_silnikowy::usun_kierowca() {
    if (kierowca_1 == nullptr) {
        cout << "Nie ma kierowcy" << endl;
        return 0;
    }
    delete kierowca_1;
    kierowca_1 = nullptr;
    cout << "Kierowca usunięty" << endl;
    return 0;

}
bool pojazd_silnikowy::out_prawo_jazdy() {
    if (kierowca_1 == nullptr) {
        cout << "Nie ma kierowcy w samochodzie" << endl;
        return false;
    }
    return kierowca_1->czy_prawo_jazdy();
}

int pojazd_silnikowy::in_bak() {
    double litry;
    while (true) {
        cout << "Podaj ile litrów paliwa chesz zatankować" << endl;
        if (wczytaj_double(litry)) {
            break;
        }
    }
    bak_1.zatankuj(litry);
}

int pojazd_silnikowy::out_bak() {
    return bak_1.info_bak();
}

int pojazd_silnikowy::on_silnik() {
    if (bak_1.info_bak() > 0) {
        silnik_1.wlacz();
    } else {
        cout << "Bak jest pusty" << endl << "Musisz dolać paliwa" << endl;
    }
    return 0;
}

int pojazd_silnikowy::off_silnik() {
    silnik_1.wylacz();
    return 0;
}

int pojazd_silnikowy::przejedz(double kilometry) {
    if (kierowca_1 == nullptr) {
        cout << "Nie można wyruszyć bo:" << endl;
        cout << "Nie ma kierowcy w samochodzie" << endl;
        return 0;
    }
    if (bak_1.info_bak() == 0) {
        cout << "Nie można wyruszyć bo:" << endl;
        cout << "Nie ma paliwa w baku" << endl;
        return 0;
    }
    if (kierowca_1->czy_prawo_jazdy()) {
        double spalone_paliwo;
        spalone_paliwo = bak_1.spal(kilometry * (spalanie_na_100km / 100));
        cout << "Udało się przejechać " << (spalone_paliwo / spalanie_na_100km) * 100 << " km" << endl;
    } else {
        cout << "Nie można wyruszyć bo:" << endl;
        cout << "Kierowca nie ma prawa jazdy" << endl;
    }
    return 0;
}

bool pojazd_silnikowy::operator++() {
    this->silnik_1.operator++();
}

bool pojazd_silnikowy::operator--() {
    this->silnik_1.operator--();
}

ostream & operator<<(ostream & os, pojazd_silnikowy &pojazd_silnikowy1) {
    pojazd_silnikowy1.out_info();
    return os;
}