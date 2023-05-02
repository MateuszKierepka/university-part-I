#include "Tfaktura.h"

#include <iostream>
#include <iomanip>

using namespace std;

Tfaktura::Tfaktura(Tklient *klient, Tdata data, const string &nazwa, const string &numer)
: Tdokument(numer, nazwa, data){
    this->klient=klient;
    this->towary=NULL;
    this->liczTowary=0;
    this->wartosc=0;
}

Tfaktura::~Tfaktura() {
    if(towary != NULL){
        delete [] towary;
    }
}

void Tfaktura::wczytaj() {
    if(towary == NULL){
        cout<<"Podaj ilosc towarow :"<<endl; cin>>liczTowary;

        while(liczTowary <= 0){
            cout<<"Ilosc towarow musi byc dodatnia, wprowadz ilosc ponownie :"<<endl; cin>>liczTowary;
        }

        towary = new Ttowar[liczTowary];

        for(int i=0; i<liczTowary; i++){
            towary[i].wczytaj();
            wartosc += towary[i].oblicz();
        }
    }
}

void Tfaktura::wyswietl() {
    Tdokument::wyswietl();
    cout<<"Klient : ";
    klient->wyswietl();

    cout<<endl;
    if(towary != NULL){
        for(int i=0; i<liczTowary; i++){
            towary[i].wyswietl();
        }
    }

    cout<<"Laczna wartosc : "<<wartosc<<endl;
    cout<<endl;
}