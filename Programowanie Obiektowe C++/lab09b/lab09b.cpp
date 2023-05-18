#include <iostream>

#include "Tzespolona.h"

using namespace std;

ostream& operator<<(ostream& os, const Tzespolona& zespolona) {
	os << zespolona.rzeczywista << " + " << zespolona.urojona << " i";
	return os;
}

Tzespolona operator-(Tzespolona a, Tzespolona b) {
	Tzespolona roznica(0, 0);
	roznica.rzeczywista = a.rzeczywista - b.rzeczywista;
	roznica.urojona = a.urojona - b.urojona;
	return roznica;
}

Tzespolona operator*(Tzespolona a, Tzespolona b) {
	Tzespolona iloczyn(0, 0);
	iloczyn.rzeczywista = a.rzeczywista * b.rzeczywista;
	iloczyn.urojona = a.urojona * b.urojona;
	return iloczyn;
}

Tzespolona operator/(Tzespolona a, Tzespolona b) {
	Tzespolona iloraz(0, 0);
	iloraz.rzeczywista = a.rzeczywista / b.rzeczywista;
	iloraz.urojona = a.urojona / b.urojona;
	return iloraz;
}

int main(){
	Tzespolona z1(1, 2.4), z2(6.9, 2.3), z3(0, 0);
	cout << "z1 : " << z1 << endl;
	cout << "z2 : " << z2 << endl;
	
	z3 = z1 + z2;
	cout << "Suma z1 i z2 wynosi " << z3 << endl;

	z3 = z1 - z2;
	cout << "Roznica z1 i z2 wynosi " << z3 << endl;
	
	z3 = z1 * z2;
	cout << "Iloczyn z1 i z2 wynosi " << z3 << endl;

	z3 = z1 / z2;
	cout << "Iloraz z1 i z2 wynosi " << z3 << endl;

	system("PAUSE");
	return EXIT_SUCCESS;
}
