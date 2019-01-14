//
// Created by slash on 12.01.2019.
//

#include "Kierownik.h"

Kierownik::Kierownik() {
    m_NazwaDzialu = "";
    m_nLiczbaPracownikow = 0;
}

Kierownik::Kierownik(const Kierownik &wzor) {
    m_NazwaDzialu = wzor.m_NazwaDzialu;
    m_nLiczbaPracownikow = wzor.m_nLiczbaPracownikow;
}

Kierownik::~Kierownik() {

}

Kierownik &Kierownik::operator=(const Kierownik &wzor) {
    if(this != &wzor)
    {
        m_NazwaDzialu=wzor.m_NazwaDzialu;
        m_nLiczbaPracownikow=wzor.m_nLiczbaPracownikow;
    }
    return *this;
}

bool Kierownik::operator==(const Kierownik &wzor) const {
    int pom=this->Porownaj(wzor);
    if(pom==0)
        return true;
    else
        return false;
}

void Kierownik::WypiszDane() {
    m_NazwaDzialu.Wypisz();
    cout<<"\t";
    cout<<m_nLiczbaPracownikow;
}

Pracownik *Kierownik::KopiaObiektu() {
    Kierownik* nowyKierownik;
    nowyKierownik = new Kierownik(*this);
    return nowyKierownik;
}

ostream &operator<<(ostream &wy, const Kierownik &wzor) {
    return wy << wzor.m_NazwaDzialu << endl << wzor.m_nLiczbaPracownikow;
}

istream &operator>>(istream &we, Kierownik &wzor) {
    return we >> wzor.m_NazwaDzialu >> wzor.m_nLiczbaPracownikow;
}


