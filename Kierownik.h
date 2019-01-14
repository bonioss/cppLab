//
// Created by slash on 12.01.2019.
//

#ifndef STUDIA1_KIEROWNIK_H
#define STUDIA1_KIEROWNIK_H


#include "Pracownik.h"

class Kierownik:public Pracownik {
    Napis m_NazwaDzialu;
    int m_nLiczbaPracownikow;
public:
    Kierownik();
    Kierownik(const Kierownik& wzor);
    ~Kierownik();
    Kierownik &operator=(const Kierownik& wzor);
    bool operator==(const Kierownik& wzor)const;
    virtual void WypiszDane();
    virtual Pracownik* KopiaObiektu();
    friend ostream &operator<<(ostream& wy, const Kierownik &wzor);
    friend istream &operator >> (istream& we, Kierownik &wzor);

};


#endif //STUDIA1_KIEROWNIK_H
