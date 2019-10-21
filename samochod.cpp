#include <iostream>
#include <string>
#include"samochod.h"
#include"Funkcje_pomocnicze.h"
#include "pasazer.h"

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
    if (pasazerowie != nullptr) {
        delete[] pasazerowie;
    }
    while (true) {
        cout << "Podaj liczbę miejsc dla pasażerów:" << endl;
        double temp_double;
        if (wczytaj_double(temp_double)) {
            if (temp_double >= 1 and temp_double <= 7 and (temp_double - int(temp_double)) == 0) {
                miejsca_dla_pasazerow = (int) temp_double;
                break;
            } else {
                cout << "Liczba musi być całkowita z zakresu 1-7" << endl;
            }
        }
    }
    pasazerowie = new pasazer[miejsca_dla_pasazerow];
    return 0;
}

int samochod::out_info() {
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

    if (miejsca_dla_pasazerow == 0) {
        cout << "Pole miejsca dla pasazerow jest puste" << endl;
    } else
        cout << "Miejsca dla pasazerow:" << miejsca_dla_pasazerow << endl;

    cout << "--------------------------------------" << endl;
    return 0;
};

int samochod::in_kierowca() {
    if (kierowca_1 == nullptr) {
        kierowca_1 = new kierowca;
    }
    kierowca_1->in_kierowca();
    return 0;
}

int samochod::out_kierowca() {
    if (kierowca_1 == nullptr) {
        cout << "Nie ma kierowcy" << endl;
        return 0;
    }
    kierowca_1->out_kierowca();
    return 0;
}

int samochod::usun_kierowca() {
    if (kierowca_1 == nullptr) {
        cout << "Nie ma kierowcy" << endl;
        return 0;
    }
    delete kierowca_1;
    kierowca_1 = nullptr;
    cout << "Kierowca usunięty" << endl;
    return 0;

}

int samochod::in_pasazer(int miejsce) {
    if (miejsca_dla_pasazerow == 0) {
        cout << "Najpierw wprowadź informacje o miejscach dla pasażerów" << endl;
        return 0;
    }
    if (miejsca_dla_pasazerow <= miejsce or miejsce < 0) {
        cout << "Wybrano nieprawidłowe miejsce" << endl;
        return 0;
    }
    pasazerowie[miejsce].in_pasazer();
}

int samochod::out_pasazer(int miejsce) {
    if (miejsca_dla_pasazerow == 0) {
        cout << "Najpierw wprowadź informacje o miejscach dla pasażerów" << endl;
        return 0;
    }
    pasazerowie[miejsce].out_pasazer();
}

int samochod::out_all_pasazer() {
    if (miejsca_dla_pasazerow == 0) {
        cout << "Najpierw wprowadź informacje o miejscach dla pasażerów" << endl;
        return 0;
    }
    for (int i = 0; i < miejsca_dla_pasazerow; i++) {
        cout << "VVVVV MIEJSCE NR " << i << "VVVVV" << endl;
        pasazerowie[i].out_pasazer();

    }
}
