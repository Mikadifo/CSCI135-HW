/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 5 C

This program prints the next prime of a given number
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

int nextPrime(int n) { return isPrime(n + 1) ? n + 1 : nextPrime(n + 1); }

int main() {
  int number;

  cout << "Enter a number: ";
  cin >> number;

  cout << nextPrime(number);

  return 0;
}
