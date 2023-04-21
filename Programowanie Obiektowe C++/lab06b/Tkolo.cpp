#include "Tkolo.h"

#include <iostream>
#include <cmath>

using namespace std;

Tkolo::Tkolo(string nazwa, float promien) {
    cout<<"Konstruktor klasy <Tkolo> z parametrem"<<endl;
    this->nazwa=nazwa;
    this->promien=promien;
}

Tkolo::~Tkolo() {
    cout<<"Destruktor klasy <Tkolo>"<<endl;
}

void Tkolo::info() {
    cout<<"Nazwa : "<<nazwa<<endl;
}

void Tkolo::rysuj() {
    cout<<"Rysuje <"<<nazwa<<">"<<endl;
}

float Tkolo::pole() {
    return M_PI*promien*promien;
}

float Tkolo::obwod() {
    return 2*M_PI*promien;
}

void Tkolo::wyswietl() {
    info();
    rysuj();
    cout<<"Pole kola wynosi : "<<pole()<<endl;
    cout<<"Obwod kola wynosi : "<<obwod()<<endl;
}