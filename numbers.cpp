/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 5A

Checks if a number is divisible by another and return true or false
*/

#include <iostream>
using namespace std;

bool isDivisibleBy(int n, int d) { return n % d == 0; }

int main() {
  int num1, num2;

  cout << "Enter number 1: ";
  cin >> num1;
  cout << "Enter number 2: ";
  cin >> num2;

  cout << (isDivisibleBy(num1, num2) ? "Yes" : "No") << endl;

  return 0;
}
