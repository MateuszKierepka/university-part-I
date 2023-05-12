#include <iostream>

#include "Ttime.h"

int main() {
    Ttime lot1(4, 20);
    lot1.wyswietl();

    Ttime lot2(2, 10);
    lot2.wyswietl();

    cout<<"Suma : "<<lot1 + lot2<<endl;
    cout<<"Roznica : "<<lot1 - lot2<<endl;

    Ttime oczekiwanie(4, 15);

    cout<<"Calkowity czas podrozy wynosi "<<lot1 + lot2 + oczekiwanie<<endl;

    Ttime zwiekszenie = lot2 * 2;
    cout<<"Iloraz : "<<zwiekszenie<<endl;

    if(lot1 == zwiekszenie){
        cout<<"Czasy podrozy sa takie same"<<endl;
    }
    else{
        cout<<"Czasy podrozy nie sa takie same"<<endl;
    }
    return 0;
}
