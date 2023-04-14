#include <iostream>

#include "Tfigura.h"
#include "Tkolo.h"
#include "Tprostokat.h"
#include "Tkwadrat.h"

using namespace std;

int main() {
//Tfigura figura;
//figura.wyswietl();
//cout<<endl;

Tkolo kolo, k(5);
kolo.wyswietl();
cout<<endl;
//k.wyswietl();
//cout<<endl;

Tprostokat prostokat, p(3, 4);
prostokat.wyswietl();
cout<<endl;
//p.wyswietl();
//cout<<endl;

Tkwadrat kwadrat, kw(4);
kwadrat.wyswietl();
cout<<endl;
//kw.wyswietl();
//cout<<endl;

    return 0;
}
