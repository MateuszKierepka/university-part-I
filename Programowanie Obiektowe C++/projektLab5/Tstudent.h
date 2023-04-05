#ifndef PROJEKTLAB5_TSTUDENT_H
#define PROJEKTLAB5_TSTUDENT_H
#include <string>
#include <vector>

#include "Tosoba.h"

using namespace std;

class Tstudent : protected Tosoba {
public:
    Tstudent();
    Tstudent(string imie, string nazwisko, string uczelnia, vector <float> oceny);
    ~Tstudent();
    void wczytaj();
    void wyswietl();
    float sredniaOcen();
    bool czyZdane();
protected:
    string uczelnia;
    int liczba_ocen;
    vector <float> oceny;
};

#endif //PROJEKTLAB5_TSTUDENT_H
