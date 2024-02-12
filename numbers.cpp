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

int largestTwinPrime(int a, int b) {
  for (int i = b; i >= a; i--) {
    if (isTwinPrime(i)) {
      return i;
    }
  }

  return -1;
}

int main() {
  int number1, number2;

  cout << "Enter a number: ";
  cin >> number1;
  cout << "Enter a number: ";
  cin >> number2;

  cout << largestTwinPrime(number1, number2);

  return 0;
}
