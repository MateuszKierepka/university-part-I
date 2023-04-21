#include "Tfigura.h"

#include <iostream>
#include <string>

using namespace std;

Tfigura::Tfigura() {
    cout<<"Konstruktor domyslny klasy <Tfigura>"<<endl;
    nazwa="FIGURA";
}

Tfigura::~Tfigura() {
    cout<<"Destruktor klasy <Tfigura>"<<endl;
}

void Tfigura::wyswietl() {
    info();
    rysuj();
    cout<<"Pole : "<<pole()<<endl;
    cout<<"Obwod : "<<obwod()<<endl;
}

void Tfigura::info() {
    cout<<"Nazwa : "<<nazwa<<endl;
}

void Tfigura::rysuj() {
    cout<<"Rysuje <"<<nazwa<<">"<<endl;
}

float Tfigura::pole() {
    return 0;
}

float Tfigura::obwod() {
    return 0;
}