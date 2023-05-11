#include "Tpunkt.h"

Tpunkt::Tpunkt() {
    //konstruktor domyslny
}

Tpunkt::Tpunkt(float x, float y) {
    this->x=x;
    this->y=y;
}

Tpunkt::~Tpunkt() {
    //destruktor
}

void Tpunkt::ruch(float x_a, float y_b) {
    x += x_a;
    y += y_b;
}

float Tpunkt::getX() {
    return x;
}

float Tpunkt::getY() {
    return y;
}


Tkolo::Tkolo() {
    //konstruktor
}

Tkolo::Tkolo(float r) {
    this->r=r;
}

Tkolo::~Tkolo() {
    //destruktor
}

float Tkolo::getR() {
    return r;
}