#pragma once
#include <iostream>
#include <string>

using namespace std;

class Tstudent{
	string imie;
	string nazwisko;

public:
	Tstudent();
	Tstudent(string imie, string nazwisko);
	~Tstudent();

	void wczytaj();
	void wyswietl();

	friend ostream& operator<<(ostream& os, const Tstudent& student);
};

