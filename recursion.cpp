/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 13 C

This program TODO
*/

#include <iostream>
using namespace std;

int sumRange(int *arr, int left, int right) {
  // TODO: Update validations...
  if (right - left < 0)
    return 0;

  if (right - left == 0)
    return left;

  return arr[left] + sumRange(arr, left + 1, right);
}

int sumArray(int *arr, int size) {
  // TODO: Check how to do it without a helper function
  return sumRange(arr, 0, size - 1);
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
  int size = 10;
  int *arr = new int[size]; // allocate array dynamically
  arr[0] = 12;
  arr[1] = 17;
  arr[2] = -5;
  arr[3] = 3;
  arr[4] = 7;
  arr[5] = -15;
  arr[6] = 27;
  arr[7] = 5;
  arr[8] = 13;
  arr[9] = -21;

  int sum1 = sumArray(arr, size);    // Add all elements
  cout << "Sum is " << sum1 << endl; // Sum is 43

  int sum2 = sumArray(arr, 5);       // Add up first five elements
  cout << "Sum is " << sum2 << endl; // Sum is 34

  delete[] arr; // deallocate it

  return 0;
}
