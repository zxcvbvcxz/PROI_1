

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

int pasazer::in_pasazer(string imie_, string nazwisko_, int wiek_) {
    obecny = true;
    imie = imie_;
    nazwisko = nazwisko_;
    wiek = wiek_;
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

int pasazer::out_pasazer_czolg() {
    if (obecny == false) {
        cout << "Nie ma członka załogi na danym miejscu" << endl;
        return 0;
    }
    cout << "--------------------------------------" << endl;

    if (imie.empty()) {
        cout << "Pole imię jest puste" << endl;
    } else
        cout << "Imię członka załogi:" << imie << endl;

    if (nazwisko.empty()) {
        cout << "Pole nazwisko jest puste" << endl;
    } else
        cout << "Nazwisko członka załogi:" << nazwisko << endl;

    if (wiek == 0) {
        cout << "Pole wiek jest puste" << endl;
    } else
        cout << "Wiek członka załogi:" << wiek << endl;

    cout << "--------------------------------------" << endl;
    return 0;
}

int pasazer::out_pasazer_radiowoz() {
    if (obecny == false) {
        cout << "Nie ma zatrzymanego na danym miejscu" << endl;
        return 0;
    }
    cout << "--------------------------------------" << endl;

    if (imie.empty()) {
        cout << "Pole imię jest puste" << endl;
    } else
        cout << "Imię zatrzymanego:" << imie << endl;

    if (nazwisko.empty()) {
        cout << "Pole nazwisko jest puste" << endl;
    } else
        cout << "Nazwisko zatrzymanego:" << nazwisko << endl;

    if (wiek == 0) {
        cout << "Pole wiek jest puste" << endl;
    } else
        cout << "Wiek zatrzymanego:" << wiek << endl;

    cout << "--------------------------------------" << endl;
    return 0;
}

int pasazer::usun_pasazer() {
    obecny = false;
    imie.clear();
    nazwisko.clear();
    wiek = 0;
}

bool pasazer::robecny() {
    return obecny;
}

string pasazer::rimie() {
    return imie;
}

string pasazer::rnazwisko() {
    return nazwisko;
}

int pasazer::rwiek() {
    return wiek;
}

int pasazer::wobecny(int &ob) {
    obecny = ob;
}

int pasazer::wimie(string &im) {
    imie = im;
}

int pasazer::wnazwisko(string &na) {
    nazwisko = na;
}

int pasazer::wwiek(int &wi) {
    wiek = wi;
}

bool pasazer::czy_obecny() {
    return obecny;
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

