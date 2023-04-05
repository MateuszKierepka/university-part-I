#ifndef PROJEKTLAB5_TPRACF_H
#define PROJEKTLAB5_TPRACF_H
#include <string>

#include "Tpracownik.h"

using namespace std;

class TpracF : private Tpracownik {
public:
    TpracF();
    TpracF(string imie, string nazwisko, string firma, int stawka, int premia);
    ~TpracF();
    void zarobki();
    void wyswietl();
protected:
    int stawka;
};


#endif //PROJEKTLAB5_TPRACF_H
