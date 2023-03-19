#include "Tdata.h"
#include <iostream>

using namespace std;

Tdata::Tdata(){
    d=4; m=6; r=2003;
}

void Tdata::wczytaj(){
    cout<<"Podaj dzien-miesiac-rok :\n"; cin>>d>>m>>r;
}

void Tdata::wyswietl() {
    cout<<"Data : "<<d<<"-"<<m<<"-"<<r<<endl;
}

int Tdata::getR() {
    return r;
}