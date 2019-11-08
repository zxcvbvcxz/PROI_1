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
    enum {min_zaloga = 2};
    int amunicja = 20;
    bool zaladowany = false;
    pasazer zaloga[4];    
public:
    czolg();
    czolg(const czolg& orig);
    virtual ~czolg();

    int in_info(); //Wpisuje podstawowe dane 
    int out_info(); //Wypisuje podstawowe dane 

    int dodaj_amunicje(int ilosc);//Dodaje wpisaną ilość amunicji
    int laduj();//Ładuje armatę czołgu
    int strzelaj();//Strzela z armaty używając załadowanej amunicji

    int dodaj_zaloge(int miejsce, string imie, string nazwisko, int wiek);//Dodaje członka załogi
    int zwolnij_zaloge(int miejsce);//Zwalnia członka załogi
    int out_zaloga(int miejsce);//Wypisuje dane członka załogi z danego miejsca
    int out_all_zaloga();//Wypisuje dane wszystkich członków załogi

};

#endif /* CZOŁG_H */

