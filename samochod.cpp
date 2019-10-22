#include <iostream>
#include <string>
#include"samochod.h"
#include"Funkcje_pomocnicze.h"
#include "pasazer.h"
#include "bak.h"
#include "silnik.h"

using namespace std;

samochod::samochod() {
    rocznik = 0;
    miejsca_dla_pasazerow = 0;
    spalanie_na_100km = 9;
    kierowca_1 = nullptr;
    pasazerowie = nullptr;
}

samochod::~samochod() {
    if (kierowca_1 != nullptr) {
        delete kierowca_1;
    }
    if (pasazerowie != nullptr) {
        delete[] pasazerowie;
    }
}

samochod::samochod(const samochod & sam1) {
    marka = sam1.marka;
    model = sam1.model;
    rocznik = sam1.rocznik;
    miejsca_dla_pasazerow = sam1.miejsca_dla_pasazerow;
    spalanie_na_100km = sam1.spalanie_na_100km;
    if (sam1.kierowca_1 == nullptr) {
        kierowca_1 = nullptr;
    } else {
        kierowca_1 = new kierowca;
        *kierowca_1 = *sam1.kierowca_1;
    }
    if (sam1.pasazerowie == nullptr) {
        pasazerowie = nullptr;
    } else {
        pasazerowie = new pasazer[sam1.miejsca_dla_pasazerow];
        for (int i = 0; i < sam1.miejsca_dla_pasazerow; i++) {
            pasazerowie[i] = sam1.pasazerowie[i];
        }
    }
    bagaznik_1 = sam1.bagaznik_1;
    bak_1 = sam1.bak_1;
    silnik_1 = sam1.silnik_1;
}

samochod& samochod::operator=(const samochod & sam1) {
    marka = sam1.marka;
    model = sam1.model;
    rocznik = sam1.rocznik;
    miejsca_dla_pasazerow = sam1.miejsca_dla_pasazerow;
    spalanie_na_100km = sam1.spalanie_na_100km;
    if (sam1.kierowca_1 == nullptr) {
        kierowca_1 = nullptr;
    } else {
        kierowca_1 = new kierowca;
        *kierowca_1 = *sam1.kierowca_1;
    }
    if (sam1.pasazerowie == nullptr) {
        pasazerowie = nullptr;
    } else {
        pasazerowie = new pasazer[sam1.miejsca_dla_pasazerow];
        for (int i = 0; i < sam1.miejsca_dla_pasazerow; i++) {
            pasazerowie[i] = sam1.pasazerowie[i];
        }
    }
    bagaznik_1 = sam1.bagaznik_1;
    bak_1 = sam1.bak_1;
    silnik_1 = sam1.silnik_1;
}

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

    cout << "Spalanie na 100 km:" << spalanie_na_100km << "L" << endl;

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

bool samochod::out_prawo_jazdy() {
    if (kierowca_1 == nullptr) {
        cout << "Nie ma kierowcy w samochodzie" << endl;
        return false;
    }
    return kierowca_1->czy_prawo_jazdy();
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

int samochod::in_bak() {
    double litry;
    while (true) {
        cout << "Podaj ile litrów paliwa chesz zatankować" << endl;
        if (wczytaj_double(litry)) {
            break;
        }
    }
    bak_1.zatankuj(litry);
}

int samochod::out_bak() {
    return bak_1.info_bak();
}

int samochod::on_silnik() {
    if (bak_1.info_bak() > 0) {
        silnik_1.wlacz();
    } else {
        cout << "Bak jest pusty" << endl << "Musisz dolać paliwa" << endl;
    }
    return 0;
}

int samochod::off_silnik() {
    silnik_1.wylacz();
    return 0;
}

int samochod::przejedz(double kilometry) {
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
    if (bagaznik_1.czy_otwarty()) {
        cout << "Nie można wyruszyć bo:" << endl;
        cout << "Bagażnik jest otwarty" << endl;
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

bool samochod::operator++() {
    this->silnik_1.operator++();
}

bool samochod::operator--() {
    this->silnik_1.operator--();
}

ostream & operator<<(ostream & os, samochod &samochod1) {
    samochod1.out_info();
    return os;
}