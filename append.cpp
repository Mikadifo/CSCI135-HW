/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Homework E6.18

This program appends one vector after another
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> append(vector<int> a, vector<int> b) {
  for (int number : b)
    a.push_back(number);

  return a;
}

int main() {
  vector<int> a = {1, 4, 9, 16};
  vector<int> b = {9, 7, 4, 9, 11};

  for (int number : append(a, b))
    cout << number << endl;

  return 0;
}
