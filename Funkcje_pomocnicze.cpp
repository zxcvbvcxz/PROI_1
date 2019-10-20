/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <string>

using namespace std;

bool wczytaj_double(double &liczba) {
    //wczytywanie liczby wzor: początek
    string temp_str;
    getline(cin, temp_str);
    if (temp_str.length() == 0) {
        cout << "Podano nieprawidłową liczbę" << endl;
        return false;
    }
    if (temp_str.length() == 1 and !isdigit(temp_str[0])) {
        cout << "Podano nieprawidłową liczbę" << endl;
        return false;
    }
    if (!isdigit(temp_str[0])) {
        if (temp_str[0] != '-') {
            if (temp_str[0] != '+') {
                cout << "Podano nieprawidłową liczbę" << endl;
                return false;
            }
        }
    }
    if (temp_str[0] == '-' or temp_str[0] == '+') {
        if (!isdigit(temp_str[1])) {
            cout << "Podano nieprawidłową liczbę" << endl;
            return false;
        }
    }

    liczba = stod(temp_str);
    //wczytywanie liczby wzor: koniec

    return true;
};