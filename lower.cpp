/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 4 D
*/

/*
 This program prints the bottom-left half of a square using a given length.
*/

#include <iostream>
using namespace std;

int main() {
  int length;

  cout << "Enter side length: ";
  cin >> length;

  cout << "Shape:" << endl;

  for (int i = 1; i <= length; i++) {
    cout << std::string(i, '*') << endl;
  }

  return 0;
}
