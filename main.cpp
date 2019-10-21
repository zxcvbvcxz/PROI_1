

#include <cstdlib>
#include "samochod.h"
#include "kierowca.h"

using namespace std;

int main(int argc, char** argv) {
    samochod pojazd1;

//    pojazd1.out_info();
//    pojazd1.in_info();
//    pojazd1.out_info();

    pojazd1.out_kierowca();
    pojazd1.in_kierowca();
    pojazd1.out_kierowca();

    cout << "Koniec programu" << endl;




    return 0;
}

