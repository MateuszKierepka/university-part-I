#include "Tklient.h"
#include "Tfaktura.h"


int main() {
    Tklient klient("Mateusz", "Kierepka");
    Tfaktura faktura(&klient, {2, 5, 2023}, "Faktura", "5/2023");
    faktura.wczytaj();

    Tfaktura faktura2(&klient, {2, 5, 2023}, "Faktura", "5/2023");
    faktura2.wczytaj();

    faktura.wyswietl();
    faktura2.wyswietl();

    return 0;
}