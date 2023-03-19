#ifndef LAB04_TDATA_H
#define LAB04_TDATA_H


class Tdata {
private:
    int d, m, r;
public:
    Tdata(); //konstruktor domyślny
    Tdata(int dzien, int miesiac, int rok) : d(dzien), m(miesiac), r(rok){}; // konstruktor z listą inicjalizacyjną
    void wczytaj();
    void wyswietl();
    int getR();
};


#endif //LAB04_TDATA_H
