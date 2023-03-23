#include <iostream>
#include "Tdata.h"
#include "Tosoba2.h"


int main() {
    Tdata data1, data2;
    Tosoba2 osoba1("Kierepka", "Mateusz", data1), osoba2("Tadewicz", "Jakub", data2);

//    osoba1.wczytaj();
    data1.wczytaj();

    osoba1.wyswietl();
    data1.wyswietl();
    cout<<data1.getR()<<endl;
//    cout<<osoba1.getNazwiskoImie()<<endl;

//    osoba2.wczytaj();
    data2.wczytaj();

    osoba2.wyswietl();
    data2.wyswietl();
    cout<<data2.getR()<<endl;
//    cout<<osoba2.getNazwiskoImie()<<endl;

    cout<<"Roznica wieku : "<<osoba1.roznicaWieku(osoba2)<<endl;
//    cout<<osoba1.dluzszeNazwisko(osoba2);
    return 0;
}
