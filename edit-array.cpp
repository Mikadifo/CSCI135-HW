/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: title, e.g., Lab1A
*/
/*
 This program 
*/

#include <iostream>
using namespace std;

int main() {
    int myData[10];
    int cell, value;

    for (int i = 0; i < 10; i ++) {
	myData[i] = 1;
    }

    do {
	for (int i = 0; i < 10; i ++) {
	    cout << myData[i] << " ";
	}

	cout << endl << "Index input: ";
	cin >> cell;
	cout << "Value input: ";
	cin >> value;

	myData[cell] = value;
    } while (cell >= 0 && cell < 10);


    cout << "Index out of range. Exit";

    return 0;
}
