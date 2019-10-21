

#ifndef BAGAZNIK_H
#define BAGAZNIK_H

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
    


};

#endif /* BAGAZNIK_H */

