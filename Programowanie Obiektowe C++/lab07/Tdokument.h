#ifndef LAB07_TDOKUMENT_H
#define LAB07_TDOKUMENT_H
#include <string>

using namespace std;

struct Tdata{
    int dzien, miesiac, rok;
};

class Tdokument {
protected:
    string numer;
    string nazwa;
    Tdata data;

public:
    Tdokument(const string &numer, const string &nazwa, Tdata data);

    virtual void wyswietl();
};

#endif //LAB07_TDOKUMENT_H


