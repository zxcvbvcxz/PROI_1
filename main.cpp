

#include <cstdlib>
#include "samochod.h"
#include "kierowca.h"
#include "pasazer.h"
#include "bagaznik.h"
#include "bak.h"
#include "silnik.h"
#include "DEBUG.h"
#include "DEMO.h"



#define DEBUG

using namespace std;

int main(int argc, char** argv) {

#ifdef DEBUG
    wybor_testu();

#endif

    cout << "Koniec main" << endl;
    return 0;
}

