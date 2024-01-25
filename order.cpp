/*
Author: Michael Padilla
Course: CSCI-136
Instructor: Tong Yi
Assignment: E3.5

This asks for 3 numbers and print their order
*/

#include <iostream>
using namespace std;

int main() {
    int number1, number2, number3;

    cout << "Enter number1: ";
    cin >> number1;
    cout << "Enter number2: ";
    cin >> number2;
    cout << "Enter number3: ";
    cin >> number3;

    if ((number1 > number2) && (number2 > number3)) {
	cout << "increasing";
    } else if ((number1 < number2) && (number2 < number3)) {
	cout << "increasing";
    } else {
	cout << "neither";
    }

    return 0;
}
