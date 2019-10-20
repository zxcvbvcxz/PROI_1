#include <iostream>
#include <string>
#include"samochod.h"
#include"Funkcje_pomocnicze.h"

using namespace std;

//wpisywanie podstawowych informacji

int samochod::wmarka() {
    cout << "Podaj markę pojazdu:" << endl;
    getline(cin, marka);
    return 0;
};

int samochod::wmodel() {
    cout << "Podaj model pojazdu:" << endl;
    getline(cin, model);
    return 0;
};

int samochod::wrocznik() {
    //wczytywanie liczby wzor: początek
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
    return 0;
};

//wypisywanie podstawowych informacji

int samochod::rmarka() {
    if (marka.empty()) {
        cout << "Pole marka jest puste" << endl;
        return 0;
    }
    cout << "Marka:" << marka << endl;

    return 0;
};

int samochod::rmodel() {
    if (marka.empty()) {
        cout << "Pole model jest puste" << endl;
        return 0;
    }
    cout << "Model:" << model << endl;

    return 0;
};

int samochod::rrocznik() {
    if (marka.empty()) {
        cout << "Pole rocznik jest puste" << endl;
        return 0;
    }
    cout << "Rocznik:" << rocznik << endl;
    cout.clear();

    return 0;
};

int samochod::rinfo() {
    rmarka();
    rmodel();
    rrocznik();

    return 0;
};

int samochod::winfo() {
    wmarka();
    wmodel();
    wrocznik();
    return 0;
};