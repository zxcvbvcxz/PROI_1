
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
    bool prawo_jazdy;


public:
//    kierowca();
//    kierowca(const kierowca& orig);
//    virtual ~kierowca();
    
    int in_kierowca();
    int out_kierowca();
    


};

#endif /* KIEROWCA_H */

