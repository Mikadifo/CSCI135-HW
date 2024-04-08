/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 13 D

This program checks if a given string is alphanumeric using recursion
*/

#include <cctype>
#include <iostream>
using namespace std;

bool isAlphanumeric(string s) {
  if (s.length() == 0)
    return true;

  if (!isalnum(s[0]))
    return false;

  return isAlphanumeric(s.substr(1));
}

int sumArray(int *arr, int size) {
  if (size <= 0)
    return 0;

  return arr[size - 1] + sumArray(arr, size - 1);
}

int sumRange(int left, int right) {
  if (right - left < 0)
    return 0;

  if (right - left == 0)
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
  cout << isAlphanumeric("ABCD") << endl;        // true (1)
  cout << isAlphanumeric("Abcd1234xyz") << endl; // true (1)
  cout << isAlphanumeric("KLMN 8-7-6") << endl;  // false (0)

  return 0;
}
