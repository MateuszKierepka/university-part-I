#include "Tdata.h"
#include "Tosoba2.h"


using namespace std;

int main() {

//    const int n = 3;
//    Tosoba2 osoba[n];
//    for(int i=0; i<n; i++){
//        osoba[i].wczytaj();
//    }
//    for(int i=0; i<n; i++){
//        osoba[i].wyswietl();
//    }

    Tosoba2 *wsk_os[3];
    for(int i=0; i<3; i++){
        wsk_os[i] = new Tosoba2; //utworzenie obiektu dynamicznego
        wsk_os[i]->wczytaj();
    }

    for(int i=0; i<3; i++){
        wsk_os[i]->wyswietl();
    }

    system("PAUSE");
    return 0;
}
