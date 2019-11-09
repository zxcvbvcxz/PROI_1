

#include "kierowca.h"
#include"Funkcje_pomocnicze.h"

int kierowca::in_kierowca() {
    cout << "Podaj imię kierowcy" << endl;
    getline(cin, imie);

    cout << "Podaj nazwisko kierowcy" << endl;
    getline(cin, nazwisko);


    double temp_double;
    while (true) {
        cout << "Podaj wiek kierowcy" << endl;
        if (wczytaj_double(temp_double)) {
            wiek = (int) temp_double;
            break;
        }
    }


    cout << "Czy kierowca ma prawo jazdy?" << endl;
    cout << " Wpisz 1 jeśli tak, wpisz 0 jeśli nie." << endl;
    wczytaj_double(temp_double);
    prawo_jazdy = temp_double;
}

int kierowca::out_kierowca() {
    cout << "--------------------------------------" << endl;

    if (imie.empty()) {
        cout << "Pole imię jest puste" << endl;
    } else
        cout << "Imię kierowcy:" << imie << endl;

    if (nazwisko.empty()) {
        cout << "Pole nazwisko jest puste" << endl;
    } else
        cout << "Nazwisko kierowcy:" << nazwisko << endl;

    if (wiek == 0) {
        cout << "Pole wiek jest puste" << endl;
    } else
        cout << "Wiek kierowcy:" << wiek << endl;

    cout << "Prawo jazdy:";
    if (prawo_jazdy == true) {
        cout << "Tak" << endl;
    } else {
        cout << "Nie" << endl;
    }
    cout << "--------------------------------------" << endl;
}

string kierowca::rimie() {
    return imie;
}

string kierowca::rnazwisko() {
    return nazwisko;
}

int kierowca::rwiek() {
    return wiek;
}

bool kierowca::rfprawo_jazdy() {
    return prawo_jazdy;
}

int kierowca::wimie(string &imie_) {
    imie = imie_;
}

int kierowca::wnazwisko(string& nazwisko_) {
    nazwisko = nazwisko_;
}

int kierowca::wwiek(int &wiek_) {
    wiek = wiek_;
}

int kierowca::wfprawo_jazdy(bool prawo_) {
    prawo_jazdy = prawo_;
}

bool kierowca::czy_prawo_jazdy() {
    return prawo_jazdy;
}

bool kierowca::operator++() {
    this->wiek++;
}

bool kierowca::operator--() {
    this->wiek--;
}

bool kierowca::operator<=(kierowca kier1) {
    return (this->wiek <= kier1.wiek);
}

bool kierowca::operator<(kierowca kier1) {
    return (this->wiek < kier1.wiek);
}

bool kierowca::operator>=(kierowca kier1) {
    return (this->wiek >= kier1.wiek);
}

bool kierowca::operator>(kierowca kier1) {
    return (this->wiek > kier1.wiek);
}

bool kierowca::operator==(kierowca kier1) {
    return (this->wiek == kier1.wiek);
}

ostream & operator<<(ostream & os, const kierowca &kier1) {


    cout << "--------------------------------------" << endl;

    if (kier1.imie.empty()) {
        cout << "Pole imię jest puste" << endl;
    } else
        cout << "Imię kierowcy:" << kier1.imie << endl;

    if (kier1.nazwisko.empty()) {
        cout << "Pole nazwisko jest puste" << endl;
    } else
        cout << "Nazwisko kierowcy:" << kier1.nazwisko << endl;

    if (kier1.wiek == 0) {
        cout << "Pole wiek jest puste" << endl;
    } else
        cout << "Wiek kierowcy:" << kier1.wiek << endl;

    cout << "Prawo jazdy:";
    if (kier1.prawo_jazdy == true) {
        cout << "Tak" << endl;
    } else {
        cout << "Nie" << endl;
    }
    cout << "--------------------------------------" << endl;
    return os;
}

istream & operator>>(istream & is, kierowca &kier1) {
    cout << "Podaj imię kierowcy" << endl;
    getline(cin, kier1.imie);

    cout << "Podaj nazwisko kierowcy" << endl;
    getline(cin, kier1.nazwisko);


    double temp_double;
    while (true) {
        cout << "Podaj wiek kierowcy" << endl;
        if (wczytaj_double(temp_double)) {
            kier1.wiek = (int) temp_double;
            break;
        }
    }


    cout << "Czy kierowca ma prawo jazdy?" << endl;
    cout << " Wpisz 1 jeśli tak, wpisz 0 jeśli nie." << endl;
    wczytaj_double(temp_double);
    kier1.prawo_jazdy = temp_double;
    return is;
}