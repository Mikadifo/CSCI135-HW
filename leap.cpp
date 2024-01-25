/*
Author: Michael Padilla
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab1C

*/
/*
This finds if the entered year is a leap year or a common year.
*/

#include <iostream>
using namespace std;

int main() {
    int year;

    cout << "Enter a year: ";
    cin >> year;

    if (year % 4 != 0) {
	cout << "Common year";
    } else if (year % 100 != 0) {
	cout << "Leap year";
    } else if (year % 400 != 0) {
	cout << "Common year";
    } else {
	cout << "Leap year";
    }

    return 0;
}
