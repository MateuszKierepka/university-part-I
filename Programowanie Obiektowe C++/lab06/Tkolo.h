#ifndef POLIMORFIZM_TKOLO_H
#define POLIMORFIZM_TKOLO_H

#include "Tfigura.h"

class Tkolo :public Tfigura{
protected:
    float promien;
    virtual float pole();
    virtual float obwod();

public:
    Tkolo();
    Tkolo(float promien);
    ~Tkolo();
};

#endif //POLIMORFIZM_TKOLO_H
