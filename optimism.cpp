/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 12B
*/

// This program filters positive numbers from a vector

#include <iostream>
#include <vector>
using namespace std;

// This function returns a vector wiht only positive numbers from a given vector
vector<int> goodVibes(const vector<int> &v) {
  vector<int> numbers;

  for (int number : v) {
    if (number > 0)
      numbers.push_back(number);
  }

  return numbers;
}

int main() {
  vector<int> n{1, 2, -1, 3, 4, -1, 6};
  vector<int> p = goodVibes(n);
  for (int num : p) {
    cout << num << endl;
  }

  return 0;
}
