/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: BM
 *
 * Created on 18 października 2019, 13:03
 */

#include <cstdlib>
#include "samochod.h"
using namespace std;


int main(int argc, char** argv) {
    samochod pojazd1;
    pojazd1.rmarka();
    pojazd1.rmodel();
    pojazd1.rrocznik();
    pojazd1.wmarka();
    pojazd1.wmodel();
    pojazd1.wrocznik();
    pojazd1.rinfo();
    pojazd1.winfo();
    pojazd1.rinfo();
    
    cout << "Koniec programu" << endl;
    
    
    

    return 0;
}

