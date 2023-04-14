#include "Tosoba.h"
#include <iostream>
#include <string>

using namespace std;

Tosoba::Tosoba(){
    imie = "Mikolaj";
    nazwisko = "Lukasik";
    data.d = 7;
    data.m = 6;
    data.r = 2005;
}

Tosoba::Tosoba(int rok) {
    imie = "Mikolaj";
    nazwisko = "Szuper";
    data.d = 3;
    data.m = 4;
    data.r = rok;
}

Tosoba::~Tosoba(){}

void Tosoba::wczytaj() {
    cout<<"Podaj imie i nazwisko : "<<endl;
    cin>>imie>>nazwisko;
    cout<<"Podaj date urodzenia (dzien-miesiac-rok) : "<<endl;
    cin>>data.d>>data.m>>data.r;
}

void Tosoba::wyswietl() {
    cout<<"1. Dane osobowe : "<<imie<<" "<<nazwisko<<" , "<<data.d<<"."<<data.m<<"."<<data.r<<endl;
}

void Tosoba::wyswietl(int rok) {
    data.r = rok;
    int wiek;
    wiek = 2023 - rok;
    cout<<"2. Dane osobowe : "<<imie<<" "<<nazwisko<<" ; wiek : "<<wiek<<endl;
}

void Tosoba::info() {
    int wiek = 2023 - data.r;
    if (wiek < 18){
        cout<<"Dziecko\n";
    }
    if (wiek == 18){
        if (data.m > 3){
            cout<<"Dziecko\n";
        }
        if (data.m == 3){
            if (data.d <= 11){
                cout<<"Osoba pelnoletnia\n";
            }
            else{
                cout<<"Dziecko\n";
            }
        }
        if (data.m < 3){
            cout<<"Osoba pelnoletnia\n";
        }
    }
    if (wiek > 18 and wiek < 31){
        cout<<"Osoba pelnoletnia\n";
    }
    if (wiek > 30 and wiek < 51){
        cout<<"Osoba 30+\n";
    }
    if (wiek > 50)
        cout<<"Osoba 50+\n";
}

void Tosoba::info(int rok) {
    data.r = rok;
    int wiek = 2023 - rok;
    if (wiek >= 18){
        wiek = wiek - 18;
        rok = 2023 - wiek;
        cout<<"Osoba ukonczyla 18 lat w "<<rok<<" roku"<<endl;
    }
    else {
        cout<<"Osoba nie ukonczyla 18 lat"<<endl;
    }
}