#ifndef KOLOKWIUM_TCENNIK_H
#define KOLOKWIUM_TCENNIK_H


class Tcennik {
    int pozycja_cenowa;
    int cena;

public:
    Tcennik();
    ~Tcennik();

    void wczytaj();
    int KwotaDoZaplaty();
};


#endif //KOLOKWIUM_TCENNIK_H
