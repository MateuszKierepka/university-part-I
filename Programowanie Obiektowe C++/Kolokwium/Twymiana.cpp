#include "Twymiana.h"

#include <iostream>

using namespace std;

Twymiana::Twymiana() {
    //konstruktor

}

Twymiana::~Twymiana() {
    //destruktor
}

void Twymiana::wczytaj() {
    ::fflush(stdin);
    cout<<"Podaj numer rejestracyjny : "<<endl;
    getline(cin, nr_rejestracyjny);
    cout<<"Podaj date wymiany : "<<endl; cin>>data.dzien>>data.miesiac>>data.rok;
    cout<<"Podaj godzine wymiany : "<<endl; cin>>godzina.godzina>>godzina.minuta;
    while(godzina.godzina > 23 || godzina.minuta > 59){
        cout<<"Podaj godzine wymiany : "<<endl; cin>>godzina.godzina>>godzina.minuta;
    }
    ::fflush(stdin);
    cout<<"Opis wymiany : "<<endl;
    getline(cin, opis);
}

void Twymiana::wyswietl() {
    cout<<"Data : "<<data.dzien<<"."<<data.miesiac<<"."<<data.rok<<endl;
    cout<<"Godzina : "<<godzina.godzina<<":"<<godzina.minuta<<endl;
    cout<<"Numer rejestracyjny : "<<nr_rejestracyjny<<endl;
    cout<<"Opis : "<<opis<<endl;
}