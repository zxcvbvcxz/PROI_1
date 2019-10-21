

#include <cstdlib>
#include "samochod.h"
#include "kierowca.h"
#include "pasazer.h"
#include "bagaznik.h"
#include "bak.h"
#include "silnik.h"


#define DEBUG

using namespace std;

int main(int argc, char** argv) {

#ifdef DEBUG
    samochod pojazd1;

    pasazer pas1;
    bagaznik bag1;
    bak bak1;
    silnik silnik1;

    //test klasy kierowca
    cout << "test klasy kierowca" << endl;
    kierowca kier1;
    kierowca kier2;

//    kier1.out_kierowca();
//    kier1.czy_prawo_jazdy();
    kier1.in_kierowca();
//    kier1.out_kierowca();
//    kier1.czy_prawo_jazdy();
//    ++kier1;
//    kier1.out_kierowca();
//    --kier1;
//    kier1.out_kierowca();
//    kier2.in_kierowca();
//    kier2.out_kierowca();
//    cout << (kier1 < kier2) << endl;
    cout << "Uga buga" << endl;
    cout <<kier1 << endl;


    cout << "KONIEC test klasy kierowca" << endl;






#endif

    cout << "Koniec programu" << endl;
    return 0;
}

