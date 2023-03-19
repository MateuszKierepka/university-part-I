#include "Tosoba2.h"
#include <iostream>

using namespace std;

Tosoba2::Tosoba2() {
    nazwisko = "Kierepka"; imie = "Mateusz"; motto = "It is what it is";
}

Tosoba2::Tosoba2(const string & nazwisko, const string & imie, const Tdata & d){
    motto = "Future is here";
}

void Tosoba2::wczytaj() {
    cout<<"Podaj imie i nazwisko :\n"; cin>>imie>>nazwisko;
    cout<<"Podaj motto :\n"; cin>>motto;
}

void Tosoba2::wyswietl() {
    cout<<"Imie i nazwisko : "<<imie<<" "<<nazwisko<<endl;
    cout<<"Motto : "<<motto<<endl;
    //cout<<"Data urodzenia : "<<dataUr<<endl;
}

string Tosoba2::getNazwiskoImie() {
    return nazwisko + " " + imie;
}