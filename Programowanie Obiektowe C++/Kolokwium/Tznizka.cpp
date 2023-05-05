#include "Tznizka.h"

#include <iostream>

using namespace std;

Tznizka::Tznizka() {
    //konstruktor
}

Tznizka::~Tznizka() {
    //destruktor
}

void Tznizka::wczytaj() {
    cout<<"Czy posiadasz karte stalego klienta?\n1 - TAK\n2 - NIE"<<endl;
    cin>>czyStalyKlient;
}

void Tznizka::wyswietl() {
    if(czyStalyKlient == 1){
        Twymiana wymiana;
        Tcennik cennik;

        wymiana.wczytaj();
        cennik.wczytaj();

        wymiana.wyswietl();
        cout<<"Kwota do zaplaty po znizce : "<<0.9 * cennik.KwotaDoZaplaty()<<endl;
    }
}