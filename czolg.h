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

class czolg : public pojazd_silnikowy
{
private:
    enum {min_zaloga = 3};
    int amunicja = 20;
    bool zaladowany = false;
    pasazer zaloga[4];    
public:
    czolg();
    czolg(const czolg& orig);
    virtual ~czolg();

    int in_info(); //wpisuje podstawowe dane 
    int out_info(); //wypisuje podstawowe dane 

    int dodaj_amunicje(int ilosc);
    int laduj();
    int strzelaj();

    int dodaj_zaloge(int miejsce);
    int zwolnij_zaloge(int miejsce);
    int out_zaloga(int miejsce);
    int out_all_zaloga();

};

#endif /* CZOŁG_H */

