#pragma once
#include <iostream>

using namespace std;

class Tzespolona {
public:
	double rzeczywista;
	double urojona;

	Tzespolona();
	Tzespolona(double rzeczywista, double urojona);
	~Tzespolona();
	
	double getRzeczywista();
	double getUrojona();

	Tzespolona operator+(Tzespolona zespolona);

	friend ostream& operator<<(ostream& os, const Tzespolona& zespolona);
};
