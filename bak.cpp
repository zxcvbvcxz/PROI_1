
#include "bak.h"
#include <string>
#include <iostream>

using namespace std;


int bak::zatankuj(double litry) {
    if (stan_bak == pelny) {
        cout << "Nie można dolać plaiwa" << endl << "Bak jest pełny" << endl;
        return 0;
    }
    if (litry + stan_bak <= pelny) {
        stan_bak += litry;
        cout << "Dolano " << litry << "L paliwa do baku" << endl;
    } else {
        stan_bak = pelny;
        cout << "Dolano " << pelny - stan_bak << "L paliwa do baku" << endl;
        cout << "Bak jest teraz pełny" << endl;
    }
    return 0;
}

double bak::spal(double litry) {
    double temp_d = stan_bak;
    if (stan_bak - litry >= 0) {
        stan_bak = stan_bak - litry;
        cout << "Spalono " << litry << "L paliwa z baku" << endl;
        return litry;
    } else {
        stan_bak = 0;
        cout << "Spalono " << temp_d << "L paliwa z baku" << endl;
        cout << "Bak jest teraz pusty" << endl;
        return temp_d;
    }

    return 0;
}

double bak::info_bak() {
    cout << "W baku jest " << stan_bak << "L paliwa" << endl;
    return stan_bak;
}

bool bak::operator++() {
    this->stan_bak++;
}

bool bak::operator--() {
    this->stan_bak--;
}

bool bak::operator<=(bak bak1) {
    return (this->stan_bak <= bak1.stan_bak);
}

bool bak::operator<(bak bak1) {
    return (this->stan_bak < bak1.stan_bak);
}

bool bak::operator>=(bak bak1) {
    return (this->stan_bak >= bak1.stan_bak);
}

bool bak::operator>(bak bak1) {
    return (this->stan_bak > bak1.stan_bak);
}

bool bak::operator==(bak bak1) {
    return (this->stan_bak == bak1.stan_bak);
}

const bak & bak::operator+(bak bak1) {
    if (this->stan_bak == pelny) {
        cout << "Nie można dolać plaiwa" << endl << "Bak jest pełny" << endl;
        return *this;
    }
    if (bak1.stan_bak + this->stan_bak <= pelny) {
        this->stan_bak += bak1.stan_bak;
        cout << "Dolano " << bak1.stan_bak << "L paliwa do baku" << endl;
    } else {
        this->stan_bak = pelny;
        cout << "Dolano " << pelny - this->stan_bak << "L paliwa do baku" << endl;
        cout << "Bak jest teraz pełny" << endl;
    }
    return *this;
}

const bak & bak::operator+(double litry) {
    if (this->stan_bak == pelny) {
        cout << "Nie można dolać plaiwa" << endl << "Bak jest pełny" << endl;
        return *this;
    }
    if (litry + this->stan_bak <= pelny) {
        this->stan_bak += litry;
        cout << "Dolano " << litry << "L paliwa do baku" << endl;
    } else {
        this->stan_bak = pelny;
        cout << "Dolano " << pelny - this->stan_bak << "L paliwa do baku" << endl;
        cout << "Bak jest teraz pełny" << endl;
    }
    return *this;
}

const bak & bak::operator-(bak bak1) {
    double temp_d = stan_bak;
    if (stan_bak - bak1.stan_bak >= 0) {
        stan_bak = stan_bak - bak1.stan_bak;
        cout << "Spalono " << bak1.stan_bak << "L paliwa z baku" << endl;
        return *this;
    } else {
        stan_bak = 0;
        cout << "Spalono " << temp_d << "L paliwa z baku" << endl;
        cout << "Bak jest teraz pusty" << endl;
        return *this;
    }
}

const bak & bak::operator-(double litry) {
    double temp_d = stan_bak;
    if (stan_bak - litry >= 0) {
        stan_bak = stan_bak - litry;
        cout << "Spalono " << litry << "L paliwa z baku" << endl;
        return *this;
    } else {
        stan_bak = 0;
        cout << "Spalono " << temp_d << "L paliwa z baku" << endl;
        cout << "Bak jest teraz pusty" << endl;
        return *this;
    }
}

ostream & operator<<(ostream & os, const bak &bak1) {
    cout << "W Baku jest " << bak1.stan_bak << "L paliwa" << endl;
    return os;
}

//  const bak & operator-(bak bak1);