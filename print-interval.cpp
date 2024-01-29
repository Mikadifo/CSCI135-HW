/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab1C
*/
/*
 This program asks for 2 numbers and print all number in that interval
*/

#include <iostream>
using namespace std;

int main() {
    int lower, upper;

    cout << "Enter L: ";
    cin >> lower;

    cout << "Enter U: ";
    cin >> upper;

    for (int i = lower; i < upper; i ++) {
	cout << i << " ";
    }

    return 0;
}
