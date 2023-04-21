#ifndef POLIMORFIZM_TKWADRAT_H
#define POLIMORFIZM_TKWADRAT_H

#include "Tprostokat.h"

class Tkwadrat :public Tprostokat{
protected:
    float a;
    virtual float pole();
    virtual float obwod();

public:
    Tkwadrat();
    Tkwadrat(float a);
    ~Tkwadrat();
};

#endif //POLIMORFIZM_TKWADRAT_H
