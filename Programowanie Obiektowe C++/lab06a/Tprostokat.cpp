#include "Tprostokat.h"

#include <iostream>

using namespace std;

Tprostokat::Tprostokat() {
    cout<<"Konstruktor domyslny klasy <Tprostokat>"<<endl;
    a=2.5; b=5.5;
    nazwa="Prostokat";
}

Tprostokat::Tprostokat(float a, float b) {
    cout<<"Konstruktor klasy <Tprostokat> z parametrami"<<endl;
    this->a=a; this->b=b;
}

Tprostokat::~Tprostokat() {
    cout<<"Destruktor klasy <Tprostokat>"<<endl;
}

float Tprostokat::pole() {
    return a*b;
}

float Tprostokat::obwod() {
    return 2*a+2*b;
}