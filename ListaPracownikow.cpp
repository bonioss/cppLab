//
// Created by slash on 19.11.2018.
//

#include "ListaPracownikow.h"
#include <iostream>
#include <fstream>
using namespace std;

ListaPracownikow::ListaPracownikow() {
    m_pPoczatek = nullptr;
    m_nLiczbaPracownikow = 0;

}
ListaPracownikow::~ListaPracownikow()
{
    Pracownik *aktualny = m_pPoczatek;
    if (m_nLiczbaPracownikow == 0)
    {
        cout << "Lista pracownikow jest pusta!" << endl;
    }
    else
        while(aktualny != nullptr)
        {
            aktualny = aktualny->m_pNastepny;
            delete m_pPoczatek;
            m_pPoczatek = aktualny;

        }
}

void ListaPracownikow::Dodaj(const Pracownik &p) {
    Pracownik *pomoc = m_pPoczatek, *pop = nullptr;

    if (m_nLiczbaPracownikow == 0)
    {
        Pracownik *k = new Pracownik(p);
        m_pPoczatek = k;
        k->m_pNastepny = nullptr;
        m_nLiczbaPracownikow++;
        return;
    }

    else {
        while (pomoc != nullptr)
        {
            if (pomoc->Porownaj(p)>0)
            {
                Pracownik *k = new Pracownik(p);
                if (pop)
                {
                    pop->m_pNastepny = k;
                }
                else
                    m_pPoczatek = k;
                k->m_pNastepny = pomoc;
                m_nLiczbaPracownikow++;
                return;
            }
            else if (pomoc->Porownaj(p) == 0)
            {
                cout << "Obiekt juz wystepuje" << endl;
                return;
            }
            pop = pomoc;
            pomoc = pomoc->m_pNastepny;
        }
        Pracownik *k = new Pracownik(p);
        pop->m_pNastepny = k;
        k->m_pNastepny = nullptr;
        ++m_nLiczbaPracownikow;
    }


}

void ListaPracownikow::WypiszPracownikow() const {
    Pracownik *aktualny = m_pPoczatek;
    if (m_nLiczbaPracownikow == 0)
    {
        cout << "Lista pracownikow jest pusta!" << endl;
    }
    else
    {
        for (int i = 1; i <= m_nLiczbaPracownikow; i++)
        {
            cout << "Pracownik #" << i << ": ";
            aktualny->Wypisz();
            aktualny = aktualny->m_pNastepny;
        }
    }
}

void ListaPracownikow::Usun(const Pracownik &wzorzec) {
    Pracownik *aktualny = m_pPoczatek;
    Pracownik *poprzedni = nullptr;
    if (m_nLiczbaPracownikow == 0)
    {
        cout << "Lista pracownikow jest pusta" << endl;
    }
    else
    {
        for(int i=0; i<=m_nLiczbaPracownikow; i++)
        {
            if (aktualny->Porownaj(wzorzec) == 0)
            {
                if (aktualny == m_pPoczatek)
                {
                    aktualny = aktualny->m_pNastepny;
                    delete m_pPoczatek;
                    m_pPoczatek = aktualny;
                    m_nLiczbaPracownikow--;
                    return;
                }
                else
                {
                    poprzedni->m_pNastepny = aktualny->m_pNastepny;
                    delete aktualny;
                    m_nLiczbaPracownikow--;
                    return;
                }
            }
            else
            {
                poprzedni = aktualny;
                aktualny = aktualny->m_pNastepny;
            }

        }
        cout << "Nie znalezionego wzorca" << endl;
    }
}

const Pracownik * ListaPracownikow::Szukaj(const char * nazwisko, const char * imie) const
{
    Pracownik* aktualny = m_pPoczatek;
    if (m_nLiczbaPracownikow == 0)
    {
        std::cout << "Lista pracownikow jest pusta!" << std::endl;
        return NULL;
    }
    else
    {
        while(aktualny!=nullptr)
        {
            if ((aktualny->SprawdzImie(imie) == 0) && (aktualny->SprawdzNazwisko(nazwisko) == 0))
            {
                std::cout << "Znaleziono pracownika!" << std::endl;
                aktualny->Wypisz();
                return aktualny;
            }
            else
            {
                aktualny = aktualny->m_pNastepny;
            }
        }
        return NULL;
    }
}

void ListaPracownikow::WczytajZPliku() {
    ifstream plik;
    plik.open("plik.txt", fstream::in);
    if (!plik.good())
    {
        cout << "Brak pliku" << endl;
    }
    else
    {
        m_nLiczbaPracownikow = 0;
        m_pPoczatek = NULL;
        Pracownik* temp = new Pracownik();
        while (plik >> *temp)
        {
            Dodaj(*temp);
            temp = new Pracownik();
        }
    }

}

void ListaPracownikow::ZapisDoPliku() {
    ofstream plik;
    plik.open("plik.dat", fstream::out);
    if (!plik.good())
    {
        cout << "Blad otwarcia pliku" << endl;
    }
    else
    {
        Pracownik* aktualny = m_pPoczatek;
        for (int i = 0; i < m_nLiczbaPracownikow; i++)
        {
            if (aktualny != NULL)
            {
                plik << *aktualny << endl;
            }
            aktualny = aktualny->m_pNastepny;
        }
    }
    plik.close();

}



