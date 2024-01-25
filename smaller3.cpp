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
    int number1, number2, number3, smallest;

    cout << "Enter the first number: ";
    cin >> number1;
    cout << "Enter the second number: ";
    cin >> number2;
    cout << "Enter the third number: ";
    cin >> number3;

    smallest = (number1 < number2) ? number1 : number2;
    smallest = (smallest < number3) ? smallest : number3;

    cout << "The smaller of the three is " << smallest << endl;
    
    return 0;
}
