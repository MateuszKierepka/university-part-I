#ifndef TOSOBA_TOSOBA_H
#define TOSOBA_TOSOBA_H
#include <string>

using namespace std;

struct Tdata{
    int d, m, r;
};

class Tosoba {
private:
    string imie;
    string nazwisko;
    Tdata data;

public:
    Tosoba(); //konstruktor domyślny
    Tosoba(int rok);
    ~Tosoba(); //destruktor

    void wczytaj();

    void wyswietl();
    void wyswietl(int rok);

    void info();
    void info(int rok);
};

#endif //TOSOBA_TOSOBA_H
