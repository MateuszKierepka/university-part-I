#include "Tstudent.h"

#include <iostream>

using namespace std;

Tstudent::Tstudent() {
	//constructor
}

Tstudent::Tstudent(string imie, string nazwisko) {
	this->imie = imie;
	this->nazwisko = nazwisko;
}

Tstudent::~Tstudent() {
	//destructor
}

void Tstudent::wczytaj() {
	cout << "Podaj imie i nazwisko : " << endl;
	cin >> imie >> nazwisko;
}

void Tstudent::wyswietl() {
	cout << "Imie : " << imie << endl;
	cout << "Nazwisko : " << nazwisko << endl;
}