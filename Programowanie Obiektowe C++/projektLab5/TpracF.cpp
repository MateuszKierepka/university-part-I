#include "TpracF.h"
#include <iostream>

using namespace std;

TpracF::TpracF() {
    cout<<"Utworzono obiekt klasy <TpracF> konstruktorem <bez parametrow>\n";
}

TpracF::TpracF(string imie, string nazwisko, string firma, int premia, int stawka) {
    this->imie=imie;
    this->nazwisko=nazwisko;
    this->firma=firma;
    this->premia=premia;
    this->stawka=stawka;
    cout<<"Utworzono obiekt klasy <TpracF> konstruktorem <z parametrami>\n";
}

TpracF::~TpracF() {
    cout<<"Usunieto obiekt klasy <TpracF>\n";
}

void TpracF::zarobki() {
    int h;
    cout<<"Podaj ilosc przepracowanych godzin : \n";
    cin>>h;
    cout<<"Zarobki wynosza : "<<stawka*h<<endl;
}

void TpracF::wyswietl() {
    Tpracownik::wyswietl();
    cout<<"Zarobki : "<<stawka<<endl;
    cout<<"Premia : "<<premia<<endl;
    zarobki();
}