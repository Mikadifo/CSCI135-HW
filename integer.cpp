/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: E3.1

This checks if a integer is positive negative or zero
*/

#include <iostream>
using namespace std;

int main() {
  int number;
  cout << "Enter a integer: ";
  cin >> number;

  if (number == 0) {
    cout << "zero" << endl;
  } else if (number < 0) {
    cout << "negative" << endl;
  } else {
    cout << "positive" << endl;
  }

  return 0;
}
