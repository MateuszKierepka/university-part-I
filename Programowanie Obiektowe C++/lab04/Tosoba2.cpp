#include "Tosoba2.h"
#include <iostream>

using namespace std;

Tosoba2::Tosoba2() {
    nazwisko = "Kierepka"; imie = "Mateusz"; motto = "cos tam";
}

Tosoba2::Tosoba2(string nazwisko, string imie, Tdata d){
    this -> nazwisko = nazwisko; this -> imie = imie; this -> dataUr=d;
    motto = "cokolwiek";
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

int Tosoba2::roznicaWieku(Tosoba2 &partner){
    return (dataUr.getR() - partner.dataUr.getR());
}

Tosoba2 Tosoba2::dluzszeNazwisko(Tosoba2 &partner){
    if(nazwisko.length() > partner.nazwisko.length()){
    return Tosoba2();}
    else{
        return partner;
    }
}