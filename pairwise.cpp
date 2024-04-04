/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 12D
*/

// This program sums elements at the same index of two arrays

#include <iostream>
#include <vector>
using namespace std;

// This function returns a new vector with the sum of the elements at the same
// index of the 2 given arrays
vector<int> sumPairWise(vector<int> &v1, vector<int> &v2) {
  vector<int> sum;
  int size = v1.size() >= v2.size() ? v1.size() : v2.size();

  for (int i = 0; i < size; i++) {
    if (i >= v1.size()) {
      sum.push_back(v2.at(i));
      continue;
    }
    if (i >= v2.size()) {
      sum.push_back(v1.at(i));
      continue;
    }
    sum.push_back(v2.at(i) + v1.at(i));
  }

  return sum;
}

int main() {
  vector<int> v1{1, 2, 3};
  vector<int> v2{5, 6};
  vector<int> sum = sumPairWise(v1, v2);

  for (int num : sum) {
    cout << num << endl;
  }

  return 0;
}
