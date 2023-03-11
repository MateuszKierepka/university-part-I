#include <iostream>
#include "Tdzialania.h"

using namespace std;

int main() {
    Tdzialania dzialania;
    dzialania.podajDane();
    cout<<"Suma = "<<dzialania.suma()<<endl;
    cout<<"Roznica = "<<dzialania.roznica()<<endl;
    cout<<"Iloczyn = "<<dzialania.iloczyn()<<endl;
    cout<<"Iloraz = "<<dzialania.iloraz()<<endl;
    cout<<"Potegowanie = "<<dzialania.potegowanie()<<endl;
    system("PAUSE");
    return 0;
}
