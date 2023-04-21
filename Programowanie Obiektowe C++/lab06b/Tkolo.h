#ifndef LAB06B_TKOLO_H
#define LAB06B_TKOLO_H

#include "Ifigura.h"

#include <string>

using namespace std;

class Tkolo : public Ifigura{
    string nazwa;
    float promien;

protected:
    void info();
    void rysuj();
    float pole();
    float obwod();

public:
    Tkolo(string nazwa = "Kolko", float promien=3.0);
    ~Tkolo();

    virtual void wyswietl();

};

#endif //LAB06B_TKOLO_H
