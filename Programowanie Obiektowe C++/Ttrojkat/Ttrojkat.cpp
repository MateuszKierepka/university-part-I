#include "Ttrojkat.h"
#include <cmath>

using namespace std;

Ttrojkat::Ttrojkat(int a, int b, int c){
    int p;
    p = (a + b + c) / 2;
    _pole = sqrt(p*(p-a)*(p-b)*(p-c));
}

Ttrojkat::Ttrojkat(int a, int h){
    _pole = (a * h) / 2;
}

float Ttrojkat::pole(){
    return _pole;
}
