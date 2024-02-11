/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: E 5.15

This program swaps the values of a, b and c until their sorted in order.
*/

#include <iostream>
using namespace std;

void sort2(int &a, int &b) {
  if (a > b) {
    int tempA = a;
    a = b;
    b = tempA;
  }
}

void sort3(int &a, int &b, int &c) {
  sort2(b, c);
  sort2(a, b);
}

int main() {
  // int v = 1, w = 3, x = 5;

  // cout << v << " " << w << " " << x << endl;
  // sort3(v, w, x); // unchanged
  // cout << v << " " << w << " " << x << endl;
  return 0;
}
