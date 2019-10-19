#include <iostream>
#include <string>
#include"samochod.h"
using namespace std;

int samochod::wmarka(){
    cout << "Podaj markę pojazdu:" << endl;
    getline( cin, marka);
    return 0;
};
int samochod::wmodel(){
    cout << "Podaj model pojazdu:" << endl;
    getline( cin, model);
    return 0;
};

int samochod::wrocznik(){
    cout << "Podaj rocznik pojazdu:" << endl;
    cin >> rocznik;
    return 0;
};

int samochod::rmarka(){
    if(marka.empty()){
        cout << "Pole marka jest puste" << endl;
        return 0;
    }
    cout << "Marka:" << marka << endl;
    return 0;
};

int samochod::rmodel(){
    if(marka.empty()){
        cout << "Pole model jest puste" << endl;
        return 0;
    }
    cout << "Model:" << model << endl;
    return 0;
};

int samochod::rrocznik(){
    if(marka.empty()){
        cout << "Pole rocznik jest puste" << endl;
        return 0;
    }
    cout <<"Rocznik:" << rocznik << endl;
    return 0;
};

int samochod::rinfo(){
    rmarka();
    rmodel();
    rrocznik();
    return 0;
};

int samochod::winfo(){
    wmarka();
    wmodel();
    wrocznik();
    return 0;
};