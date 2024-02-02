/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 4 E
*/

/*
 This program print the top-half part of a square using a given length.
*/

#include <iostream>
using namespace std;

int main() {
  int length;

  cout << "Enter side length: ";
  cin >> length;

  cout << "Shape:" << endl;

  for (int i = length; i > 0; i--) {
    cout << std::string(length - i, ' ');
    cout << std::string(i, '*') << endl;
  }

  return 0;
}
