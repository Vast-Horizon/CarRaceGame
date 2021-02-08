//Specification file
#ifndef CARDATA_H
#define CARDATA_H
#include <string>
using namespace std;
class Car
{
private:
	string owner;
	int yearModel;
	string make;
	int speed;
public:
	Car() { owner = ""; yearModel = 0; make = ""; speed = 0; }
	Car(string o, int y, string m);

	void setOwner(string o) { owner = o; }
	void setYear(int y) { yearModel = y; }
	void setMake(string m) { make = m; }
	void setSpeed(int s) { speed = s; }

	string getOwner()const { return owner; }
	int getYear()const { return yearModel; }
	string getMake()const { return make; }
	int getSpeed()const { return speed; }

	void accelerate() { speed += 5; };
	void brake() { speed -= 5; };
	void upateStatus();
	~Car() {};
};
#endif
