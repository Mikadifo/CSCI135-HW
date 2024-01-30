/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 2 A
*/
/*
    Asks the user for a number between 0 and 100.
*/

#include <iostream>
using namespace std;

int main() {
  int number;
  do {
    cout << "Enter a number between 0 and 100: ";
    cin >> number;
  } while (number <= 0 || number >= 100);

  cout << "Number squared is " << number * number << endl;

  return 0;
}
