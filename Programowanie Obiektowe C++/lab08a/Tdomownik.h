#ifndef LAB08_TDOMOWNIK_H
#define LAB08_TDOMOWNIK_H

#include <string>

using namespace std;

class Tdomownik {
    string nazwa, sekret;
    static int kod;

public:
    Tdomownik();
    Tdomownik(string nazwa);
    ~Tdomownik();
    static void setkod();
    static int getkod();

    void wyswietl();

    friend string sasiad(Tdomownik *wsk);
    friend class Tsasiad;
};


class Tsasiad {
    string nazwa;

public:
    Tsasiad();
    Tsasiad(string nazwa);
    ~Tsasiad();

    void info(Tdomownik* domownik);
};

#endif //LAB08_TDOMOWNIK_H
