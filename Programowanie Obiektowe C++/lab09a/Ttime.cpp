#include "Ttime.h"

Ttime::Ttime() {
	//constructor
}

Ttime::Ttime(int hours, int minutes) {
	while (minutes >= 60) {
		hours++;
	}
	this->hours = hours;
	this->minutes = minutes;
}

Ttime::~Ttime() {
	//destructor
}

int Ttime::getHours() {
	return hours;
}

int Ttime::getMinutes() {
	return minutes;
}

Ttime Ttime::operator+(Ttime time) {
	Ttime sum(0, 0);
	sum.hours = time.hours + hours;
	sum.minutes = time.minutes + minutes;
	while (sum.minutes >= 60) {
		sum.hours++;
		sum.minutes -= 60;
	}
	return sum;
}

Ttime Ttime::operator-(Ttime time) {
	Ttime subtraction(0, 0);
	if (hours > time.hours) {
		subtraction.hours = hours - time.hours;
		subtraction.minutes = minutes - time.minutes;
		while (subtraction.minutes < 0) {
			subtraction.hours--;
			subtraction.minutes += 60;
		}
	}
	else {
		subtraction.hours = time.hours - hours;
		subtraction.minutes = time.minutes - minutes;
		while (subtraction.minutes < 0){
			subtraction.hours--;
			subtraction.minutes = +60;
		}
	}
	return subtraction;
}

ostream& operator<<(ostream& os, const Ttime& time) {
	return os << time.hours << "h " << time.minutes << "min ";
}