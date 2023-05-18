#include <iostream>

#include "Tstudent.h"

ostream& operator<<(ostream& os, const Tstudent& student) {
	os << student.imie << " " << student.nazwisko;
	return os;
}

int main(){
	Tstudent student("Mateusz", "Kierepka");
	cout << student << endl;

	system("PAUSE");
	return EXIT_SUCCESS;
}