/*
Author: Michael Padilla
Course: CSCI-136
Instructor: Tong Yi
Assignment: E2.10

It asks the user the number of gallons of gas in the tank,
the fuel efficiency in miles per gallon
and the price of gas per gallon
and then it prins the cost per 100 miles and how far the car can go with the gas in the tank.
*/

#include <iostream>
using namespace std;

int main() {
	int gasGallons;
	float fuelEfficiency;
	float gasPrice;

	cout << "Enter the number of gallons of gas in the tank: ";
	cin >> gasGallons;
	cout << "Enter the fuel efficiency in miles per gallon: ";
	cin >> fuelEfficiency;
	cout << "Enter the price of gas per gallon: ";
	cin >> gasPrice;

	cout << (100.0 / fuelEfficiency) * gasPrice << endl;
	cout << fuelEfficiency * gasGallons << endl;

	return 0;
}
