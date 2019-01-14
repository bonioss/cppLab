//
// Created by slash on 05.11.2018.
//

#include "Napis.h"
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
using namespace std;

Napis::Napis(const char *nap):m_nDl(strlen(nap)) {
    m_pszNapis = new char[m_nDl];
    strcmp(m_pszNapis, nap);
}


Napis::~Napis()
{
    delete[](m_pszNapis);
    m_pszNapis=nullptr;
}

const char * Napis::Zwroc() const
{
    return this->m_pszNapis ;
}

void Napis::Ustaw(const char * nowy_napis)
{
    strncpy(this->m_pszNapis, nowy_napis, 40);
}

void Napis::Wypisz() const
{


    cout << m_pszNapis;


}

void Napis::Wpisz() {
    cin >> m_pszNapis;
}

int Napis::SprawdzNapis(const char *por_napis) const {
    return strcmp(m_pszNapis, por_napis);
}

Napis::Napis(const Napis &wzor) {
    m_nDl=wzor.m_nDl;
    m_pszNapis = new char[m_nDl+1];
    m_pszNapis=wzor.m_pszNapis;
    strcpy(m_pszNapis,wzor.m_pszNapis);
}

Napis &Napis::operator=(const Napis &wzor) {
    if (this != &wzor)
    {
        m_nDl = wzor.m_nDl;
        delete[]m_pszNapis;
        m_pszNapis = new char[m_nDl+ 1];
        strcpy(m_pszNapis, wzor.m_pszNapis);
    }
    return *this;
}

bool Napis::operator==(const Napis *wzor) const {
    return !SprawdzNapis(wzor->m_pszNapis);
}

ostream &operator<<(ostream &wy, const Napis &p) {
    return wy << p.m_nDl << '\n' << p.m_pszNapis;
}

istream &operator>>(istream &we, Napis &p) {
    return we >> p.m_nDl >> p.m_pszNapis;
}


