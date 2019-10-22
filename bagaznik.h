

#ifndef BAGAZNIK_H
#define BAGAZNIK_H

#include <iostream>

using namespace std;

class bagaznik
{
private:
    bool otwarty=false;
    bool zaladowany=false;

public:

    int otworz();
    int zamknij();
    int zaladuj();
    int rozladuj();
    bool czy_otwarty();
    friend ostream & operator<<(ostream & os, bagaznik &bag1);


};

#endif /* BAGAZNIK_H */

