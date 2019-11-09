/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include "samochod.h"
#include "kierowca.h"
#include<iostream>

int demo_taxi() {
    
    
    samochod taxi;
    taxi.in_info();
    taxi.in_kierowca();
    taxi.in_pasazer(0);
    taxi.in_pasazer(1);
    taxi.open_bagaznik();
    taxi.zaladuj_bagaznik();
    taxi.close_bagaznik();
    taxi.out_kierowca();
    taxi.out_all_pasazer();
    ++taxi;
    taxi.przejedz(30);
    --taxi;
    taxi.in_bak();
    ++taxi;
    taxi.przejedz(50);
    --taxi;
    taxi.usun_all_pasazer();
    taxi.open_bagaznik();
    taxi.rozladuj_bagaznik();
    taxi.close_bagaznik();
    taxi.out_all_pasazer();
    taxi.usun_kierowca();
    return 0;
}