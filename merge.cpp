/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Homework E6.20

This program merges two sorted vectors
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> merge_sorted(vector<int> a, vector<int> b) {
  for (int number : b)
    a.push_back(number);

  sort(a.begin(), a.end());

  return a;
}

int main() {
  vector<int> a = {1, 4, 9, 16};
  vector<int> b = {4, 7, 9, 9, 11};

  for (int number : merge_sorted(a, b))
    cout << number << endl;

  return 0;
}
