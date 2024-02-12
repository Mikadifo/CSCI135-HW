/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 5 E

This program checks if a number is a twin prime
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
  // cout << endl << isPrime(n - 2) << endl;
  // cout << isPrime(n + 2) << endl;

  return isPrime(n - 2) || isPrime(n + 2);
}

int main() {
  int number;

  cout << "Enter a number: ";
  cin >> number;

  cout << number
       << (isTwinPrime(number) ? " is a twin prime" : "is not a twin prime");

  return 0;
}
