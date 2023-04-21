#include "Ifigura.h"
#include "Tkolo.h"
#include "Tprostokat.h"
#include "Tkwadrat.h"

#include <iostream>

int main() {

Tkolo kolo;
Tprostokat prostokat;
Tkwadrat kwadrat;

cout<<endl;

Ifigura *wsk;//utworzenie polimorficznego wskaznika typu <Ifigura>

wsk=&kolo;
wsk->wyswietl();

cout<<endl;

wsk=&prostokat;
wsk->wyswietl();

cout<<endl;

wsk=&kwadrat;
wsk->wyswietl();

    system("PAUSE");
    return EXIT_SUCCESS;
}
