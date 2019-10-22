

#ifndef BAGAZNIK_H
#define BAGAZNIK_H

#include <iostream>

using namespace std;

class bagaznik
{
private:
    bool otwarty;
    bool zaladowany;

public:
    //    bagaznik();
    //    bagaznik(const bagaznik& orig);
    //    virtual ~bagaznik();
    int otworz();
    int zamknij();
    int zaladuj();
    int rozladuj();
    bool czy_otwarty();
    friend ostream & operator<<(ostream & os,const bagaznik &bag1);


};

#endif /* BAGAZNIK_H */

