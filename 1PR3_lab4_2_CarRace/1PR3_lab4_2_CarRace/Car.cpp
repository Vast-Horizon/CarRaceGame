//Implementation file
#include "Car.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
Car::Car(string o, int y, string m) {
	owner = o;
	yearModel = y;
	make = m;
	
	int randomN = 100 + (rand() % (101));
	speed = randomN;
}
void Car::upateStatus() {
	int r = rand() % 2;
	if (r == 0)
		brake();
	else if (r == 1)
		accelerate();
}