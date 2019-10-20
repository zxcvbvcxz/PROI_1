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
    pojazd1.out_info();
    pojazd1.in_info();
    pojazd1.out_info();
    
    cout << "Koniec programu" << endl;
    
    
    

    return 0;
}

