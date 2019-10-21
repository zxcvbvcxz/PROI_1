
#ifndef KIEROWCA_H
#define KIEROWCA_H

#include <string>
#include <iostream>

using namespace std;

class kierowca
{
private:
    string imie;
    string nazwisko;
    int wiek = 0;
    bool prawo_jazdy=false;


public:
    //    kierowca();
    //    kierowca(const kierowca& orig);
    //    virtual ~kierowca();

    int in_kierowca();
    int out_kierowca();
    bool czy_prawo_jazdy();
    bool operator++();
    bool operator--();
    bool operator<=(kierowca kier1);
    bool operator<(kierowca kier1);
    bool operator>=(kierowca kier1);
    bool operator>(kierowca kier1);
    bool operator==(kierowca kier1);
    friend ostream & operator<<(ostream & os,const kierowca &kier1);
};
#endif /* KIEROWCA_H */

