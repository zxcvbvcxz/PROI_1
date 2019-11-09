/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include<iostream>
#include "samochod.h"
#include "kierowca.h"
#include "Funkcje_pomocnicze.h"

int testuj_kierowca();
int testuj_pasazer();
int testuj_bagaznik();
int testuj_bak();
int testuj_silnik();
int testuj_samochod();
int wybor_testu();
int testuj_all();

int wybor_testu() {
    while (true) {
        cout << "Którą klasę chcesz przetestować?" << endl;
        int wybor;
        while (true) {
            cout << "1.kierowca" << endl;
            cout << "2.pasazer" << endl;
            cout << "3.bagaznik" << endl;
            cout << "4.bak" << endl;
            cout << "5.silnik" << endl;
            cout << "6.samochod" << endl;
            cout << "7.TESTUJ WSZYSTKO" << endl;
            cout << "8.Zakończ program" << endl;


            double temp_double;
            if (wczytaj_double(temp_double)) {
                if ((temp_double - int(temp_double)) == 0) {
                    wybor = (int) temp_double;
                    break;
                } else {
                    cout << "Liczba musi być całkowita" << endl;
                }
            }
        }
        switch (wybor) {
            case 1:
                testuj_kierowca();
                break;

            case 2:
                testuj_pasazer();
                break;
            case 3:
                testuj_bagaznik();
                break;
            case 4:
                testuj_bak();
                break;
            case 5:
                testuj_silnik();
                break;
            case 6:
                testuj_samochod();
                break;
            case 7:
                testuj_all();
                break;
            case 8:
                cout << "Koniec programu" << endl;
                return 0;
                break;
        }
    }
}

int testuj_all() {
    testuj_kierowca();
    testuj_pasazer();
    testuj_bagaznik();
    testuj_bak();
    testuj_silnik();
    testuj_samochod();
    return 0;
}

int testuj_kierowca() {
    cout << "Zaczynam test klasy kierowca" << endl;
    kierowca kier1, kier2;
    kier1.in_kierowca();
    kier2.in_kierowca();
    kier1.out_kierowca();
    kier2.out_kierowca();

    ++kier1;
    kier1.out_kierowca();
    --kier1;
    kier1.out_kierowca();

    cout << (kier1 <= kier2) << endl
            << (kier1 < kier2) << endl
            << (kier1 >= kier2) << endl
            << (kier1 > kier2) << endl
            << (kier1 == kier2) << endl
            << kier1 << endl;

    cin >> kier2;
    cout << kier2;
    cout << "Kończe test klasy kierowca" << endl;
    return 0;
}

int testuj_pasazer() {
    cout << "Zaczynam test klasy pasazer" << endl;
    pasazer pas1, pas2;
    pas1.in_pasazer();
    pas2.in_pasazer();
    pas1.out_pasazer();
    pas2.out_pasazer();

    ++pas1;
    pas1.out_pasazer();
    --pas1;
    pas1.out_pasazer();

    cout << (pas1 <= pas2) << endl
            << (pas1 < pas2) << endl
            << (pas1 >= pas2) << endl
            << (pas1 > pas2) << endl
            << (pas1 == pas2) << endl
            << pas1 << endl;

    cin >> pas2;
    cout << pas2;
    cout << "Kończe test klasy pasazer" << endl;
    return 0;
}

int testuj_bagaznik() {
    cout << "Zaczynam test klasy pasazer" << endl;
    bagaznik bag1;
    cout << bag1 << endl;
    bag1.zaladuj();
    bag1.otworz();
    cout << bag1 << endl;
    bag1.zaladuj();
    bag1.zamknij();
    cout << bag1 << endl;

    cout << "Kończe test klasy pasazer" << endl;
    return 0;
}

int testuj_bak() {
    cout << "Zaczynam test klasy bak" << endl;
    bak bak1, bak2;
    bak1.zatankuj(10);
    bak2.zatankuj(40);
    bak1.info_bak();
    bak2.info_bak();

    ++bak1;
    bak1.info_bak();
    --bak1;
    bak1.info_bak();

    cout << (bak1 <= bak2) << endl
            << (bak1 < bak2) << endl
            << (bak1 >= bak2) << endl
            << (bak1 > bak2) << endl
            << (bak1 == bak2) << endl
            << bak1 << endl;

    cin >> bak1;
    cout << bak1;
    cout << bak2;
    bak1 + bak2;
    cout << bak2 << endl;
    cout << "Kończe test klasy bak" << endl;
    return 0;
}

int testuj_silnik() {
    cout << "Zaczynam test klasy silnik" << endl;
    silnik silnik1;
    cout << silnik1 << endl;
    --silnik1;
    cout << silnik1 << endl;
    ++silnik1;
    cout << silnik1 << endl;

    cout << "Kończe test klasy silnik" << endl;
    return 0;
}

int testuj_samochod() {
    cout << "Zaczynam test klasy samochod" << endl;
    samochod sam1, sam2;
    cout << sam1 << endl;
    sam1.in_info();
    cout << sam1 << endl;
    sam2 = sam1;
    cout << sam2 << endl;

    --sam1;
    ++sam1;
    cout << "Kończe test klasy samochod" << endl;
}
