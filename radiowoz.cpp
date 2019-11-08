/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   radiowoz.cpp
 * Author: Bogusław Malewski
 * 
 * Created on 3 listopada 2019, 17:13
 */

#include "radiowoz.h"
#include "pasazer.h"
#include <iostream>

using namespace std;

radiowoz::radiowoz() : samochod(1)  {
    syg_swietlna = false;
    syg_dzwiekowa = false;
}

radiowoz::radiowoz(const radiowoz& orig){
    syg_swietlna = orig.syg_swietlna;
    syg_dzwiekowa = orig.syg_dzwiekowa;
    zatrzymani[0] = orig.zatrzymani[0];
    zatrzymani[1] = orig.zatrzymani[1];
    zatrzymani[2] = orig.zatrzymani[2];
}

radiowoz::~radiowoz() {
}

int radiowoz::on_dzwiek() {
    if (syg_dzwiekowa == false) {
        syg_dzwiekowa = true;
        cout << "syganlizacja dźwiękowa została włączona" << endl;
    } else {
        cout << "syganlizacja dźwiękowa jest już włączona" << endl;
    }
    return 0;
}

int radiowoz::off_dzwiek() {
    if (syg_dzwiekowa == false) {
        cout << "syganlizacja dźwiękowa jest już wyłączona" << endl;
    } else {
        syg_dzwiekowa = false;
        cout << "syganlizacja dźwiękowa została wyłączona" << endl;
    }
    return 0;
}

int radiowoz::on_swiatlo() {
    if (syg_swietlna == false) {
        syg_swietlna = true;
        cout << "syganlizacja świetlna została włączona" << endl;
    } else {
        cout << "syganlizacja świetlna jest już włączona" << endl;
    }
    return 0;
}

int radiowoz::off_swiatlo() {
    if (syg_swietlna == false) {
        cout << "syganlizacja świetlna jest już wyłączona" << endl;
    } else {
        syg_swietlna = false;
        cout << "syganlizacja świetlna została wyłączona" << endl;
    }
    return 0;
}

int radiowoz::zatrzymaj(int miejsce) {
    if (miejsce == 0 or miejsce == 1 or miejsce == 2) {
        zatrzymani[miejsce].in_pasazer();
    } else {
        cout << "Podano niewłaściwy numer miejsca dla zatrzymanego" << endl;
    }
    return 0;
}

int radiowoz::zwolnij(int miejsce) {
    if (miejsce == 0 or miejsce == 1 or miejsce == 2) {
        zatrzymani[miejsce].usun_pasazer();
    } else {
        cout << "Podano niewłaściwy numer miejsca dla zatrzymanego" << endl;
    }
    return 0;
}

int radiowoz::out_zatrzymani(int miejsce) {
    if (miejsce == 0 or miejsce == 1 or miejsce == 2) {
        zatrzymani[miejsce].out_pasazer();
    } else {
        cout << "Podano niewłaściwy numer miejsca dla zatrzymanego" << endl;
    }
    return 0;
}

int radiowoz::out_all_zatrzymani() {
    for (int i = 0; i < 3; i++) {
        zatrzymani[i].out_pasazer();
    }
    return 0;
}
