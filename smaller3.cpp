/*
Author: Michael Padilla
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab1B

It finds the smaller of 3 integers
*/

#include <iostream>
using namespace std;

int main() {
    int number1, number2, number3;

    cout << "Enter the first number: ";
    cin >> number1;
    cout << "Enter the second number: ";
    cin >> number2;
    cout << "Enter the third number: ";
    cin >> number3;

    if ((number1 < number2) && (number1 < number3)) {
	cout << number1;
    } else if ((number2 < number1) && (number2 < number3)) {
	cout << number2;
    } else {
	cout << number3;
    }
    
    return 0;
}
