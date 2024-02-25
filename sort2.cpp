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
    double *aux = p;
    p = q;
    q = aux;
  }
}

int main() {
  double x = 8;
  double *xPointer = &x;
  double y = 3;
  double *yPointer = &y;

  cout << *xPointer << endl;
  cout << *yPointer << endl;
  sort2(xPointer, yPointer);
  cout << *xPointer << endl;
  cout << *yPointer << endl;

  return 0;
}
