#pragma once
#include <iostream>

using namespace std;

class Ttime{
	int hours;
	int minutes;

public:
	Ttime();
	Ttime(int hours, int minutes);
	~Ttime();

	int getHours();
	int getMinutes();

	Ttime operator+(Ttime time);
	Ttime operator-(Ttime time);

	friend ostream& operator<<(ostream& os, const Ttime& time);
};
