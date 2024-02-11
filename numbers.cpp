/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 5 B

This program checks if a number is prime
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

int main() {
  int number;

  cout << "Enter a number: ";
  cin >> number;

  cout << number << (isPrime(number) ? " is prime" : " is not prime") << endl;

  return 0;
}
