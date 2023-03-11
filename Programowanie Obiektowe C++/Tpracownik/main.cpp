#include <iostream>
#include "Tpracownik.h"

using namespace std;

int main() {
    Tpracownik pracownik[2];
    Tdata data[2];
    for(int i=0; i<2; i++) {
        cout << "Podaj date zatrudnienia :" << endl;
        cin >> data[i].dzien >> data[i].miesiac >> data[i].rok;
        pracownik[i].wczytaj();

    }
    for(int i=0; i<2; i++) {
        cout << "Placa : " << pracownik[i].placa() << endl;
        pracownik[i].wyswietl();
        cout<<"\n";
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
