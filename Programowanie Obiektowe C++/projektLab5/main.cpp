#include "Tosoba.h"
#include "Tstudent.h"
#include "Tpracownik.h"
#include "TpracF.h"
#include "TpracU.h"

using namespace std;

int main() {
Tstudent student1;
student1.wczytaj();
student1.wyswietl();
student1.sredniaOcen();
student1.czyZdane();

TpracF pracownik1("Mateusz", "Kierepka", "New Balance", 500, 25);
pracownik1.wyswietl();

TpracU pracownik2("Piotr", "Zyla", "Reprezentacja Polski", 100, 5000);
pracownik2.wyswietl();
    return 0;
}
