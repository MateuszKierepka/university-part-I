#ifndef POLIMORFIZM_TPROSTOKAT_H
#define POLIMORFIZM_TPROSTOKAT_H

#include "Tfigura.h"

class Tprostokat :public Tfigura{
protected:
    float a, b;
    virtual float pole();
    virtual float obwod();

public:
    Tprostokat();
    Tprostokat(float a, float b);
    ~Tprostokat();
};

#endif //POLIMORFIZM_TPROSTOKAT_H
