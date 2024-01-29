/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: E1.7

This program asks the user for 3 names and prints them out.
*/

#include <iostream>
using namespace std;

int main() {
  string firstName, secondName, thirdName;

  cout << "Enter first name: ";
  cin >> firstName;
  cout << "Enter second name: ";
  cin >> secondName;
  cout << "Enter third name: ";
  cin >> thirdName;

  cout << firstName << endl << secondName << endl << thirdName << endl;

  return 0;
}
