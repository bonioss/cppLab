//
// Created by slash on 22.10.2018.
//

#ifndef STUDIA1_DATA_H
#define STUDIA1_DATA_H
#pragma once

#include <iostream>
using namespace std;
class Data {


private:
    int m_nDzien;
    int m_nMiesiac;
    int m_nRok;

public:
    Data(int d, int m, int r);
    ~Data();
    void Wypisz() const;
    void Ustaw (int d, int m, int r);
    int Dzien() const;
    int Miesiac() const;
    int Rok() const;
    void Wpisz();
    int Porownaj(const Data &wzor) const;
    friend ostream& operator<<(ostream &wy, const Data &d);
    friend istream& operator>>(istream &we, Data &d);
private:
    void Koryguj();

};


#endif //STUDIA1_DATA_H
