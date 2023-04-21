#ifndef LAB06B_TKWADRAT_H
#define LAB06B_TKWADRAT_H

#include "Ifigura.h"

#include <string>

using namespace std;

class Tkwadrat :public Ifigura{
    string nazwa;
    float a;

protected:
    void info();
    void rysuj();
    float pole();
    float obwod();

public:
    Tkwadrat(string nazwa="Kwadracik", float a=5.0);
    ~Tkwadrat();

    virtual void wyswietl();
};

#endif //LAB06B_TKWADRAT_H
