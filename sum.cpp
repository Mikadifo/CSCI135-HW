/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 1 Task A
*/

/*
 This program reads a sequence of integers from cin and prints their sum.
*/

#include <iostream>
using namespace std;

int main() {
  int number, total = 0;

  while (cin >> number) {
    total += number;
  }

  cout << total << endl;

  return 0;
}
