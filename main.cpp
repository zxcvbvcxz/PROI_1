

#include <cstdlib>
#include "samochod.h"
#include "kierowca.h"
#include "pasazer.h"
#include "bagaznik.h"
#include "bak.h"
#include "silnik.h"
#include "DEBUG.h"
#include "DEMO.h"
#include "czolg.h"
#include "radiowoz.h"



//#define DEBUG
#define DEMO

using namespace std;

int main(int argc, char** argv) {
    

    czolg tiger;
    tiger.strzelaj();
    tiger.out_kierowca();
    tiger.in_kierowca();
    tiger.dodaj_zaloge(0,"Jan","Kowalski",24);
    tiger.out_all_zaloga();
    
    tiger.dodaj_zaloge(1,"Marian","Kot",24);
    tiger.out_all_zaloga();
    tiger.laduj();
    tiger.strzelaj();
    cout << "Koniec main" << endl;   
    return 0;
}

