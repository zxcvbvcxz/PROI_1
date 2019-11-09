

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
    int in_pasazer(string imie_,string nazwisko_,int wiek);//wprowadza dane do klasy
    int out_pasazer(); //wypisuje dane z klasy
    int out_pasazer_czolg(); //wypisuje dane z klasy nazywając pasazera członkiem załogi
    int out_pasazer_radiowoz(); //wypisuje dane z klasy nazywając pasazera zatrzymanym
    int usun_pasazer();//usuwa pasazera 
    
    bool robecny();
    string rimie();
    string rnazwisko();
    int rwiek();
    
    int wobecny(int &ob);
    int wimie(string &im);
    int wnazwisko(string &na);
    int wwiek(int &wi);
    
    bool czy_obecny(); //zwraca true jeśli pasażer jest obecny
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

