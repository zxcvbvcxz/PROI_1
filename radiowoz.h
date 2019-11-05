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

class radiowoz : samochod
{
private:
    bool syg_swietlna;
    bool syg_dzwiekowa;
    pasazer zatrzymani[3];

public:
    radiowoz();
    radiowoz(const radiowoz& orig);
    virtual ~radiowoz();
    
    int on_dzwiek();
    int off_dzwiek();
    
    int on_swiatlo();
    int off_swiatlo();
    
    int zatrzymaj(int miejsce);
    int zwolnij(int miejsce);
    int out_zatrzymani(int miejsce);
    int out_all_zatrzymani();


};

#endif /* RADIOWOZ_H */

