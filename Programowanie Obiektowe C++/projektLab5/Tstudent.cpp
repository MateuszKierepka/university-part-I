#include "Tstudent.h"
#include <iostream>
#include <vector>

using namespace std;

Tstudent::Tstudent() {
    cout<<"Utworzono obiekt klasy <Tstudent> konstruktorem <bez parametrow>\n";
}

Tstudent::Tstudent(string imie, string nazwisko, string uczelnia, vector <float> oceny) {
    this->imie=imie;
    this->nazwisko=nazwisko;
    this->uczelnia=uczelnia;
    this->oceny=oceny;
    cout<<"Utworzono obiekt klasy <Tstudent> konstruktorem <z parametrami>\n";
}

Tstudent::~Tstudent() {
    cout<<"Usunieto obiekt klasy <Tstudent>\n";
}

void Tstudent::wczytaj() {
    cout<<"Podaj imie i nazwisko : \n";
    cin>>imie>>nazwisko;
    ::fflush(stdin);
    cout<<"Podaj uczelnie : \n";
    getline(cin, uczelnia);
    cout<<"Podaj liczbe ocen : \n";
    cin>>liczba_ocen;
    int x;
    for(int i=0; i<liczba_ocen; i++){
        cout<<"Podaj "<<i+1<<" ocene : \n";
        cin>>x;
        oceny.push_back(x);
    }
}

void Tstudent::wyswietl() {
    cout<<"Dane osobowe : \n";
    cout<<imie<<" "<<nazwisko<<endl;
    cout<<"Dane studenta : \n";
    cout<<"Uczelnia : "<<uczelnia<<endl;
    cout<<"Oceny : ";
    for(int i=0; i<liczba_ocen; i++){
        cout<<oceny[i]<<", ";
    }
    cout<<endl;
}

float Tstudent::sredniaOcen() {
    float x=0;
    for(int i=0; i<liczba_ocen; i++){
        x+=oceny[i];
    }
    x=x/liczba_ocen;
    return x;
}

bool Tstudent::czyZdane() {
    for(int i=0; i<liczba_ocen; i++){
        if(oceny[i]<3){
            return false;
        }
        if(sredniaOcen()>=3.0){
            return true;
        }
        else
            return false;
    }
}
