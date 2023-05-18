#include <iostream>

#include "Ttime.h"

using namespace std;

Ttime operator*(Ttime& time, int N) {
	int multiplication_h = 0, multiplication_min=0;
	multiplication_h = time.getHours() * N;
	multiplication_min = time.getMinutes() * N;
	while (multiplication_min >= 60) {
		multiplication_h++;
		multiplication_min -= 60;
	}
	return Ttime(multiplication_h, multiplication_min);
}

bool operator==(Ttime& time, Ttime& time1) {
	return (time.getHours() == time1.getHours() && time.getMinutes() == time1.getMinutes());
}

int main(){
	Ttime flight1(8, 49), flight2(2, 11), waiting(4, 22);
	cout << "Flight 1 : " << flight1 << endl;
	cout << "Flight 2 : " << flight2 << endl;
	cout << "Waiting : " << waiting << endl;

	cout << "Total travel time : " << flight1 + flight2 + waiting << endl;
	
	flight2 = flight2 * 2;
	cout << "Doubled time of the 2nd flight : " << flight2 << endl;

	if (flight2 == waiting) {
		cout << "Times are the same!" << endl;
	}
	else {
		cout << "Times aren't the same!" << endl;
	}

	system("PAUSE");
	return EXIT_SUCCESS;
}