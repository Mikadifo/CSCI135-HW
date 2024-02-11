/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: E 5.14

This program swaprs the values of a and b if a is greater than b and otherwise
leaves a and b unchanged.
*/

using namespace std;

void sort2(int &a, int &b) {
  if (a > b) {
    int tempA = a;
    a = b;
    b = tempA;
  }
}

int main() { return 0; }
