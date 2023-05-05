#include "Tcennik.h"

#include <iostream>

using namespace std;

Tcennik::Tcennik() {
    //konstruktor
    cena=0;
    pozycja_cenowa=0;
}

Tcennik::~Tcennik() {
    //destruktor
}

void Tcennik::wczytaj() {
    pozycja_cenowa = 0;
    while(pozycja_cenowa <= 0 || pozycja_cenowa >= 4) {
        cout << "Wybierz pozycje cenowa :\n1-Wymiana opon na nowe (1500 ZLOTY)\n2-Wymiana opon na wlasne (200 ZLOTY)\n3-Wymiana opon na nowe(uzywane) (1000 ZLOTY)"<<endl;
        cin>>pozycja_cenowa;
    }
    if(pozycja_cenowa == 1){
        cena = 1500;
    }
    if(pozycja_cenowa == 2){
        cena = 200;
    }
    if(pozycja_cenowa == 3){
        cena = 1000;
    }
}

int Tcennik::KwotaDoZaplaty() {
    return cena;
}

