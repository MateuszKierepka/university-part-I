#include "Tkwadrat.h"

#include <iostream>

using namespace std;

Tkwadrat::Tkwadrat() {
    cout<<"Konstruktor domyslny klasy <Tkwadrat>"<<endl;
    a=3.5;
    nazwa="Kwadrat";
}

Tkwadrat::Tkwadrat(float a) {
    cout<<"Konstruktor klasy <Tkwadrat> z parametrem"<<endl;
    this->a=a;
}

Tkwadrat::~Tkwadrat() {
    cout<<"Destruktor klasy <Tkwadrat>"<<endl;
}

float Tkwadrat::pole() {
    return a*a;
}

float Tkwadrat::obwod() {
    return 4*a;
}