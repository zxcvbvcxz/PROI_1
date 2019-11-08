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
#include"Funkcje_pomocnicze.h"

czolg::czolg() {
}

czolg::czolg(const czolg& orig) {
}

czolg::~czolg() {
}

int czolg::in_info() {
    pojazd_silnikowy::in_info();
    while (1) {
        cout << "Podaj ile sztuk amunicji ma czołg" << endl;
        double temp_double;
        wczytaj_double(temp_double);
        if (temp_double < 0 or temp_double > 100) {
            cout << "Podano nieprawidłową liczbę" << endl;
            cout << "podaj liczbę z zakresu od 0 do 100" << endl;
            continue;
        }
        break;

        amunicja = (int) temp_double;
    }
    return 0;
}

int czolg::out_info() {
    cout << "++++++++++++++++++++++++++++++++++++++" << endl;
    pojazd_silnikowy::out_info();
    cout << "W czołgu jest " << amunicja << " sztuk amunicji" << endl;
    if (zaladowany) {
        cout << "Armata czołgu jest załadowana" << endl;
    } else {
        cout << "Armata czołgu nie jest załadowana" << endl;
    }
    cout << "++++++++++++++++++++++++++++++++++++++" << endl;
    return 0;
}

int czolg::dodaj_amunicje(int ilosc) {
    if (amunicja == 100) {
        cout << "Limit amunicji wynosi 100; Nie można dodać więcej amunicji" << endl;
        return 0;
    }
    if (amunicja < 0) {
        cout << "Podano niewłaściwą ilość amunicji" << endl;
        return 0;
    }

    if (amunicja + ilosc > 100) {
        amunicja = 100;
        cout << "Dodano " << 100 - amunicja << " sztuk amunicji" << endl;
        return 0;
    }
    amunicja += ilosc;
    cout << "Dodano " << ilosc << " sztuk amunicji" << endl;
    return 0;

}

int czolg::laduj() {
    if (zaladowany) {
        cout << "Działo jest juz załadowane" << endl;
    } else if (amunicja > 0) {
        int temp = 0;
        for (int i = 0; i < 3; i++) {
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
        for (int i = 0; i < 3; i++) {
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

int czolg::dodaj_zaloge(int miejsce, string imie, string nazwisko, int wiek) {
    if (miejsce == 0 or miejsce == 1 or miejsce == 2 or miejsce == 3 or miejsce == 4) {
        zaloga[miejsce].in_pasazer(imie, nazwisko, wiek);
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
        zaloga[miejsce].out_pasazer_czolg();
    } else {
        cout << "Wybrano nieprawidłowe miejsce" << endl;
    }
    return 0;
}

int czolg::out_all_zaloga() {
    out_kierowca();
    for (int i = 0; i < 4; i++) {
        cout << "VVVVV MIEJSCE NR " << i << "VVVVV" << endl;
        zaloga[i].out_pasazer_czolg();
    }
}
