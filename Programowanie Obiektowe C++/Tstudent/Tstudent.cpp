#include "Tstudent.h"
#include <iostream>

using namespace std;

void Tstudent::wczytaj() {
    cout<<"Podaj imie i nazwisko : "<<endl;
    cin>>imie>>nazwisko;
    for(int i=0; i<3; i++){
        cout<<"Wynik z "<<i+1<<" egzaminu : "<<endl;
        cin>>egzamin[i];
    }
}

float Tstudent::srednia() {
    float srednia;
    for(int i=0; i<3; i++){
        srednia += egzamin[i];
    }
    return srednia/3;
}

void Tstudent::wyswietl() {
    cout<<"Srednia ocen "<<imie<<" "<<nazwisko<<" wynosi : "<<Tstudent::srednia()<<endl;
}