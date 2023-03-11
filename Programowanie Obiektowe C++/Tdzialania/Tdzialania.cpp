#include "Tdzialania.h"
#include <iostream>
#include <cmath>

using namespace std;

    void Tdzialania::podajDane(){
    cout<<"Podaj dwie liczby calkowite : ";
    cin>>a>>b;
    }

    int Tdzialania::suma(){
    return a+b;
    }

    int Tdzialania::roznica(){
    return a-b;
    }

    int Tdzialania::iloczyn() {
        return a*b;
    }

    int Tdzialania::iloraz(){
        return a/b;
    }

    int Tdzialania::potegowanie() {
        return pow(a, b);
    }