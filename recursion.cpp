/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 13 F

This program TODO
*/

#include <cctype>
#include <iostream>
using namespace std;

int nestedParens(string s, int counter) {
  if (s.length() == 0)
    return counter;

  if (s[0] == ')' && s[1] == '(') {
    return 1;
  }

  if (s[0] == '(') {
    counter++;
  } else if (s[0] == ')') {
    counter--;
  } else {
    return 1;
  }

  return nestedParens(s.substr(1), counter);
}

bool nestedParens(string s) {
  if (s.length() == 0)
    return true;

  if (s[0] != '(')
    return false;

  return nestedParens(s, 0) == 0;
}

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

bool divisible(int *prices, int size) {
  // TODO

  return true;
}

int main() {
  // TODO

  return 0;
}
