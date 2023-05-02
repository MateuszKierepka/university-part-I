#include "Tdokument.h"

#include <iostream>

using namespace std;

Tdokument::Tdokument(const string &numer, const string &nazwa, Tdata data) {
    this->numer=numer;
    this->nazwa=nazwa;
    this->data=data;
}

void Tdokument::wyswietl() {
    cout<<"Numer : "<<numer<<endl;
    cout<<"Nazwa : "<<nazwa<<endl;
    cout<<"Data : "<<data.dzien<<"."<<data.miesiac<<"."<<data.rok<<endl;
}