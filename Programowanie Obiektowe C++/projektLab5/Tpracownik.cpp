#include "Tpracownik.h"
#include <iostream>

using namespace std;

Tpracownik::Tpracownik() {
    cout<<"Utworzono obiekt klasy <Tpracownik> kontruktorem <bez parametrow>\n";
}

Tpracownik::Tpracownik(string imie, string nazwisko, string firma) {
    this->imie=imie;
    this->nazwisko=nazwisko;
    this->firma=firma;
    cout<<"Utworzono obiekt klasy <Tstudent> konstruktorem <z parametrami>\n";
}

Tpracownik::~Tpracownik() {
    cout<<"Usunieto obiekt klasy <Tpracownik>\n";
}

void Tpracownik::wyswietl() {
    Tosoba::wyswietl();
    cout<<"Dane pracownika : \n";
    cout<<"Firma : "<<firma<<endl;
}