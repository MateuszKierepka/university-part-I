#ifndef LAB07_TFAKTURA_H
#define LAB07_TFAKTURA_H

#include "Tdokument.h"
#include "Tklient.h"
#include "Ttowar.h"

class Tfaktura :public Tdokument{ //specjalizacja(dziedziczenie)
    Tklient* klient; //(asocjacja) pole wskaznikowe
    Ttowar* towary; //(agregacja) tablica obiektow
    int liczTowary;
    float wartosc;

public:
    Tfaktura(Tklient *klient, Tdata data, const string &nazwa, const string &numer);
    ~Tfaktura();

    void wczytaj();
    virtual void wyswietl();
};

#endif //LAB07_TFAKTURA_H
