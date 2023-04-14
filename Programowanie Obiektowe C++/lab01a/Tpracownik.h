#ifndef TPRACOWNIK_TPRACOWNIK_H
#define TPRACOWNIK_TPRACOWNIK_H

struct Tdata{
    int dzien, miesiac, rok;
};

class Tpracownik
{
private:
    char imie[20], nazwisko[20];
    float stawka;
    int liczba_godzin;
    Tdata dataZatrudnienia;
public:
    void wczytaj();
    float placa();
    void wyswietl();
};

#endif //TPRACOWNIK_TPRACOWNIK_H
