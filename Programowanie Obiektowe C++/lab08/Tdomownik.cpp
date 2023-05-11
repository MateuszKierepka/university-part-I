#include "Tdomownik.h"

#include <iostream>

using namespace std;

int Tdomownik::kod;

Tdomownik::Tdomownik() {
    //konstruktor domyslny
}

Tdomownik::Tdomownik(std::string nazwa) {
    this->nazwa=nazwa;
    ::fflush(stdin);
    cout<<"Podaj sekret : "<<endl;
    getline(cin, sekret);
}

Tdomownik::~Tdomownik() {
    //destruktor
}

void Tdomownik::setkod() {
    cout<<"Podaj kod : "<<endl; cin>>kod;
}

int Tdomownik::getkod() {
    return kod;
}

void Tdomownik::wyswietl() {
    cout<<"Nazwa : "<<nazwa<<endl;
    cout<<"Sekret : "<<sekret<<endl;
}


Tsasiad::Tsasiad() {
//konstruktor
}

Tsasiad::~Tsasiad() {
    //destruktor
}

void Tsasiad::info(Tdomownik* domownik) {
    cout<<"Ja sasiad "<<nazwa<<" znam sekret domownika "<<domownik->nazwa<<" : "<<domownik->sekret<<" i kod do ich domu : "<<domownik->kod<<endl;
}