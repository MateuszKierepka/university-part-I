#include <iostream>
#include "Tdata.h"
#include "Tosoba2.h"


int main() {
    Tdata data1, data2;
    data1.wczytaj();
    data1.wyswietl();
    cout<<data1.getR()<<endl;

    data2.wczytaj();
    data2.wyswietl();
    cout<<data2.getR()<<endl;

    Tosoba2 osoba1("Kierepson", "Mathew", data1), osoba2("Michalski", "Jacob", data2);
//    osoba1.wczytaj();
    osoba1.wyswietl();
//    cout<<osoba1.getNazwiskoImie()<<endl;

//    osoba2.wczytaj();
    osoba2.wyswietl();
//    cout<<osoba2.getNazwiskoImie()<<endl;

//    cout<<osoba1.dluzszeNazwisko(osoba2);
    cout<<"roznica wieku : "<<osoba1.roznicaWieku(osoba2)<<endl;
    return 0;
}
