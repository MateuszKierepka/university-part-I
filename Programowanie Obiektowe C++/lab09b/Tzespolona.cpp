#include "Tzespolona.h"

Tzespolona::Tzespolona() {
	//constructor
}

Tzespolona::Tzespolona(double rzeczywista, double urojona) {
	this->rzeczywista = rzeczywista;
	this->urojona = urojona;
}

Tzespolona::~Tzespolona() {
	//destructor
}


Tzespolona Tzespolona::operator+(Tzespolona zespolona) {
	Tzespolona suma(0, 0);
	suma.rzeczywista = this->rzeczywista + zespolona.rzeczywista;
	suma.urojona = this->urojona + zespolona.urojona;
	return suma;
}