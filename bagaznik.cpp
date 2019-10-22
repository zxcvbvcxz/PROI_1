
#include "bagaznik.h"
#include <string>
#include <iostream>

using namespace std;



int bagaznik::otworz() {
    if (otwarty) {
        cout << "Bagażnik jest już otwarty" << endl;
        return 0;
    }
    otwarty = true;
    cout << "Bagażnik został otworzony" << endl;
    return 0;
}

int bagaznik::zamknij() {
    if (otwarty) {
        otwarty = false;
        cout << "Bagażnik został zamknięty" << endl;
        return 0;
    }
    cout << "Bagażnik jest już zamknięty" << endl;
    return 0;

}

int bagaznik::zaladuj() {
    if (zaladowany) {
        cout << "Bagażnik jest już zaladowany" << endl;
        return 0;
    }
    if (otwarty) {
        zaladowany = true;
        cout << "Bagażnik został załadaowany" << endl;
    } else {
        cout << "Najpierw otwórz bagażnik" << endl;
    }
    return 0;
}

int bagaznik::rozladuj() {
    if (otwarty) {
        if (zaladowany) {
            zaladowany = false;
            cout << "Bagażnik został rozładowany" << endl;
            return 0;
        }
        if (zaladowany == false) {
            cout << "Bagażnik jest już rozładowany" << endl;
        }
    } else {
        cout << "Najpierw otwórz bagażnik" << endl;
    }
    return 0;
}

bool bagaznik::czy_otwarty() {
    return otwarty;
}

ostream & operator<<(ostream & os, bagaznik &bag1) {
    if (bag1.czy_otwarty()) {
        cout << "Bagażnik jest otwarty" << endl;
    } else {
        cout << "Bagażnik jest zamknięty" << endl;
    }
    return os;
}