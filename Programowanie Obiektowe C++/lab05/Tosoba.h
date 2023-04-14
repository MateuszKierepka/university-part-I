#ifndef PROJEKTLAB5_TOSOBA_H
#define PROJEKTLAB5_TOSOBA_H
#include <string>

using namespace std;

class Tosoba {
public:
    Tosoba();
    Tosoba(string imie, string nazwisko);
    ~Tosoba();
    void wczytaj();
    void wyswietl();
protected:
    string imie;
    string nazwisko;
};

#endif //PROJEKTLAB5_TOSOBA_H
