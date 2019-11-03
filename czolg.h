/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   czołg.h
 * Author: Bogusław Malewski
 *
 * Created on 3 listopada 2019, 17:36
 */

#ifndef CZOLG_H
#define CZOLG_H
#include"pojazd_silnikowy.h"

class czolg : pojazd_silnikowy
{
private:    
    int amunicja;
    bool zaladowany;
    pasazer zaloga[5];
    int min_zaloga;
    int max_zaloga;
public:
    czolg();
    czolg(const czolg& orig);
    virtual ~czolg();

    int dodaj_amunicje();
    int laduj();
    int strzelaj();
    
    int dodaj_zaloge(int miejsce);
    int zwolnij_zaloge();
    int out_zaloga(int miejsce);
    int out_all_zaloga();
    
};

#endif /* CZOŁG_H */

