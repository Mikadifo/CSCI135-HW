/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 5 E

This program return the next twin prime of a given number
*/

#include <iostream>
using namespace std;

bool isPrime(int n) {
  for (int i = 2; i < n - 1; i++) {
    if (n % i == 0) {
      return false;
    }
  }

  return n > 1;
}

bool isTwinPrime(int n) {
  return isPrime(n) && (isPrime(n - 2) || isPrime(n + 2));
}

int nextTwinPrime(int n) {
  return isTwinPrime(n + 1) ? n + 1 : nextTwinPrime(n + 1);
}

int main() {
  int number;

  cout << "Enter a number: ";
  cin >> number;

  cout << nextTwinPrime(number);

  return 0;
}
