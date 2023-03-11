#include "Tosoba.h"

int main() {
    Tosoba osoba;
    osoba.wczytaj();
    osoba.wyswietl();
    osoba.info();

    Tosoba osoba1(2001);
    osoba1.wyswietl(2001);
    osoba1.info(2001);

    system("PAUSE");
    return EXIT_SUCCESS;
}
