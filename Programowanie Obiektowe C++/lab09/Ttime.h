#ifndef LAB09_TTIME_H
#define LAB09_TTIME_H

#include <iostream>

using namespace std;

class Ttime {
    int godziny;
    int minuty;

public:
    Ttime();
    Ttime(int godziny, int minuty);
    ~Ttime();

    void wyswietl();

    Ttime operator+(Ttime czas);
    Ttime operator-(Ttime czas);
    friend Ttime operator*(Ttime czas, int n);
    friend bool operator==(Ttime &czas, Ttime &czas2);

    friend ostream & operator<< (ostream &wyjscie, const Ttime &czas);

};

#endif //LAB09_TTIME_H
