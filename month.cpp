/*
Author: Michael Padilla
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab1D

*/
/*
Prints the number of days in a given month
*/

#include <iostream>
using namespace std;

bool isLeap(int year) {
    if (year % 4 != 0) {
	return false;
    } else if (year % 100 != 0) {
	return true;
    } else if (year % 400 != 0) {
	return false;
    } else {
	return true;
    }
}

int main() {
    int year, month;

    cout << "Enter year: ";
    cin >> year;
    cout << "Enter month: ";
    cin >> month;

    if (month == 2) {
	cout << (isLeap(year) ? 29 : 28)  << " days";
	return 0;
    }

    if (month <= 7) {
	if (month % 2 != 0) {
	    cout << 31 << " days";
	} else {
	    cout << 30 << " days";
	}
    } else {
	if (month % 2 != 0) {
	    cout << 30 << " days";
	} else {
	    cout << 31 << " days";
	}
    }

    return 0;
}
