#ifndef LAB04_TOSOBA2_H
#define LAB04_TOSOBA2_H
#include <string>
#include "Tdata.h"

using namespace std;

class Tosoba2 {
private:
    string nazwisko, imie, motto;

public:
    Tdata dataUr;
    Tosoba2(); // kontruktor domyślny
    Tosoba2(string nazwisko, string imie, Tdata d); // motto zdefiniowane wewnątrz konstruktora
    ~Tosoba2();
    void wczytaj();
    void wyswietl();
    string getNazwiskoImie();
    int roznicaWieku(Tosoba2 &partner); // referencja
    Tosoba2 dluzszeNazwisko(Tosoba2 &partner); // referencja
};


#endif //LAB04_TOSOBA2_H
