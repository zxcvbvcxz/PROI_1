
#ifndef SAMOCHOD_H
#define SAMOCHOD_H
#include <string>
#include <iostream>
#include"kierowca.h"
#include "pasazer.h"
#include "bagaznik.h"
#include"bak.h"
#include"silnik.h"
#include "pojazd_silnikowy.h"
#include<fstream>
using namespace std;

class samochod : public pojazd_silnikowy
{
private:
    int miejsca_dla_pasazerow;
    pasazer * pasazerowie = nullptr;
    bagaznik bagaznik_1;
public:
    samochod(int miejsca = 0); //konstruktor
    ~samochod(); //destruktor
    samochod(const samochod & sam1); //konstruktor kopiujący
    samochod &operator=(const samochod & sam1); //operator przypisania

    int in_info(); //wpisuje podstawowe dane 
    int out_info(); //wypisuje podstawowe dane 
    int fin_info(ifstream &plik); //wczytuje stan obiektu z pliku
    int fout_info(ofstream& plik); //zapisuje stan obiektu do pliku




    int in_pasazer(int miejsce); //wprowadza pasażera na dane miejsce
    int out_pasazer(int miejsce); //wypisuje dane pasażera z danego miejsca
    int out_all_pasazer(); //wypisuje dane wszystkich pasażerów z auta
    int usun_pasazer(int miejsce); //usuwa pasażera z danego miejsca
    int usun_all_pasazer(); //usuwa wszystkich pasażerów z auta

    int open_bagaznik(); //otwiera bagażnik
    int close_bagaznik(); //zamyka bagażnik
    int zaladuj_bagaznik(); //ładuje bagażnik
    int rozladuj_bagaznik(); //rozładowuje bagżnik

    int przejedz(double kilometry); //przejeżdża daną liczbę kilometrów

    friend ostream & operator<<(ostream & os, samochod &samochod1);
    friend istream & operator>>(istream & is, samochod &samochod1);
    friend ofstream & operator<<(ofstream & os, samochod &samochod1);
    friend ifstream & operator>>(ifstream & os, samochod &samochod1);
};



#endif /* SAMOCHOD_H */

