/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Homework E7.1

This program sorts the values of two given pointers based on what they point to.
*/

#include <iostream>
using namespace std;

void sort2(double *p, double *q) {
  if (*p > *q) {
    double auxP = *p;
    *p = *q;
    *q = auxP;
  }
}

int main() {
  double x = 5.2, y = 3.7;
  // double *xPointer = &x;
  // double *yPointer = &y;

  // cout << *xPointer << endl;
  // cout << *yPointer << endl;
  cout << x << endl;
  cout << y << endl;
  sort2(&x, &y);
  cout << x << endl;
  cout << y << endl;
  // cout << *xPointer << endl;
  // cout << *yPointer << endl;

  return 0;
}
