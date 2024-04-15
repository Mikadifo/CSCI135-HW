/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 13 F

This program checks if a collection of paints can be evenly divided by 2 based
on their price
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

bool divisible(int *prices, int size, int i, int left, int right, int sum) {
  if (i == size) {
    return left == right;
  }

  if (left > sum || right > sum) {
    return false;
  }

  if (divisible(prices, size, i + 1, left + prices[i], right, sum)) {
    return true;
  }

  if (divisible(prices, size, i + 1, left, right + prices[i], sum)) {
    return true;
  }

  return false;
}

bool divisible(int *prices, int size) {
  int sum = 0;

  for (int i = 0; i < size; i++) {
    sum += prices[i];
  }

  return divisible(prices, size, 0, 0, 0, sum / 2);
}

int main() {
  int prices[] = {10, 15, 12, 18, 19, 17, 13, 35, 33};

  bool result = divisible(prices, sizeof(prices) / sizeof(int));

  cout << result << endl;

  return 0;
}
