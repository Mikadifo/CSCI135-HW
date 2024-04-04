/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 12C
*/

// This program merges all elements from array 2 into 1

#include <iostream>
#include <vector>
using namespace std;

// This function takes elements from the array vegeta and adds them to goku
void gogeta(vector<int> &goku, vector<int> &vegeta) {
  for (int number : vegeta) {
    goku.push_back(number);
  }

  vegeta.clear();
}

int main() {
  vector<int> v1{1, 2, 3};
  vector<int> v2{4, 5};
  gogeta(v1, v2);
  for (int num : v1) {
    cout << num << endl;
  }
  cout << "---" << endl;
  for (int num : v2) {
    cout << num << endl;
  }

  return 0;
}
