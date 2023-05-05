#include <iostream>

#include "Twymiana.h"
#include "Tcennik.h"
#include "Tznizka.h"

using namespace std;

int main() {
    //zad 1
    for(int i=0; i<2; i++) {
        Twymiana wymiana;
        Tcennik cennik;

        wymiana.wczytaj();
        cennik.wczytaj();

        cout<<"SAMOCHOD NR "<<i+1<<" : "<<endl;
        wymiana.wyswietl();
        cout << "Kwota do zaplaty : " << cennik.KwotaDoZaplaty() << endl;
        cout<<endl;
    }

    //zad 2
    Tznizka znizka;
    znizka.wczytaj();
    znizka.wyswietl();
    return 0;
}
