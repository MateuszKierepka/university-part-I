#include "Tkolo.h"

#include <iostream>
#include <math.h>

using namespace std;

Tkolo::Tkolo() {
    cout<<"Konstruktor domyslny klasy <Tkolo>"<<endl;
    promien=1.5;
    nazwa="Kolo";
}

Tkolo::Tkolo(float promien) {
    cout<<"Konstruktor klasy <Tkolo> z parametrem"<<endl;
    this->promien=promien;
}

Tkolo::~Tkolo() {
    cout<<"Destruktor klasy <Tkolo>"<<endl;
}

float Tkolo::pole() {
    return M_PI*promien*promien;
}

float Tkolo::obwod() {
    return 2*M_PI*promien;
}