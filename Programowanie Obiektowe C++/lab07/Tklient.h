#ifndef LAB07_TKLIENT_H
#define LAB07_TKLIENT_H

#include <string>

using namespace std;

class Tklient {
    string imie;
    string nazwisko;

public:
    Tklient(const string &imie, const string &nazwisko);

    void wyswietl();
};

#endif //LAB07_TKLIENT_H
