#ifndef TOSOBA2_TOSOBA2_H
#define TOSOBA2_TOSOBA2_H
#include "Tdata.h"
#include <string>

using namespace std;

class Tosoba2 {
private:
    string nazwisko;
    string imie;
    string motto;
    Tdata dataUr;
public:
    Tosoba2(); // konstruktor domyslny
    Tosoba2(string nazwisko, string imie, Tdata d); // motto zdefiniowane wewnatrz
    ~Tosoba2(); //destruktor
    void wczytaj();
    void wyswietl();
    string getNazwiskoImie();
    int roznicaWieku(Tosoba2 &partner);
    Tosoba2 dluzszeNazwisko(Tosoba2 &partner);
};


#endif //TOSOBA2_TOSOBA2_H
