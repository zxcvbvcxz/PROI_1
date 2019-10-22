/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pasazer.h
 * Author: Bogusław Malewski
 *
 * Created on 21 października 2019, 15:09
 */

#ifndef PASAZER_H
#define PASAZER_H

#include <string>
#include <iostream>

using namespace std;

class pasazer
{
private:
    bool obecny = false;
    string imie;
    string nazwisko;
    int wiek = 0;

public:

    int in_pasazer(); //wprowadza dane do klasy
    int out_pasazer(); //wypisuje dane z klasy
    int usun_pasazer();//usuwa pasazera 
    bool operator++(); //zwiększa wiek pasażera
    bool operator--(); //zmniejsza wiek pasażera
    bool operator<=(pasazer pas1); //porównuje wieki pasażerów
    bool operator<(pasazer pas1); //porównuje wieki pasażerów
    bool operator>=(pasazer pas1); //porównuje wieki pasażerów
    bool operator>(pasazer pas1); //porównuje wieki pasażerów
    bool operator==(pasazer pas1); //porównuje wieki pasażerów
    friend ostream & operator<<(ostream & os, const pasazer &pas1); //wypisuje dane z klasy
    friend istream & operator>>(istream & is, pasazer &pas1); //wprowadza dane do klasy

};

#endif /* PASAZER_H */

