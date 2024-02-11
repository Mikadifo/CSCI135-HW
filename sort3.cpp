/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: E 5.15

This program swaps the values of a, b and c until their sorted in order.
*/

using namespace std;

void sort2(int &a, int &b) {
  if (a > b) {
    int tempA = a;
    a = b;
    b = tempA;
  }
}

void sort3(int &a, int &b, int &c) {
  sort2(a, b);
  sort2(b, c);
  sort2(a, b);
}

int main() { return 0; }
