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
#include"Funkcje_pomocnicze.h"


using namespace std;

int main(int argc, char** argv) {
    czolg czolg1;
    samochod sam;
    radiowoz rad;

    pojazd_silnikowy * lista[3];
    lista[0] = &czolg1;
    lista[1] = &sam;
    lista[2] = &rad;

    ofstream fout_czolg("czolg.txt");
    ofstream fout_samochod("samochod.txt");
    ofstream fout_radiowoz("radiowoz.txt");

    ifstream fin_czolg("czolg.txt");
    ifstream fin_samochod("samochod.txt");
    ifstream fin_radiowoz("radiowoz.txt");




    while (1) {
        double temp_double;
        int wybor;

        while (true) {
            cout << "Wybierz obiekt których chesz zarządzać" << endl;
            cout << "1.Czołg" << endl;
            cout << "2.Samochód" << endl;
            cout << "3.Radiowóz" << endl;
            cout << "4.ZAKOŃCZ PROGRAM" << endl;
            if (wczytaj_double(temp_double)) {
                if (temp_double >= 1 and temp_double <= 4 and(temp_double - int(temp_double)) == 0) {
                    wybor = (int) temp_double;
                    break;
                } else {
                    cout << "Proszę podać liczbę całkowitą z zakresu od 1 do 4" << endl;
                }
            }
        }
        if (wybor == 4) {
            break;
        }

        bool zakoncz = false;
        switch (wybor) {
            case 1://czołg                
                while (true) {
                    if (zakoncz) {
                        break;
                    }
                    cout << "Co chcesz zrobić z czołgiem?" << endl;
                    cout << "1.Wprowadź podstawowe informacje o czołgu" << endl;
                    cout << "2.Wypisz podstawowe informacje o czołgu" << endl;
                    cout << "3.Wczytaj stan czołgu z pliku" << endl;
                    cout << "4.Zapisz stan czołgu do pliku" << endl;
                    cout << "5.Wprowadź kierowcę do czołgu" << endl;
                    cout << "6.Wypisz informacje o kierowcy czołgu" << endl;
                    cout << "7.Usuń kierowcę czołgu" << endl;
                    cout << "8.Zatankuj paliwo" << endl;
                    cout << "9.Wypisz informacje o stanie baku" << endl;
                    cout << "10.Włącz silnik" << endl;
                    cout << "11.Wyłącz silnik" << endl;
                    cout << "12.Przejedź dystans" << endl;

                    cout << "13.Dodaj amunicje do czołgu" << endl;
                    cout << "14.Załaduj armatę czołgu" << endl;
                    cout << "15.Wystrzel z armaty czołgu" << endl;
                    cout << "16.Dodaj członka załogi" << endl;
                    cout << "17.Zwolnij członka załogi" << endl;
                    cout << "18.Wypisz informacje o członku załogi" << endl;
                    cout << "19.Wypisz informacje o wszyskich członkach załogi" << endl;
                    cout << "20.Skończ zarządzać czołgiem" << endl;

                    if (wczytaj_double(temp_double)) {
                        if (temp_double >= 1 and temp_double <= 20 and(temp_double - int(temp_double)) == 0) {
                            wybor = (int) temp_double;
                            break;
                        } else {
                            cout << "Proszę podać liczbę całkowitą z zakresu od 1 do 20" << endl;
                        }
                    }
                }
                switch (wybor) {
                    case 1:
                        cin >> czolg1;
                        break;
                    case 2:
                        cout << czolg1;
                        break;
                    case 3:
                        fin_czolg >> czolg1;
                        break;
                    case 4:
                        fout_czolg << czolg1;
                        break;
                    case 5:
                        czolg1.in_kierowca();
                        break;
                    case 6:
                        czolg1.out_kierowca();
                        break;
                    case 7:
                        czolg1.usun_kierowca();
                        break;
                    case 8:
                        czolg1.in_bak();
                        break;
                    case 9:
                        czolg1.out_bak();
                        break;
                    case 10:
                        czolg1.on_silnik();
                        break;
                    case 11:
                        czolg1.off_silnik();
                        break;
                    case 12:
                        cout << "Podaj ile kilometrów chesz przejechać" << endl;
                        while (1) {
                            if (wczytaj_double(temp_double)) {
                                if (temp_double >= 0) {
                                    break;
                                } else {
                                    cout << "Proszę podać liczbę nieujemną" << endl;
                                }
                            }
                        }
                        czolg1.przejedz(temp_double);
                        break;
                    case 13:
                        cout << "Podaj ile sztuk amunicji chesz dodać" << endl;
                        while (1) {
                            if (wczytaj_double(temp_double)) {
                                if (temp_double >= 0) {
                                    break;
                                } else {
                                    cout << "Proszę podać liczbę nieujemną" << endl;
                                }
                            }
                        }
                        czolg1.dodaj_amunicje(temp_double);
                        break;
                    case 14:
                        czolg1.laduj();
                        break;
                    case 15:
                        czolg1.strzelaj();
                        break;
                    case 16:
                    {
                        int miejsce, wiek;
                        string imie, nazwisko;
                        while (true) {
                            cout << "Podaj numer miejsca do którego chesz dodać członka załogi" << endl;
                            double temp_double;
                            if (wczytaj_double(temp_double)) {
                                if (temp_double >= 0 and temp_double <= 2 and (temp_double - int(temp_double)) == 0) {
                                    miejsce = (int) temp_double;
                                    break;
                                } else {
                                    cout << "Miejsce musi być liczbą całkowitą z zakresu od 0 do 2" << endl;
                                }
                            }
                        }
                        cout << "Podaj imię członka załogi" << endl;
                        getline(cin, imie);

                        cout << "Podaj nazwisko członka załogi" << endl;
                        getline(cin, nazwisko);

                        while (true) {
                            cout << "Podaj wiek członka załogi" << endl;
                            double temp_double;
                            if (wczytaj_double(temp_double)) {
                                if (temp_double >= 18 and temp_double <= 99 and (temp_double - int(temp_double)) == 0) {
                                    wiek = (int) temp_double;
                                    break;
                                } else {
                                    cout << "Wiek musi być liczbą całkowitą z zakresu od 18 do 99 " << endl;
                                }
                            }
                        }


                        czolg1.dodaj_zaloge(miejsce, imie, nazwisko, wiek);
                    }
                        break;
                    case 17:
                    {
                        int miejsce;

                        while (true) {
                            cout << "Podaj numer miejsca z którego chesz usunąć członka załogi" << endl;
                            double temp_double;
                            if (wczytaj_double(temp_double)) {
                                if (temp_double >= 0 and temp_double <= 2 and (temp_double - int(temp_double)) == 0) {
                                    miejsce = (int) temp_double;
                                    break;
                                } else {
                                    cout << "Miejsce musi być liczbą całkowitą z zakresu od 0 do 2" << endl;
                                }
                            }
                        }
                        czolg1.zwolnij_zaloge(miejsce);
                    }
                        break;
                    case 18:
                    {
                        int miejsce;

                        while (true) {
                            cout << "Podaj numer miejsca z którego chesz uzyskać informacje o członku załogi" << endl;
                            double temp_double;
                            if (wczytaj_double(temp_double)) {
                                if (temp_double >= 0 and temp_double <= 2 and (temp_double - int(temp_double)) == 0) {
                                    miejsce = (int) temp_double;
                                    break;
                                } else {
                                    cout << "Miejsce musi być liczbą całkowitą z zakresu od 0 do 2" << endl;
                                }
                            }
                        }

                        czolg1.out_zaloga(miejsce);
                    }
                        break;
                    case 19:
                        czolg1.out_all_zaloga();
                        break;
                    case 20:
                        zakoncz = true;
                        break;
                }

                break;
            case 2://samochod
                break;
            case 3://radiowoz
                break;
        }
    }


    cout << "Koniec main" << endl;
    return 0;
}


