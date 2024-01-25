/*
Author: Michael Padilla
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab1A

It finds the smaller of 2 integers
*/

#include <iostream>
using namespace std;

int main() {
    int number1, number2;

    cout << "Enter the first number: ";
    cin >> number1;
    cout << "Enter the second number: ";
    cin >> number2;

    cout << (number1 < number2 ? number1 : number2);

    return 0;
}
