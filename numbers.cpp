/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 5 D

This program counts the number of primes in the interval a <= x <= b.
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

int countPrimes(int a, int b) {
  int total = 0;

  for (int i = a; i <= b; i++) {
    if (isPrime(i)) {
      total++;
    }
  }

  return total;
}

int main() {
  int a, b;

  cout << "Enter a number: ";
  cin >> a;
  cout << "Enter a number: ";
  cin >> b;

  cout << countPrimes(a, b);

  return 0;
}
