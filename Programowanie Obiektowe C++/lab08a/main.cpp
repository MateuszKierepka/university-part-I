#include <iostream>
#include <string>

#include "Tdomownik.h"

using namespace std;

string sasiad(Tdomownik *wsk){
    cout<<"Podaj nowy kod systemu alarmowego: "<<endl; cin>>wsk->kod;
    return wsk->sekret;
}

int main() {
    Tdomownik ojciec("Ojciec");
    Tdomownik matka("Matka");
    Tdomownik corka("Corka");
    Tdomownik::setkod();

    Tsasiad s("Marian");
    s.info(&ojciec);
    s.info(&matka);
    s.info(&corka);

    string sekret = sasiad(&ojciec);
    cout<<"Sekret to : "<<sekret<<endl;
    cout<<"Nowy kod to : "<<ojciec.getkod()<<endl;

    return 0;
}
