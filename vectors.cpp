/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 12A

*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> makeVector(int n) {
  vector<int> numbers;
  for (int i = 0; i < n; i++) {
    numbers.push_back(i);
  }

  return numbers;
}

int main() {
  vector<int> n = makeVector(10);
  for (int num : n) {
    cout << num << endl;
  }

  return 0;
}
