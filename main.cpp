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
#include <algorithm>


using namespace std;

struct czolgi_struct {
    czolg cz;
    ofstream fout_czolg;
    ifstream fin_czolg;
};

int main(int argc, char** argv) {



    //    vector<ofstream> vfout_czolg;
    //    vfout_czolg.reserve(sizeof (ofstream) * 10);

    vector<ofstream> vfout_sam;
    vfout_sam.reserve(sizeof (ofstream) * 10);

    vector<ofstream> vfout_rad;
    vfout_rad.reserve(sizeof (ofstream) * 10);

    //    vector<ifstream> vfin_czolg;
    //    vfin_czolg.reserve(sizeof (ifstream) * 10);

    vector<ifstream> vfin_sam;
    vfin_sam.reserve(sizeof (ifstream) * 10);

    vector<ifstream> vfin_rad;
    vfin_rad.reserve(sizeof (ifstream) * 10);


    vector<czolgi_struct> czolgi;
    czolgi.reserve(sizeof (czolgi_struct) * 10);

    vector<samochod> samochody;
    samochody.reserve(sizeof (samochod)*10);
    vector<radiowoz> radiowozy;
    radiowozy.reserve(sizeof (radiowoz)*10);
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
                cout << "Lista dostępnych czołgów:" << endl;
                cout << "   Marka:                Model:                Rocznik:" << endl;
            {
                int j = 0;
                for (auto i = czolgi.begin(); i != czolgi.end(); i++) {
                    j++;
                    cout << j << ". ";
                    cout.width(22);
                    cout << left;
                    cout << i->cz.get_marka();
                    cout.width(22);
                    cout << left;
                    cout << i->cz.get_model();
                    cout.width(16);
                    cout << i->cz.get__rocznik() << endl;
                }
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
                        czolgi_struct temp_czolg;
                        czolgi.push_back(move(temp_czolg));
                    }
                    nr_czolg = licznik_czolg + 1;
                    t_str = plik_czolg + to_string((int) (nr_czolg)) + ".txt";


                    czolgi[licznik_czolg].fout_czolg.open(t_str.c_str());


                    czolgi[licznik_czolg].fin_czolg.open(t_str.c_str());

                    licznik_czolg++;
//                    sort(czolgi.begin(), czolgi.end(), [](const czolgi_struct& a, const czolgi_struct & b) {
//                        return a.cz.get__rocznik() > b.cz.get__rocznik();
//                    });

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
                            cin >> czolgi[nr_czolg - 1].cz;
//                            sort(czolgi.begin(), czolgi.end(), [](const czolgi_struct& a, const czolgi_struct & b) {
//                                return a.cz.get__rocznik() > b.cz.get__rocznik();
//                            });
                            break;
                        case 2:
                            cout << czolgi[nr_czolg - 1].cz;
                            break;
                        case 3:
                            czolgi[nr_czolg - 1].fin_czolg >> czolgi[nr_czolg - 1].cz;
                            break;
                        case 4:
                            czolgi[nr_czolg - 1].fout_czolg << czolgi[nr_czolg - 1].cz;
                            break;
                        case 5:
                            czolgi[nr_czolg - 1].cz.in_kierowca();
                            break;
                        case 6:
                            czolgi[nr_czolg - 1].cz.out_kierowca();
                            break;
                        case 7:
                            czolgi[nr_czolg - 1].cz.usun_kierowca();
                            break;
                        case 8:
                            czolgi[nr_czolg - 1].cz.in_bak();
                            break;
                        case 9:
                            czolgi[nr_czolg - 1].cz.out_bak();
                            break;
                        case 10:
                            czolgi[nr_czolg - 1].cz.on_silnik();
                            break;
                        case 11:
                            czolgi[nr_czolg - 1].cz.off_silnik();
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
                            czolgi[nr_czolg - 1].cz.przejedz(temp_double);
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
                            czolgi[nr_czolg - 1].cz.dodaj_amunicje(temp_double);
                            break;
                        case 14:
                            czolgi[nr_czolg - 1].cz.laduj();
                            break;
                        case 15:
                            czolgi[nr_czolg - 1].cz.strzelaj();
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
                            czolgi[nr_czolg - 1].cz.dodaj_zaloge(miejsce, imie, nazwisko, wiek);
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
                            czolgi[nr_czolg - 1].cz.zwolnij_zaloge(miejsce);
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

                            czolgi[nr_czolg - 1].cz.out_zaloga(miejsce);
                        }
                            break;
                        case 19:
                            czolgi[nr_czolg - 1].cz.out_all_zaloga();
                            break;
                        case 20:
                            zakoncz = true;
                            break;
                    }
                }
                break;
            case 2://samochod

                cout << "Lista dostępnych samochodów:" << endl;
                cout << "   Marka:                Model:                Rocznik:" << endl;
            {
                int j = 0;
                for (auto i = samochody.begin(); i != samochody.end(); i++) {
                    j++;
                    cout << j << ". ";
                    cout.width(22);
                    cout << left;
                    cout << i->get_marka();
                    cout.width(22);
                    cout << left;
                    cout << i->get_model();
                    cout.width(16);
                    cout << i->get__rocznik() << endl;
                }
            }
                if (samochody.begin() == samochody.end()) {
                    cout << "Nie ma dostępnych żadnych samochodów!" << endl;
                }

                while (true) {
                    cout << "Podaj numer samochodu którym chcesz zarządzać lub wpisz 0 aby dodać nowy samochód" << endl;
                    if (wczytaj_double(temp_double)) {
                        if (temp_double >= 0 and temp_double <= licznik_sam and(temp_double - int(temp_double)) == 0) {
                            nr_sam = temp_double;
                            break;
                        } else {
                            cout << "Proszę podać liczbę całkowitą większa lub równą zero z odpowiedniego zakresu" << endl;
                        }
                    }
                }
                if (nr_sam == 0) {
                    {
                        samochod temp_sam;
                        samochody.push_back(temp_sam);
                    }
                    nr_sam = licznik_sam + 1;
                    t_str = plik_sam + to_string((int) (nr_sam)) + ".txt";

                    ofstream fout_sam;
                    vfout_sam.push_back(move(fout_sam));
                    vfout_sam[licznik_sam].open(t_str.c_str());

                    ifstream fin_sam;
                    vfin_sam.push_back(move(fin_sam));
                    vfin_sam[licznik_sam].open(t_str.c_str());

                    licznik_sam++;


                } else {
                    cout << "Wybrano samochód nr." << nr_sam << endl;
                }
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
                            cin >> samochody[nr_sam - 1];
                            break;
                        case 2:
                            cout << samochody[nr_sam - 1];
                            break;
                        case 3:
                            vfin_sam[nr_sam - 1] >> samochody[nr_sam - 1];
                            break;
                        case 4:
                            vfout_sam[nr_sam - 1] << samochody[nr_sam - 1];
                            break;
                        case 5:
                            samochody[nr_sam - 1].in_kierowca();
                            break;
                        case 6:
                            samochody[nr_sam - 1].out_kierowca();
                            break;
                        case 7:
                            samochody[nr_sam - 1].usun_kierowca();
                            break;
                        case 8:
                            samochody[nr_sam - 1].in_bak();
                            break;
                        case 9:
                            samochody[nr_sam - 1].out_bak();
                            break;
                        case 10:
                            samochody[nr_sam - 1].on_silnik();
                            break;
                        case 11:
                            samochody[nr_sam - 1].off_silnik();
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
                            samochody[nr_sam - 1].przejedz(temp_double);
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
                            samochody[nr_sam - 1].in_pasazer(miejsce);
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
                            samochody[nr_sam - 1].out_pasazer(miejsce);
                        }
                            break;
                        case 15:
                            samochody[nr_sam - 1].out_all_pasazer();
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
                            samochody[nr_sam - 1].usun_pasazer(miejsce);
                        }
                            break;
                        case 17:
                            samochody[nr_sam - 1].usun_all_pasazer();
                            break;
                        case 18:
                            samochody[nr_sam - 1].open_bagaznik();
                            break;
                        case 19:
                            samochody[nr_sam - 1].close_bagaznik();
                            break;
                        case 20:
                            samochody[nr_sam - 1].zaladuj_bagaznik();
                            break;
                        case 21:
                            samochody[nr_sam - 1].rozladuj_bagaznik();
                            break;
                        case 22:
                            zakoncz = true;
                            break;
                    }
                }
                break;
            case 3://radiowoz

                cout << "Lista dostępnych radiowozów:" << endl;
                cout << "   Marka:                Model:                Rocznik:" << endl;
            {
                int j = 0;
                for (auto i = radiowozy.begin(); i != radiowozy.end(); i++) {
                    j++;
                    cout << j << ". ";
                    cout.width(22);
                    cout << left;
                    cout << i->get_marka();
                    cout.width(22);
                    cout << left;
                    cout << i->get_model();
                    cout.width(16);
                    cout << i->get__rocznik() << endl;
                }
            }
                if (radiowozy.begin() == radiowozy.end()) {
                    cout << "Nie ma dostępnych żadnych radiowozów!" << endl;
                }

                while (true) {
                    cout << "Podaj numer radiowozu którym chcesz zarządzać lub wpisz 0 aby dodać nowy radiowoz" << endl;
                    if (wczytaj_double(temp_double)) {
                        if (temp_double >= 0 and temp_double <= licznik_rad and(temp_double - int(temp_double)) == 0) {
                            nr_rad = temp_double;
                            break;
                        } else {
                            cout << "Proszę podać liczbę całkowitą większa lub równą zero z odpowiedniego zakresu" << endl;
                        }
                    }
                }
                if (nr_rad == 0) {
                    {
                        radiowoz temp_rad;
                        radiowozy.push_back(temp_rad);
                    }
                    nr_rad = licznik_rad + 1;
                    t_str = plik_rad + to_string((int) (nr_rad)) + ".txt";

                    ofstream fout_rad;
                    vfout_rad.push_back(move(fout_rad));
                    vfout_rad[licznik_rad].open(t_str.c_str());

                    ifstream fin_rad;
                    vfin_rad.push_back(move(fin_rad));
                    vfin_rad[licznik_rad].open(t_str.c_str());

                    licznik_rad++;


                } else {
                    cout << "Wybrano radiowóz nr." << nr_rad << endl;
                }

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

                            cin >> radiowozy[nr_rad - 1];
                            break;
                        case 2:
                            cout << radiowozy[nr_rad - 1];
                            break;
                        case 3:
                            vfin_rad[nr_rad - 1] >> radiowozy[nr_rad - 1];
                            break;
                        case 4:
                            vfout_rad[nr_rad - 1] << radiowozy[nr_rad - 1];
                            break;
                        case 5:
                            radiowozy[nr_rad - 1].in_kierowca();
                            break;
                        case 6:
                            radiowozy[nr_rad - 1].out_kierowca();
                            break;
                        case 7:
                            radiowozy[nr_rad - 1].usun_kierowca();
                            break;
                        case 8:
                            radiowozy[nr_rad - 1].in_bak();
                            break;
                        case 9:
                            radiowozy[nr_rad - 1].out_bak();
                            break;
                        case 10:
                            radiowozy[nr_rad - 1].on_silnik();
                            break;
                        case 11:
                            radiowozy[nr_rad - 1].off_silnik();
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
                            radiowozy[nr_rad - 1].przejedz(temp_double);
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
                            radiowozy[nr_rad - 1].in_pasazer(miejsce);
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
                            radiowozy[nr_rad - 1].out_pasazer(miejsce);
                        }
                            break;
                        case 15:
                            radiowozy[nr_rad - 1].out_all_pasazer();
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
                            radiowozy[nr_rad - 1].usun_pasazer(miejsce);
                        }
                            break;
                        case 17:
                            radiowozy[nr_rad - 1].usun_all_pasazer();
                            break;
                        case 18:
                            radiowozy[nr_rad - 1].open_bagaznik();
                            break;
                        case 19:
                            radiowozy[nr_rad - 1].close_bagaznik();
                            break;
                        case 20:
                            radiowozy[nr_rad - 1].zaladuj_bagaznik();
                            break;
                        case 21:
                            radiowozy[nr_rad - 1].rozladuj_bagaznik();
                            break;
                        case 22:
                            radiowozy[nr_rad - 1].on_dzwiek();
                            break;
                        case 23:
                            radiowozy[nr_rad - 1].off_dzwiek();
                            break;
                        case 24:
                            radiowozy[nr_rad - 1].on_swiatlo();
                            break;
                        case 25:
                            radiowozy[nr_rad - 1].off_swiatlo();
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
                            radiowozy[nr_rad - 1].zatrzymaj(miejsce, imie, nazwisko, wiek);
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
                            radiowozy[nr_rad - 1].zwolnij(miejsce);
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
                            radiowozy[nr_rad - 1].out_zatrzymani(miejsce);
                        }
                            break;
                        case 29:
                            radiowozy[nr_rad - 1].out_all_zatrzymani();
                            break;
                        case 30:
                            zakoncz = true;
                            break;
                    }
                }
                break;
        }
    }




    cout << "Koniec main" << endl;
    return 0;
}


