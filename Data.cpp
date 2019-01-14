//
// Created by slash on 22.10.2018.
//
#pragma once;
#include "Data.h"
#include <iostream>
using namespace std;


Data::Data(int d, int m, int r) {
    m_nDzien=d;
    m_nMiesiac=m;
    m_nRok=r;
}


Data::~Data()
{
}

void Data::Ustaw(int d, int m, int r)
{
    m_nDzien=d;
    m_nMiesiac=m;
    m_nRok = r;
    Koryguj();
}

int Data::Dzien() const
{
    return m_nDzien;
}

int Data::Miesiac() const
{
    return m_nMiesiac;
}

int Data::Rok() const
{
    return m_nRok;
}

void Data::Wypisz() const
{
    cout << m_nDzien << "-" << m_nMiesiac << "-" << m_nRok << endl;

}

void Data::Wpisz()
{
    cout << "Podaj dzien:  ";
    cin >> m_nDzien;
    cout << endl << "Podaj miesiac: ";
    cin >> m_nMiesiac;
    cout << endl << "Podaj rok: ";
    cin >> m_nRok;

}

int Data::Porownaj(const Data & wzor) const
{
    int i = -2;
    if (wzor.m_nDzien == this->m_nDzien && wzor.m_nMiesiac == this->m_nMiesiac && wzor.m_nRok == this->m_nRok)
        i = 0;
    else if (wzor.m_nRok > this->m_nRok || wzor.m_nRok == this->m_nRok && wzor.m_nMiesiac > this->m_nMiesiac || wzor.m_nRok == this->m_nRok && wzor.m_nMiesiac == this->m_nMiesiac && wzor.m_nDzien > this->m_nDzien)
        i = 1;
    else i=-1;
    return i;
}

void Data::Koryguj()
{
    if (m_nDzien < 1)
        m_nDzien = 1;
    if (m_nMiesiac < 1)
        m_nMiesiac = 1;
    if (m_nMiesiac > 12)
        m_nMiesiac = 12;
    if (m_nRok < 1)
        m_nRok = 1;
    if (m_nMiesiac == 2)
    {
        if ( (m_nRok % 4 == 0 && m_nRok % 100 != 0) || m_nRok % 400 == 0)
        {
            if (m_nDzien > 29)
                m_nDzien = 29;

        }
        else if (m_nDzien > 28)
            m_nDzien = 28;
    }
    else if ((m_nMiesiac == 1 || m_nMiesiac == 3 || m_nMiesiac == 5 || m_nMiesiac == 7 || m_nMiesiac == 8 || m_nMiesiac == 10 || m_nMiesiac == 12) && m_nDzien > 31)
        m_nDzien = 31;
    else if (m_nDzien>30)
    {
        m_nDzien = 30;
    }
}

ostream& operator<<(ostream &wy, const Data & d)
{
    return wy<<d.m_nDzien<<'\t'<<d.m_nMiesiac<<'\t'<<d.m_nRok;
}

istream& operator>>(istream &we, Data &d)
{
    we>>d.m_nDzien>>d.m_nMiesiac>>d.m_nRok;
    d.Koryguj();
    return we;
}