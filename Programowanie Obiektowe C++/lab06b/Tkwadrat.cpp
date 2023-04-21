#include "Tkwadrat.h"

#include <iostream>

using namespace std;

Tkwadrat::Tkwadrat(string nazwa, float a) {
    cout<<"Konstruktor klasy <Tkwadrat> z parametrami"<<endl;
    this->nazwa=nazwa;
    this->a=a;

}

Tkwadrat::~Tkwadrat() {
    cout<<"Destruktor klasy <Tkwadrat>"<<endl;
}

void Tkwadrat::info() {
    cout<<"Nazwa : "<<nazwa<<endl;
}

void Tkwadrat::rysuj() {
    cout<<"Rysuje <"<<nazwa<<">"<<endl;
}

float Tkwadrat::pole() {
    return a*a;
}

float Tkwadrat::obwod() {
    return 4*a;
}

void Tkwadrat::wyswietl() {
    info();
    rysuj();
    cout<<"Pole kwadratu wynosi : "<<pole()<<endl;
    cout<<"Obwod kwadratu wynosi : "<<obwod()<<endl;
}