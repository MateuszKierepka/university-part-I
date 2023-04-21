#include "Tprostokat.h"

#include <iostream>

using namespace std;

Tprostokat::Tprostokat(string nazwa, float a, float b) {
    cout<<"Konstruktor klasy <Tprostokat> z parametrami"<<endl;
    this->nazwa=nazwa; this->a=a; this->b=b;
}

Tprostokat::~Tprostokat() {
    cout<<"Destruktor klasy <Tprostokat>"<<endl;
}

void Tprostokat::info() {
    cout<<"Nazwa : "<<nazwa<<endl;
}

void Tprostokat::rysuj() {
    cout<<"Rysuje <"<<nazwa<<">"<<endl;
}

float Tprostokat::pole() {
    return a*b;
}

float Tprostokat::obwod() {
    return 2*(a+b);
}

void Tprostokat::wyswietl() {
    info();
    rysuj();
    cout<<"Pole prostokata wynosi : "<<pole()<<endl;
    cout<<"Obwod prostokata wynosi : "<<obwod()<<endl;
}