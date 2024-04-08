/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 13 B

This program sums all the numbers within a given range
*/

#include <iostream>
using namespace std;

int sumRange(int left, int right) {
  if (right - left <= 0)
    return left;

  return left + sumRange(left + 1, right);
}

void printRange(int left, int right) {
  if (left <= right) {
    cout << left << " ";
    printRange(left + 1, right);
  }
}

int main() {
  int x = sumRange(1, 3);
  cout << "This is " << x << endl; // 6

  int y = sumRange(-2, 10);
  cout << "That is " << y << endl; // 52
                                   //
  return 0;
}
