/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   radiowoz.h
 * Author: Bogusław Malewski
 *
 * Created on 3 listopada 2019, 17:13
 */

#ifndef RADIOWOZ_H
#define RADIOWOZ_H

#include "samochod.h"

class radiowoz : public samochod
{
private:
    bool syg_swietlna;
    bool syg_dzwiekowa;
    pasazer zatrzymani[3];

public:
    radiowoz();
    radiowoz(const radiowoz& orig);
    virtual ~radiowoz();
    
    int in_info(); //wpisuje podstawowe dane 
    int out_info(); //wypisuje podstawowe dane 

    int on_dzwiek(); //Włącza syganlizację świetlną
    int off_dzwiek(); //Wyłącza syganlizację świetlną

    int on_swiatlo(); //Włącza syganlizację dźwiękową
    int off_swiatlo(); //Wyłącza syganlizację dźwiękową

    int zatrzymaj(int miejsce, string imie, string nazwisko, int wiek);//Wprowadza do radiowozu zatrzymaną osobę
    int zwolnij(int miejsce); //Wyprowadza z radiowozu zatrzymaną osobę
    int out_zatrzymani(int miejsce); //Wypisuje dane zatrzymanej osoby
    int out_all_zatrzymani(); //Wypisuje dane wszystkich zatrzymanych osob


};

#endif /* RADIOWOZ_H */

