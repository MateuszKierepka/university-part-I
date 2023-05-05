#ifndef KOLOKWIUM_TWYMIANA_H
#define KOLOKWIUM_TWYMIANA_H

#include <string>

using namespace std;

struct Tdata{
    int dzien, miesiac, rok;
};

struct Tgodzina{
    int godzina, minuta;
};

class Twymiana {
    Tdata data;
    Tgodzina godzina;
    string nr_rejestracyjny;
    string opis;

public:
    Twymiana();
    ~Twymiana();

    void wczytaj();
    void wyswietl();
};

#endif //KOLOKWIUM_TWYMIANA_H
