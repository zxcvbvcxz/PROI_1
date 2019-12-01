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
#include <vector>


using namespace std;

int main(int argc, char** argv) {
    //    czolg czolg1;
    //    samochod sam;
    //    radiowoz rad;
    //    
    //    pojazd_silnikowy * lista[3];
    //    lista[0] = &czolg1;
    //    lista[1] = &sam;
    //    lista[2] = &rad;
    //
    vector<ofstream> vfout_czolg;
    //    ofstream fout_samochod("samochod.txt");
    //    ofstream fout_radiowoz("radiowoz.txt");
    //
    //    fout_czolg << czolg1;
    //    fout_samochod << sam;
    //    fout_radiowoz << rad;
    //
    vector<ifstream> vfin_czolg;
    //    ifstream fin_samochod("samochod.txt");
    //    ifstream fin_radiowoz("radiowoz.txt");

    vector<czolg> czolgi;
    vector<samochod> samochody;
    vector<radiowoz> radiowozy;
    int licznik_czolg = 0;
    int licznik_sam = 0;
    int licznik_rad = 0;
    string plik_czolg = "czolg";
    string plik_sam = "samochod";
    string plik_rad = "radiowoz";






    while (1) {
        double temp_double;
        int wybor;
        string t_str;
        int nr_czolg;
        int nr_sam;
        int nr_rad;

        while (true) {
            cout << "Wybierz typ obiektów którymi chcesz zarządzać" << endl;
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
                cout << "Liczba dostępnych czołgów:" << endl;
                for (auto i = czolgi.begin(); i != czolgi.end(); i++) {
                    int j = 0;
                    j++;
                    cout << j << '.' << endl;
                    cout.width(15);
                    cout << i->get_marka() << i->get_model() << i->get__rocznik();
                    cout.width(0);
                }
                if (czolgi.begin() == czolgi.end()) {
                    cout << "Nie ma dostępnych żadnych czołgów!" << endl;
                }

                while (true) {
                    cout << "Podaj numer czołgu którym chcesz zarządzać lub wpisz 0 aby dodać nowy czołg" << endl;
                    if (wczytaj_double(temp_double)) {
                        if (temp_double >= 0 and temp_double <= licznik_czolg and(temp_double - int(temp_double)) == 0) {
                            nr_czolg = temp_double;
                            break;
                        } else {
                            cout << "Proszę podać liczbę całkowitą większa lub równą zero z odpowiedniego zakresu" << endl;
                        }
                    }
                }
                if (nr_czolg == 0) {
                    {
                        czolg temp_czolg;
                        czolgi.push_back(temp_czolg);
                    }
                    t_str = plik_czolg + to_string((int) (nr_czolg + 1)) + ".txt";

                    ofstream fout_czolg;
                    vfout_czolg.push_back(move(fout_czolg));
                    vfout_czolg[licznik_czolg].open(t_str.c_str());

                    ifstream fin_czolg;
                    vfin_czolg.push_back(move(fin_czolg));
                    vfin_czolg[licznik_czolg].open(t_str.c_str());

                    licznik_czolg++;
                    nr_czolg = licznik_czolg;

                } else {
                    cout << "Wybrano czolg nr." << nr_czolg << endl;
                }

                while (1) {

                    if (zakoncz) {
                        break;
                    }
                    while (true) {
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
                    if (zakoncz) {
                        break;
                    }
                    switch (wybor) {
                        case 1:
                            cin >> czolgi[nr_czolg - 1];
                            break;
                        case 2:
                            cout << czolgi[nr_czolg - 1];
                            break;
                        case 3:
                            vfin_czolg[nr_czolg - 1] >> czolgi[nr_czolg - 1];
                            break;
                        case 4:
                            vfout_czolg[nr_czolg - 1] << czolgi[nr_czolg - 1];
                            break;
                        case 5:
                            czolgi[nr_czolg - 1].in_kierowca();
                            break;
                        case 6:
                            czolgi[nr_czolg - 1].out_kierowca();
                            break;
                        case 7:
                            czolgi[nr_czolg - 1].usun_kierowca();
                            break;
                        case 8:
                            czolgi[nr_czolg - 1].in_bak();
                            break;
                        case 9:
                            czolgi[nr_czolg - 1].out_bak();
                            break;
                        case 10:
                            czolgi[nr_czolg - 1].on_silnik();
                            break;
                        case 11:
                            czolgi[nr_czolg - 1].off_silnik();
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
                            czolgi[nr_czolg - 1].przejedz(temp_double);
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
                            czolgi[nr_czolg - 1].dodaj_amunicje(temp_double);
                            break;
                        case 14:
                            czolgi[nr_czolg - 1].laduj();
                            break;
                        case 15:
                            czolgi[nr_czolg - 1].strzelaj();
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
                            czolgi[nr_czolg - 1].dodaj_zaloge(miejsce, imie, nazwisko, wiek);
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
                            czolgi[nr_czolg - 1].zwolnij_zaloge(miejsce);
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

                            czolgi[nr_czolg - 1].out_zaloga(miejsce);
                        }
                            break;
                        case 19:
                            czolgi[nr_czolg - 1].out_all_zaloga();
                            break;
                        case 20:
                            zakoncz = true;
                            break;
                    }
                }

                break;
        }
        break;
    }

    /*
                case 2://samochod
                    while (1) {
                        if (zakoncz) {
                            break;
                        }
                        while (true) {
                            cout << "Co chcesz zrobić z samochodem?" << endl;
                            cout << "1.Wprowadź podstawowe informacje o samochodzie" << endl;
                            cout << "2.Wypisz podstawowe informacje o samochodzie" << endl;
                            cout << "3.Wczytaj stan samochodu z pliku" << endl;
                            cout << "4.Zapisz stan samochodu do pliku" << endl;
                            cout << "5.Wprowadź kierowcę do samochodu" << endl;
                            cout << "6.Wypisz informacje o kierowcy samochodu" << endl;
                            cout << "7.Usuń kierowcę samochodu" << endl;
                            cout << "8.Zatankuj paliwo" << endl;
                            cout << "9.Wypisz informacje o stanie baku" << endl;
                            cout << "10.Włącz silnik" << endl;
                            cout << "11.Wyłącz silnik" << endl;
                            cout << "12.Przejedź dystans" << endl;

                            cout << "13.Wprowadź pasażera na dane miejsce" << endl;
                            cout << "14.Wypisz informacje o pasażerze" << endl;
                            cout << "15.Wypisz informacje o wszystkich pasażerach" << endl;
                            cout << "16.Usuń pasażera z danego miejsca" << endl;
                            cout << "17.Usuń wszystkich pasażerów" << endl;
                            cout << "18.Otwórz bagażnik" << endl;
                            cout << "19.Zamknij bagażnik" << endl;
                            cout << "20.Załaduj bagażnik" << endl;
                            cout << "21.Rozładuj bagażnik" << endl;
                            cout << "22.Skończ zarządzać samochodem" << endl;
                            if (wczytaj_double(temp_double)) {
                                if (temp_double >= 1 and temp_double <= 22 and(temp_double - int(temp_double)) == 0) {
                                    wybor = (int) temp_double;
                                    break;
                                } else {
                                    cout << "Proszę podać liczbę całkowitą z zakresu od 1 do 22" << endl;
                                }
                            }
                        }
                        if (zakoncz) {
                            break;
                        }
                        switch (wybor) {
                            case 1:
                                cin >> sam;
                                break;
                            case 2:
                                cout << sam;
                                break;
                            case 3:
                                fin_samochod >> sam;
                                break;
                            case 4:
                                fout_samochod << sam;
                                break;
                            case 5:
                                sam.in_kierowca();
                                break;
                            case 6:
                                sam.out_kierowca();
                                break;
                            case 7:
                                sam.usun_kierowca();
                                break;
                            case 8:
                                sam.in_bak();
                                break;
                            case 9:
                                sam.out_bak();
                                break;
                            case 10:
                                sam.on_silnik();
                                break;
                            case 11:
                                sam.off_silnik();
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
                                sam.przejedz(temp_double);
                                break;
                            case 13:
                            {
                                int miejsce;
                                while (true) {
                                    cout << "Podaj numer miejsca na którym chesz posadzić pasażera" << endl;
                                    double temp_double;
                                    if (wczytaj_double(temp_double)) {
                                        if (temp_double >= 0 and temp_double <= 6 and (temp_double - int(temp_double)) == 0) {
                                            miejsce = (int) temp_double;
                                            break;
                                        } else {
                                            cout << "Miejsce musi być liczbą całkowitą z zakresu od 0 do 6" << endl;
                                        }
                                    }
                                }
                                sam.in_pasazer(miejsce);
                            }
                                break;
                            case 14:
                            {
                                int miejsce;
                                while (true) {
                                    cout << "Podaj numer miejsca z którego chesz wypisać informacje o pasażerze" << endl;
                                    double temp_double;
                                    if (wczytaj_double(temp_double)) {
                                        if (temp_double >= 0 and temp_double <= 6 and (temp_double - int(temp_double)) == 0) {
                                            miejsce = (int) temp_double;
                                            break;
                                        } else {
                                            cout << "Miejsce musi być liczbą całkowitą z zakresu od 0 do 6" << endl;
                                        }
                                    }
                                }
                                sam.out_pasazer(miejsce);
                            }
                                break;
                            case 15:
                                sam.out_all_pasazer();
                                break;
                            case 16:
                            {
                                int miejsce;
                                while (true) {
                                    cout << "Podaj numer miejsca z którego chesz usunąć pasażera" << endl;
                                    double temp_double;
                                    if (wczytaj_double(temp_double)) {
                                        if (temp_double >= 0 and temp_double <= 6 and (temp_double - int(temp_double)) == 0) {
                                            miejsce = (int) temp_double;
                                            break;
                                        } else {
                                            cout << "Miejsce musi być liczbą całkowitą z zakresu od 0 do 6" << endl;
                                        }
                                    }
                                }
                                sam.usun_pasazer(miejsce);
                            }
                                break;
                            case 17:
                                sam.usun_all_pasazer();
                                break;
                            case 18:
                                sam.open_bagaznik();
                                break;
                            case 19:
                                sam.close_bagaznik();
                                break;
                            case 20:
                                sam.zaladuj_bagaznik();
                                break;
                            case 21:
                                sam.rozladuj_bagaznik();
                                break;
                            case 22:
                                zakoncz = true;
                                break;
                        }
                    }
                    break;
                case 3://radiowoz
                    while (1) {
                        if (zakoncz) {
                            break;
                        }
                        while (true) {
                            cout << "Co chcesz zrobić z radiowozem?" << endl;
                            cout << "1.Wprowadź podstawowe informacje o radiowozie" << endl;
                            cout << "2.Wypisz podstawowe informacje o radiowozie" << endl;
                            cout << "3.Wczytaj stan radiowozu z pliku" << endl;
                            cout << "4.Zapisz stan radiowozu do pliku" << endl;
                            cout << "5.Wprowadź kierowcę do radiowozu" << endl;
                            cout << "6.Wypisz informacje o kierowcy radiowozu" << endl;
                            cout << "7.Usuń kierowcę radiowozu" << endl;
                            cout << "8.Zatankuj paliwo" << endl;
                            cout << "9.Wypisz informacje o stanie baku" << endl;
                            cout << "10.Włącz silnik" << endl;
                            cout << "11.Wyłącz silnik" << endl;
                            cout << "12.Przejedź dystans" << endl;

                            cout << "13.Wprowadź pasażera na dane miejsce" << endl;
                            cout << "14.Wypisz informacje o pasażerze" << endl;
                            cout << "15.Wypisz informacje o wszystkich pasażerach" << endl;
                            cout << "16.Usuń pasażera z danego miejsca" << endl;
                            cout << "17.Usuń wszystkich pasażerów" << endl;
                            cout << "18.Otwórz bagażnik" << endl;
                            cout << "19.Zamknij bagażnik" << endl;
                            cout << "20.Załaduj bagażnik" << endl;
                            cout << "21.Rozładuj bagażnik" << endl;


                            cout << "22.Włącz syganlizację dźwiękową" << endl;
                            cout << "23.Wyłącz syganlizację dźwiękową" << endl;
                            cout << "24.Włącz syganlizację świetlną" << endl;
                            cout << "25.Wyłącz syganlizację świetlną" << endl;
                            cout << "26.Zatrzymaj podejrzaną osobę" << endl;
                            cout << "27.Zwolnij zatrzymanego" << endl;
                            cout << "28.Wypisz dane zatrzymanej osoby z danego miejsca" << endl;
                            cout << "29.Wypisz dane wszystkich zatrzymanych osób" << endl;
                            cout << "30.Skończ zarządzać radiowozem" << endl;
                            if (wczytaj_double(temp_double)) {
                                if (temp_double >= 1 and temp_double <= 30 and(temp_double - int(temp_double)) == 0) {
                                    wybor = (int) temp_double;
                                    break;
                                } else {
                                    cout << "Proszę podać liczbę całkowitą z zakresu od 1 do 30" << endl;
                                }
                            }
                        }
                        if (zakoncz) {
                            break;
                        }
                        switch (wybor) {
                            case 1:
                                cin >> rad;
                                break;
                            case 2:
                                cout << rad;
                                break;
                            case 3:
                                fin_radiowoz >> rad;
                                break;
                            case 4:
                                fout_radiowoz << rad;
                                break;
                            case 5:
                                rad.in_kierowca();
                                break;
                            case 6:
                                rad.out_kierowca();
                                break;
                            case 7:
                                rad.usun_kierowca();
                                break;
                            case 8:
                                rad.in_bak();
                                break;
                            case 9:
                                rad.out_bak();
                                break;
                            case 10:
                                rad.on_silnik();
                                break;
                            case 11:
                                rad.off_silnik();
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
                                rad.przejedz(temp_double);
                                break;
                            case 13:
                            {
                                int miejsce;
                                while (true) {
                                    cout << "Podaj numer miejsca na którym chesz posadzić pasażera" << endl;
                                    double temp_double;
                                    if (wczytaj_double(temp_double)) {
                                        if (temp_double >= 0 and temp_double <= 6 and (temp_double - int(temp_double)) == 0) {
                                            miejsce = (int) temp_double;
                                            break;
                                        } else {
                                            cout << "Miejsce musi być liczbą całkowitą z zakresu od 0 do 6" << endl;
                                        }
                                    }
                                }
                                rad.in_pasazer(miejsce);
                            }
                                break;
                            case 14:
                            {
                                int miejsce;
                                while (true) {
                                    cout << "Podaj numer miejsca z którego chesz wypisać informacje o pasażerze" << endl;
                                    double temp_double;
                                    if (wczytaj_double(temp_double)) {
                                        if (temp_double >= 0 and temp_double <= 6 and (temp_double - int(temp_double)) == 0) {
                                            miejsce = (int) temp_double;
                                            break;
                                        } else {
                                            cout << "Miejsce musi być liczbą całkowitą z zakresu od 0 do 6" << endl;
                                        }
                                    }
                                }
                                rad.out_pasazer(miejsce);
                            }
                                break;
                            case 15:
                                rad.out_all_pasazer();
                                break;
                            case 16:
                            {
                                int miejsce;
                                while (true) {
                                    cout << "Podaj numer miejsca z którego chesz usunąć pasażera" << endl;
                                    double temp_double;
                                    if (wczytaj_double(temp_double)) {
                                        if (temp_double >= 0 and temp_double <= 6 and (temp_double - int(temp_double)) == 0) {
                                            miejsce = (int) temp_double;
                                            break;
                                        } else {
                                            cout << "Miejsce musi być liczbą całkowitą z zakresu od 0 do 6" << endl;
                                        }
                                    }
                                }
                                rad.usun_pasazer(miejsce);
                            }
                                break;
                            case 17:
                                rad.usun_all_pasazer();
                                break;
                            case 18:
                                rad.open_bagaznik();
                                break;
                            case 19:
                                rad.close_bagaznik();
                                break;
                            case 20:
                                rad.zaladuj_bagaznik();
                                break;
                            case 21:
                                rad.rozladuj_bagaznik();
                                break;
                            case 22:
                                rad.on_dzwiek();
                                break;
                            case 23:
                                rad.off_dzwiek();
                                break;
                            case 24:
                                rad.on_swiatlo();
                                break;
                            case 25:
                                rad.off_swiatlo();
                                break;
                            case 26:
                            {
                                int miejsce, wiek;
                                string imie, nazwisko;
                                while (true) {
                                    cout << "Podaj numer miejsca na którym chesz posadzić zatrzymaną osobę" << endl;
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
                                cout << "Podaj imię zatrzymanego" << endl;
                                getline(cin, imie);

                                cout << "Podaj nazwisko zatrzymanego" << endl;
                                getline(cin, nazwisko);

                                while (true) {
                                    cout << "Podaj wiek zatrzymanego" << endl;
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
                                rad.zatrzymaj(miejsce, imie, nazwisko, wiek);
                            }
                                break;
                            case 27:
                            {
                                int miejsce;
                                while (true) {
                                    cout << "Podaj numer miejsca z którego chesz zwolnić zatrzymanego" << endl;
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
                                rad.zwolnij(miejsce);
                            }
                                break;
                            case 28:
                            {
                                int miejsce;
                                while (true) {
                                    cout << "Podaj numer miejsca z chcesz wypisać dane podejrzanego" << endl;
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
                                rad.out_zatrzymani(miejsce);
                            }
                                break;
                            case 29:
                                rad.out_all_zatrzymani();
                                break;
                            case 30:
                                zakoncz = true;
                                break;
                        }
                    }
                    break;
            }
        }


     */

    cout << "Koniec main" << endl;
    return 0;
}


