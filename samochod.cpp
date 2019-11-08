#include <iostream>
#include <string>
#include"samochod.h"
#include"Funkcje_pomocnicze.h"
#include "pasazer.h"
#include "bak.h"
#include "silnik.h"

using namespace std;

samochod::samochod(int miejsca) {
    if (miejsca < 0) {
        miejsca = 0;
    }
    if (miejsca > 7) {
        miejsca = 7;
    }
    if (miejsca > 0) {
        miejsca_dla_pasazerow = miejsca;
        pasazerowie = new pasazer[miejsca];
    } else {
        pasazerowie = nullptr;
    }

}

samochod::~samochod() {
    if (pasazerowie != nullptr) {
        delete[] pasazerowie;
    }
}

samochod::samochod(const samochod & sam1) {

    miejsca_dla_pasazerow = sam1.miejsca_dla_pasazerow;

    if (sam1.pasazerowie == nullptr) {
        pasazerowie = nullptr;
    } else {
        pasazerowie = new pasazer[sam1.miejsca_dla_pasazerow];
        for (int i = 0; i < sam1.miejsca_dla_pasazerow; i++) {
            pasazerowie[i] = sam1.pasazerowie[i];
        }
    }
    bagaznik_1 = sam1.bagaznik_1;
}

samochod& samochod::operator=(const samochod & sam1) {

    miejsca_dla_pasazerow = sam1.miejsca_dla_pasazerow;
    if (sam1.pasazerowie == nullptr) {
        pasazerowie = nullptr;
    } else {
        pasazerowie = new pasazer[sam1.miejsca_dla_pasazerow];
        for (int i = 0; i < sam1.miejsca_dla_pasazerow; i++) {
            pasazerowie[i] = sam1.pasazerowie[i];
        }
    }
    bagaznik_1 = sam1.bagaznik_1;
}

int samochod::in_info() {

    pojazd_silnikowy::in_info();
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
    cout << "++++++++++++++++++++++++++++++++++++++" << endl;
    pojazd_silnikowy::out_info();
    if (miejsca_dla_pasazerow == 0) {
        cout << "Pole miejsca dla pasazerow jest puste" << endl;
    } else
        cout << "Miejsca dla pasazerow:" << miejsca_dla_pasazerow << endl;
    cout << "++++++++++++++++++++++++++++++++++++++" << endl;
    return 0;
};

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
    if (miejsca_dla_pasazerow <= miejsce or miejsce < 0) {
        cout << "Wybrano nieprawidłowe miejsce" << endl;
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

int samochod::usun_pasazer(int miejsce) {
    if (miejsca_dla_pasazerow == 0) {
        cout << "Najpierw wprowadź informacje o miejscach dla pasażerów" << endl;
        return 0;
    }
    if (miejsca_dla_pasazerow <= miejsce or miejsce < 0) {
        cout << "Wybrano nieprawidłowe miejsce" << endl;
        return 0;
    }
    pasazerowie[miejsce].usun_pasazer();
}

int samochod::usun_all_pasazer() {
    if (miejsca_dla_pasazerow == 0) {
        cout << "Najpierw wprowadź informacje o miejscach dla pasażerów" << endl;
        return 0;
    }
    for (int i = 0; i < miejsca_dla_pasazerow; i++) {
        pasazerowie[i].usun_pasazer();
    }

}

int samochod::przejedz(double kilometry) {

    if (bagaznik_1.czy_otwarty()) {
        cout << "Nie można wyruszyć bo:" << endl;
        cout << "Bagażnik jest otwarty" << endl;
        return 0;
    } else
        pojazd_silnikowy::przejedz(kilometry);
    return 0;
}

int samochod::open_bagaznik() {
    bagaznik_1.otworz();
}

int samochod::close_bagaznik() {
    bagaznik_1.zamknij();
}

int samochod::zaladuj_bagaznik() {
    bagaznik_1.zaladuj();
}

int samochod::rozladuj_bagaznik() {
    bagaznik_1.rozladuj();
}

ostream & operator<<(ostream & os, samochod &samochod1) {
    samochod1.out_info();
    return os;
}

istream & operator>>(istream & is, samochod &samochod1) {
    samochod1.in_info();
    return is;
}