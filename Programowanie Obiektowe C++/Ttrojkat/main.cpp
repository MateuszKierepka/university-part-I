#include <iostream>
#include "Ttrojkat.h"

using namespace std;
int main() {
    int a, b, c, h, wybor;
    cout<<"Podaj boki trojkata i wysokosc : \n";
    cin>>a>>b>>c>>h;
    cout<<"1 - pole obliczone z bokami\n2 - pole obliczone z wysokoscia\nWybierz metode : \n";
    cin>>wybor;
    switch(wybor){
        case 1:{
            Ttrojkat trojkat(a, b, c);
            cout<<"Pole trojkata = "<<trojkat.pole()<<endl;
            break;
        }
        case 2:{
            Ttrojkat trojkat(a, h);
            cout<<"Pole trojkata = "<<trojkat.pole()<<endl;
            break;
        }
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
