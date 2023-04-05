#ifndef PROJEKTLAB5_TPRACOWNIK_H
#define PROJEKTLAB5_TPRACOWNIK_H
#include <string>

#include "Tosoba.h"

using namespace std;

class Tpracownik : protected Tosoba {
public:
    Tpracownik();
    Tpracownik(string imie,string nazwisko, string firma);
    ~Tpracownik();
    void wyswietl();
protected:
    string firma;
    int premia;
};


#endif //PROJEKTLAB5_TPRACOWNIK_H
