

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
    
    int a =89;
    int b =999;
    radiowoz mark;
 //   lol.in_pasazer(0);
    
    int c =999232323;
    int d =99923;
    mark.close_bagaznik();
    mark.out_info();
//    mark.in_info();
//    mark.on_silnik();
    cout << "Koniec main" << endl;   
    return 0;
}

