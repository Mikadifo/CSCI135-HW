/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Homework E 6.8

This function checks whether two arrays have the same elements in the same order
*/

using namespace std;

bool equals(int a[], int a_size, int b[], int b_size) {
  if (a_size != b_size)
    return false;

  for (int i = 0; i < a_size; i++) {
    if (a[i] != b[i])
      return false;
  }

  return true;
}

int main() { return 0; }
