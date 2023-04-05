#ifndef PROJEKTLAB5_TPRACU_H
#define PROJEKTLAB5_TPRACU_H
#include <string>

#include "Tpracownik.h"

using namespace std;

class TpracU : private Tpracownik {
public:
    TpracU();
    TpracU(string imie, string nazwisko, string firma, int stawka, int premia);
    ~TpracU();
    void wyswietl();
protected:
    int wynagrodzenie;
};


#endif //PROJEKTLAB5_TPRACU_H
