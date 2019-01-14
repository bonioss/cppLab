//
// Created by slash on 05.11.2018.
//

#include "Pracownik.h"
#include "Data.h"
#include <iostream>
using namespace std;


Pracownik::~Pracownik() {

}

const char *Pracownik::Imie() const {
    return m_Imie.Zwroc();
}

const char *Pracownik::Nazwisko() const {
    return m_Nazwisko.Zwroc();
}

void Pracownik::Imie(const char *nowe_imie) {
    m_Imie.Ustaw(nowe_imie);

}

void Pracownik::Nazwisko(const char *nowe_nazwisko) {
    m_Nazwisko.Ustaw(nowe_nazwisko);

}

void Pracownik::DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok) {
m_DataUrodzenia.Ustaw(nowy_dzien,nowy_miesiac,nowy_rok);
}

void Pracownik::Wypisz() const {
    m_Imie.Wypisz();
    cout<<"\t";
    m_Nazwisko.Wypisz();
    cout<<"\t";
    m_DataUrodzenia.Wypisz();

}

void Pracownik::Wpisz() {
    cout << "Podaj imie: ";
    m_Imie.Wpisz();
    cout << "Podaj nazwisko: ";
    m_Nazwisko.Wpisz();
    m_DataUrodzenia.Wpisz();

}

int Pracownik::SprawdzImie(const char *por_imie) const {
    return m_Imie.SprawdzNapis(por_imie);
}

int Pracownik::SprawdzNazwisko(const char *por_nazwisko) const {
    return m_Nazwisko.SprawdzNapis(por_nazwisko);

}

int Pracownik::Porownaj(const Pracownik &wzorzec) const
{
    int i=-1;
    if(wzorzec.SprawdzImie(
            m_Imie.Zwroc())==0 &&
            wzorzec.SprawdzNazwisko(
                    m_Nazwisko.Zwroc())==0&&
            m_DataUrodzenia.Porownaj(
                    wzorzec.m_DataUrodzenia)==0 )
    {
        i=0;
    }
    else if (wzorzec.SprawdzImie(m_Imie.Zwroc())>0 || wzorzec.SprawdzImie(m_Imie.Zwroc())==0&&wzorzec.SprawdzNazwisko(m_Nazwisko.Zwroc())>0||wzorzec.SprawdzImie(m_Imie.Zwroc())==0&&wzorzec.SprawdzNazwisko(m_Nazwisko.Zwroc())==0&&m_DataUrodzenia.Porownaj(wzorzec.m_DataUrodzenia)>0 )
    {
        i=1;
    }
    else return i;
}

int Pracownik::ID;

Pracownik::Pracownik(const char *im, const char *naz, int dzien, int miesiac, int rok):m_Imie(im), m_Nazwisko(naz), m_nIDZatrudnienia(ID++), m_DataUrodzenia(dzien, miesiac, rok) {

}

Pracownik::Pracownik(const Pracownik &wzor):m_nIDZatrudnienia(ID+1), m_Imie(wzor.m_Imie), m_Nazwisko(wzor.m_Nazwisko), m_DataUrodzenia(wzor.m_DataUrodzenia){

}

Pracownik &Pracownik::operator=(const Pracownik &wzor) {
    if(this != &wzor)
    {
        m_DataUrodzenia=wzor.m_DataUrodzenia;
        m_Imie=wzor.m_Imie;
        m_Nazwisko=wzor.m_Nazwisko;
    }
    return *this;
}

bool Pracownik::operator==(const Pracownik &wzor) {
    int pom=this->Porownaj(wzor);
    if(pom==0)
    return true;
    else
        return false;

}

ostream & operator<<(ostream &wy, const Pracownik &p) {
     return wy << p.m_Imie << endl << p.m_Nazwisko << endl << p.m_DataUrodzenia;
}

istream & operator >>(istream &we, Pracownik &p){
    return we >> p.m_Imie >> p.m_Nazwisko >> p.m_DataUrodzenia;
}

void Pracownik::WypiszDane() {
    m_Imie.Wypisz();
    cout << '\t';
    m_Nazwisko.Wypisz();
    cout << '\t';
    m_DataUrodzenia.Wypisz();
}

Pracownik *Pracownik::KopiaObiektu() {
    Pracownik* nowyPracownik;
    nowyPracownik = new Pracownik(*this);
    return nowyPracownik;
}



