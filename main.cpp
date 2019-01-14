#include <iostream>
#include "Data.h"
#include "Napis.h"
#include "Pracownik.h"
#include "ListaPracownikow.h"

using namespace std;

int main() {
    ListaPracownikow lista;
    Pracownik* nowy;
    Napis imie, nazwisko;
    char s;
    while (1)
    {
        cout << "1 - dodanie nowego pracownika" << endl;
        cout << "2 - usuniecie pracownika" << endl;
        cout << "3 - wyswietlenie listy" << endl;
        cout << "4 - wyszukanie pracownika" << endl;
        cout << "5 - wczytaj liste" << endl;
        cout << "6 - zapisz liste" << endl;
        cout << "0 - wyjscie z programu" << endl;
        cin >> s;
        switch (s)
        {
            case '1':
                cin.clear();
                nowy = new Pracownik;
                nowy->Wpisz();
                lista.Dodaj(*nowy);
                break;
            case '2':
            {
                nowy = new Pracownik;
                nowy->Wpisz();
                lista.Usun(*nowy);
                break;
            }
            case '3':
            {
                lista.WypiszPracownikow();
                break;
            }
            case '4':
            {
                cout << "Podaj imie i nazwisko szukanego pracownika" << endl;
                cout << "Imie: ";
                imie.Wpisz();
                cout << "Nazwisko: ";
                nazwisko.Wpisz();
                cout << endl;
                lista.Szukaj(nazwisko.Zwroc(), imie.Zwroc());
                break;
            }
            case '5':
            {
                lista.ZapisDoPliku();
                break;
            }
            case '6':
            {
                lista.WczytajZPliku();
                break;
            }
            case '0'://quuuuiiit
                return 0;
                //break;
            default:
            {
                break;
            }

        }
    }


}

