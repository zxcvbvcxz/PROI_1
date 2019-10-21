

#include <cstdlib>
#include "samochod.h"
#include "kierowca.h"

using namespace std;

int main(int argc, char** argv) {
    samochod pojazd1;

    //    pojazd1.out_info();
    //    pojazd1.in_info();
    //    pojazd1.out_info();

//    pojazd1.out_kierowca();
//    pojazd1.in_kierowca();
//    pojazd1.out_kierowca();
//    cout << "hihi\n";
//    pojazd1.usun_kierowca();
//    pojazd1.out_kierowca();
    
    pojazd1.in_pasazer(2);
    pojazd1.out_pasazer(2);
    pojazd1.in_info();
    pojazd1.in_pasazer(2);
    pojazd1.out_pasazer(2);
    pojazd1.out_all_pasazer();

    cout << "Koniec programu" << endl;




    return 0;
}

