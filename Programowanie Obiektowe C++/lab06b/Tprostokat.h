#ifndef LAB06B_TPROSTOKAT_H
#define LAB06B_TPROSTOKAT_H

#include "Ifigura.h"

#include <string>

using namespace std;

class Tprostokat :public Ifigura{
    string nazwa;
    float b;

protected:
    float a;
    void info();
    void rysuj();
    float pole();
    float obwod();

public:
    Tprostokat(string nazwa="Prostokat", float a=2.0, float b=4.0);
    ~Tprostokat();

    virtual void wyswietl();
};

#endif //LAB06B_TPROSTOKAT_H
