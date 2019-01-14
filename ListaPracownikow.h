//
// Created by slash on 19.11.2018.
//

#ifndef STUDIA1_LISTAPRACOWNIKOW_H
#define STUDIA1_LISTAPRACOWNIKOW_H

#include "Pracownik.h"


class ListaPracownikow {
    Pracownik *m_pPoczatek;
    int m_nLiczbaPracownikow;

public:
    ListaPracownikow();
    ~ListaPracownikow();
    void Dodaj (const Pracownik &p);
    void WypiszPracownikow()const;
    void Usun(const Pracownik & wzorzec);
    const Pracownik * Szukaj(const char * nazwisko, const char * imie) const;
    void WczytajZPliku();
    void ZapisDoPliku();

};
#endif //STUDIA1_LISTAPRACOWNIKOW_H
