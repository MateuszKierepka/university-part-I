#ifndef LAB07_TTOWAR_H
#define LAB07_TTOWAR_H

#include <string>

using namespace std;

class Ttowar {
    string nazwa;
    float cena;
    int ilosc;

public:
    Ttowar();
    Ttowar(const string &nazwa, float cena, int ilosc);

    void wczytaj();
    void wyswietl();
    float oblicz();
};


#endif //LAB07_TTOWAR_H
