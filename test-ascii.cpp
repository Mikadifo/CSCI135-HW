/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 6 A

This program prints each character of the given string as ASCII
*/

#include <iostream>
using namespace std;

int main() {
  string message;

  cout << "Enter a message: ";
  getline(cin, message);

  for (char character : message) {
    cout << character << " " << int(character) << endl;
  }

  return 0;
}
