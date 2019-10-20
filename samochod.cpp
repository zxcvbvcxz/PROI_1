#include <iostream>
#include <string>
#include"samochod.h"
#include"Funkcje_pomocnicze.h"

using namespace std;

int samochod::in_info() {

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
    return 0;
}

int samochod::out_info() {
    cout << "--------------------------------------" << endl;

    if (marka.empty()) {
        cout << "Pole marka jest puste" << endl;
    } else
        cout << "Marka:" << marka << endl;

    if (marka.empty()) {
        cout << "Pole model jest puste" << endl;
    } else
        cout << "Model:" << model << endl;

    if (marka.empty()) {
        cout << "Pole rocznik jest puste" << endl;
    } else
        cout << "Rocznik:" << rocznik << endl;
    
    cout << "--------------------------------------" << endl;

    return 0;
};
