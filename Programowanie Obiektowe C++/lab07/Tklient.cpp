#include "Tklient.h"

#include <iostream>

using namespace std;

Tklient::Tklient(const string &imie, const string &nazwisko) {
    this->imie=imie;
    this->nazwisko=nazwisko;
}

void Tklient::wyswietl() {
    cout<<imie<<" "<<nazwisko<<endl;
}
