#include "Tpracownik.h"
#include <iostream>

using namespace std;

void Tpracownik::wczytaj(){
    cout<<"Podaj imie i nazwisko: "<<endl;
    cin>>imie>>nazwisko;
    cout<<"Podaj stawke i liczbe godzin :"<<endl;
    cin>>stawka>>liczba_godzin;
}

float Tpracownik::placa(){
    return stawka*liczba_godzin;
}

void Tpracownik::wyswietl(){
    cout<<imie<<" "<<nazwisko<<" zarabia "<<Tpracownik::placa()<<endl;
}
