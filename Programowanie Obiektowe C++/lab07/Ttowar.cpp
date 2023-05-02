#include "Ttowar.h"

#include <iostream>

using namespace std;

Ttowar::Ttowar() {
    nazwa="";
    cena=0;
    ilosc=0;
}

Ttowar::Ttowar(const string &nazwa, float cena, int ilosc) {
    this->nazwa=nazwa;
    this->cena=cena;
    this->ilosc=ilosc;
}

void Ttowar::wczytaj() {
    cout<<"Podaj nazwe towaru :"<<endl; cin>>nazwa;
    cout<<"Podaj cene towaru :"<<endl; cin>>cena;
    cout<<"Podaj ilosc towaru :"<<endl; cin>>ilosc;
}

float Ttowar::oblicz() {
    return ilosc * cena;
}

void Ttowar::wyswietl() {
    cout<<"Cena : "<<cena<<"\nIlosc : "<<ilosc<<"\nCalosc : "<<oblicz()<<endl;
}