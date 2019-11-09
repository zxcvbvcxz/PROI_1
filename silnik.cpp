

#include "silnik.h"
#include <string>
#include <iostream>

using namespace std;


int silnik::wlacz() {
    if (wlaczony) {
        cout << "Silnik jest już włączony" << endl;
    } else {
        wlaczony = true;
        cout << "Silnik został włączony" << endl;
    }
    return 0;
}

int silnik::wylacz() {
    if (wlaczony) {
        wlaczony = false;
        cout << "Silnik został wyłączony" << endl;
    } else {
        cout << "Silnik jest już wyłączony" << endl;
    }
    return 0;
}
bool silnik::rwlaczony(){
    return wlaczony;
}

int silnik::set(int stan){
    wlaczony = stan;
}
bool silnik::operator++() {
    wlacz();
}

bool silnik::operator--() {
    wylacz();
}

ostream & operator<<(ostream & os, const silnik &silnik1) {
    if (silnik1.wlaczony) {
        cout << "Silnik jest włączony" << endl;
    } else {
        cout << "Silnik jest wyłączony" << endl;
    }
    return os;
}