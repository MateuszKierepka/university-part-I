#include "Tosoba2.h"
#include <iostream>
#include "Tdata.h"

using namespace std;

Tosoba2::Tosoba2() {
    imie = "Mateusz"; nazwisko = "Kierepka"; motto = "cos tam";
}

Tosoba2::Tosoba2(string nazwisko, string imie, Tdata d) {
    this->nazwisko = nazwisko; this->imie = imie; this->dataUr = d;
    motto="cokolwiek";
}

Tosoba2::~Tosoba2() {
    //destruktor
}

void Tosoba2::wczytaj() {
    cout<<"Podaj imie i nazwisko:\n"; cin>>imie>>nazwisko;
    fflush(stdin);
    cout<<"Podaj motto :\n";
    getline(cin, motto);
}

void Tosoba2::wyswietl() {
    cout<<"Imie i nazwisko : "<<imie<<" "<<nazwisko<<endl;
    cout<<"Motto : "<<motto<<endl;
//    cout<<"Data : "<<dataUr<<endl;
}

string Tosoba2::getNazwiskoImie() {
    return nazwisko + " " + imie;
}

int Tosoba2::roznicaWieku(Tosoba2 &partner) {
    return abs(dataUr.getR() - partner.dataUr.getR());
}

Tosoba2 Tosoba2::dluzszeNazwisko(Tosoba2 &partner) {
    if(this->nazwisko.length() > partner.nazwisko.length()){
        return *this;
    }
    else
        return partner;
}