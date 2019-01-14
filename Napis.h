//
// Created by slash on 05.11.2018.
//

#ifndef STUDIA1_NAPIS_H
#define STUDIA1_NAPIS_H
#include <iostream>
using namespace std;

class Napis {private:
    char* m_pszNapis;
    int m_nDl;
public:
    Napis(const char * nap = "");
    Napis(const Napis &wzor);
    ~Napis();
    const char* Zwroc() const;
    void Ustaw(const char* nowy_napis);
    void Wypisz() const;
    void Wpisz();
    int SprawdzNapis(const char* por_napis) const;
    Napis &operator=(const Napis & wzor);
    bool operator==(const Napis * wzor) const;
    friend ostream & operator<<(ostream & wy, const Napis & p);
    friend istream & operator>>(istream & we, Napis & p);

};


#endif //STUDIA1_NAPIS_H
