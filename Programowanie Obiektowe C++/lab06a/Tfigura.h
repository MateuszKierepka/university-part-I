#ifndef POLIMORFIZM_TFIGURA_H
#define POLIMORFIZM_TFIGURA_H

#include <string>

using namespace std;

class Tfigura {

protected:
    string nazwa;
    void info();
    void rysuj();
    virtual float pole();
    virtual float obwod();

public:
    Tfigura();
    ~Tfigura();

    void wyswietl();

};

#endif //POLIMORFIZM_TFIGURA_H
