/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 13 A

This program prints numbers in a range using recursion
*/

#include <iostream>
using namespace std;

void printRange(int left, int right) {
  if (left <= right) {
    cout << left << " ";
    printRange(left + 1, right);
  }
}

int main() {
  printRange(-2, 10);
  return 0;
}
