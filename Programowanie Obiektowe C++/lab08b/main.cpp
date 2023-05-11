#include <iostream>
#include <cmath>

#include "Tpunkt.h"


using namespace std;

bool nalezy(Tpunkt *punkt, Tkolo *kolo){
    float s = sqrt(pow(punkt->x, 2) + pow(punkt->y, 2));
    if(s > kolo->getR()){
        return false;
    }
    else{
        return true;
    }
}

int main() {
    Tpunkt punkt(0, 3);
    Tkolo kolo(3);

    if(nalezy(&punkt, &kolo)){
        cout<<"Punkt nalezy do kola o srodku(0, 0)"<<endl;
    }
    else{
        cout<<"Punkt nie nalezy do kola o srodku(0, 0)"<<endl;
    }
    return 0;
}
