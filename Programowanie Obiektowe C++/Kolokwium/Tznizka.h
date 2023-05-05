#ifndef KOLOKWIUM_TZNIZKA_H
#define KOLOKWIUM_TZNIZKA_H

#include "Twymiana.h"
#include "Tcennik.h"

class Tznizka :public Twymiana, Tcennik{
    int czyStalyKlient;

public:
    Tznizka();
    ~Tznizka();

    void wczytaj();
    void wyswietl();
};


#endif //KOLOKWIUM_TZNIZKA_H
