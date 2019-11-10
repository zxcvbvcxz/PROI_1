

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
    int fin_info(ifstream &plik);//wczytuje stan obiektu z pliku
    int fout_info(ofstream &plik); //zapisuje stan obiektu do pliku
    
    

    int dodaj_amunicje(int ilosc);//Dodaje wpisaną ilość amunicji
    int laduj();//Ładuje armatę czołgu
    int strzelaj();//Strzela z armaty używając załadowanej amunicji

    int dodaj_zaloge(int miejsce, string imie, string nazwisko, int wiek);//Dodaje członka załogi
    int zwolnij_zaloge(int miejsce);//Zwalnia członka załogi
    int out_zaloga(int miejsce);//Wypisuje dane członka załogi z danego miejsca
    int out_all_zaloga();//Wypisuje dane wszystkich członków załogi

    friend ostream & operator<<(ostream & os, czolg &czolg1);
    friend istream & operator>>(istream & is, czolg &czolg1);
    friend ofstream & operator<<(ofstream & os, czolg &czolg1);
    friend ifstream & operator>>(ifstream & is, czolg &czolg1);
};

#endif /* CZOŁG_H */

