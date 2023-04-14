#ifndef TOSOBA2_TDATA_H
#define TOSOBA2_TDATA_H


class Tdata {
private:
    int d, m, r;
public:
    Tdata();
    Tdata(int dzien, int miesiac, int rok): d(dzien), m(miesiac), r(rok){} // kontruktor z lista inicjalizacyjna
    void wczytaj();
    void wyswietl();
    int getR();
};


#endif //TOSOBA2_TDATA_H
