#include "Ttime.h"

#include <iostream>

using namespace std;

Ttime::Ttime() {
    //konstruktor
}

Ttime::Ttime(int godziny, int minuty) {
    while (minuty >= 60){
        godziny++;
        minuty -= 60;
    }
    this->godziny=godziny;
    this->minuty=minuty;
}

Ttime::~Ttime() {
    //destruktor
}

void Ttime::wyswietl() {
    cout<<godziny<<"h "<<minuty<<"min "<<endl;
}

Ttime Ttime::operator+(Ttime czas) {
    Ttime suma(0, 0);
    suma.minuty = czas.minuty + minuty;
    while (suma.minuty >= 60){
        suma.godziny++;
        suma.minuty -= 60;
    }
    suma.godziny += czas.godziny + godziny;
    return suma;
}

Ttime Ttime::operator-(Ttime czas) {
    Ttime roznica(0, 0);
    if(godziny > czas.godziny) {
        roznica.godziny = godziny - czas.godziny;
        roznica.minuty = minuty - czas.minuty;
        while (roznica.minuty < 0) {
            roznica.godziny--;
            roznica.minuty += 60;
        }
    }
    else{
        roznica.godziny = czas.godziny - godziny;
        roznica.minuty = czas.minuty - minuty;
        while (roznica.minuty < 0) {
            roznica.godziny--;
            roznica.minuty += 60;
        }
    }
    return roznica;
}

ostream & operator<<(ostream &wyjscie, const Ttime &czas){
    return wyjscie<<czas.godziny<<"h "<<czas.minuty<<"min ";
}

Ttime operator*(Ttime czas, int n){
    Ttime iloraz(0, 0);
    iloraz.minuty = czas.minuty * n;
    iloraz.godziny = czas.godziny * n;
    while(iloraz.minuty >= 60){
        iloraz.godziny++;
        iloraz.minuty -= 60;
    }
    return Ttime(iloraz.godziny, iloraz.minuty);
}

bool operator==(Ttime &czas, Ttime &czas2){
    return (czas.godziny == czas2.godziny && czas.minuty == czas2.minuty);
}