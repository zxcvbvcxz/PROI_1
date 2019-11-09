

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

    pojazd_silnikowy * lista[3];
    czolg tiger;
    czolg t34;
    // samochod reanult;
    //radiowoz pol;

    tiger.in_kierowca();
    tiger.in_info();

    ofstream fout("tutaj.txt");
    fout << tiger;
    //    fout.close();
    ifstream fin("tutaj.txt");
    ofstream fout2("Dane 2 czolgu.txt");
    fin >> t34;
    fout2 << t34;


    //    lista[0] = &tiger;
    //    lista[1] = &reanult;
    //    lista[2] = &pol;
    //
    //    for (int i = 0; i < 3; i++) {
    //        cin >> *lista[i];
    //    }
    //  //  cin >> *lista[0];
    //    
    //    for (int i = 0; i < 3; i++) {
    //        cout << *lista[i];
    //        cout << endl;
    //    }

    cout << "Koniec main" << endl;
    return 0;
}

