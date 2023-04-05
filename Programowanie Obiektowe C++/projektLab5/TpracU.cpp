#include "TpracU.h"
#include <iostream>

using namespace std;

TpracU::TpracU() {
    cout<<"Utworzono obiekt klasy <TpracU> konstruktorem <bez parametrow>\n";
}

TpracU::TpracU(string imie, string nazwisko, string firma, int stawka, int premia) {
    this->imie=imie;
    this->nazwisko=nazwisko;
    this->firma=firma;
    this->premia=premia;
    this->wynagrodzenie=wynagrodzenie;
    cout<<"Utworzono obiekt klasy <TpracU> konstruktorem <z parametrami>\n";
}

TpracU::~TpracU() {
    cout<<"Usunieto obiekt klasy <TpracU\n";
}

void TpracU::wyswietl() {
    Tpracownik::wyswietl();
    cout<<"Zarobki : "<<wynagrodzenie<<endl;
    cout<<"Premia : "<<premia<<endl;
}