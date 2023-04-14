#include "Tstudent.h"
#include <iostream>

using namespace std;

int main() {
    Tstudent student;
    student.wczytaj();
    student.srednia();
    student.wyswietl();
    system("PAUSE");
    return EXIT_SUCCESS;
}