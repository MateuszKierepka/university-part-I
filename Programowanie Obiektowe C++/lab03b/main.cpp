#include "Toosba_wskaznik.h"

int main() {
    Toosba_wskaznik osoba;
    osoba.wczytaj();
    osoba.wyswietl();
    osoba.info();

    Toosba_wskaznik osoba1(2001);
    osoba1.wyswietl(2001);
    osoba1.info(2001);

    Toosba_wskaznik* wsk = new Toosba_wskaznik;
    wsk->wyswietl();
    wsk->info(2001);
    delete wsk;

    system("PAUSE");
    return EXIT_SUCCESS;
}