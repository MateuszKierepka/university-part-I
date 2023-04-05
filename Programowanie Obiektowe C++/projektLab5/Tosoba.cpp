#include "Tosoba.h"
#include <iostream>

using namespace std;

Tosoba::Tosoba() {
    cout<<"Utworzono obiekt klasy <Tosoba> konstruktorem <bez parametrow>\n";
}

Tosoba::~Tosoba() {
    cout<<"Usunieto obiekt klasy <Tosoba>\n";
}

Tosoba::Tosoba(string imie, string nazwisko) {
    this->imie=imie;
    this->nazwisko=nazwisko;
    cout<<"Utworzono obiekt klasy <Tosoba> konstruktorem <z parametrami>\n";
}

void Tosoba::wczytaj() {
    cout<<"Podaj imie i nazwisko : \n";
    cin>>imie>>nazwisko;
}

void Tosoba::wyswietl() {
    cout<<"Imie : "<<imie<<endl;
    cout<<"Nazwisko : "<<nazwisko<<endl;
}
