#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "car.h"

using namespace std;

int main() {
	//creat five car objects
	Car carObj[5];
	//file objects
	fstream input, output;
	//define variables
	string name, make;
	int year, count=0;
	//open the data file
	input.open("carData.txt", ios::in|ios::app);
	if (input.fail()) {
		cout << "Cannot open the file" << endl;
	}
	else {
		srand(time(0));
		while (!input.eof()) {
			getline(input, name, ':');//read the string till ":"
			input >> year >> make;
			input.ignore();
			carObj[count] = Car(name, year, make);//store the data into the object
			count++;
		}
		//display the information before start the game 
		cout << "NO.    Owner\t   Year-Model\t   Make" << endl;
		cout << "-----------------------------------------\n";
		for (int i = 0; i < 5; i++) {
			cout << left << setw(5) << i + 1 << setw(18) << carObj[i].getOwner()
				<< setw(11) << carObj[i].getYear()
				<< setw(12) << carObj[i].getMake()
				<< endl;
		}
		//wait for pressing enter
		cout << "\nPress Enter to start the game!";cin.get();
		cout << endl;
		//10 round
		for (int i = 0; i < 10; i++) {
			cout << "Round " << i + 1 << endl;
			cout << "NO." << "  speed" << endl;
			for (int j = 0; j < 5; j++) {

				carObj[j].upateStatus();
				//output the new speed of each car after each round
				cout << "NO." << j + 1 << "  " << carObj[j].getSpeed() << endl;
			}
			cout << endl;
		}
		//determine the winner
		int max = 100;
		int index;
		for (int j = 0; j < 5; j++) {
			if (carObj[j].getSpeed() >= max) {
				max = carObj[j].getSpeed();
				index = j;
			}
		
		}
		//close carData.txt
		input.close();
		//announce the winner
		cout << "***************************************************\n";
		cout << "NO.    Owner\t   Year-Model\t   Make    Final-Speed" << endl;
		for (int i = 0; i < 5; i++) {
			cout << left << setw(5) << i + 1 << setw(18) << carObj[i].getOwner()
				<< setw(11) << carObj[i].getYear()
				<< setw(12) << carObj[i].getMake()
				<< setw(12) << carObj[i].getSpeed() << endl;
		}
		
		cout << "NO." << index + 1 <<", "<<carObj[index].getOwner()<< " is the winner" << endl;

		//open winner file then output the winner reslut to there
		output.open("winner.txt", ios::out);
		output << "\nNO." << index + 1 << ", " << carObj[index].getOwner() << " is the winner" << endl;
		output << "\n\t\t********Winner Info********\n";
		output << "NO.    Owner\t   Year-Model\t   Make \tFinal-Speed" << endl;
		output << left << setw(5) << index + 1 << setw(18) << carObj[index].getOwner()
			<< setw(11) << carObj[index].getYear()
			<< setw(12) << carObj[index].getMake()
			<< setw(12)<<carObj[index].getSpeed()<<endl;
		//close winner.txt
		output.close();
	}
	

	return 0;
}

