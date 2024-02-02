/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 4 G
*/
/*
 This program prints a 3x3 checkerboard using the given width and height.
*/

#include <iostream>
using namespace std;

int main() {
  int width, height, colRemaining;
  bool isColBlank, isRowBlank = false;

  cout << "Enter width: ";
  cin >> width;
  cout << "Enter height: ";
  cin >> height;

  cout << "Shape:" << endl;

  colRemaining = 0;
  for (int row = 1; row <= height; row++) {
    isColBlank = isRowBlank;
    for (int col = 3; col <= width; col += 3) {
      cout << (isColBlank ? "   " : "***");
      isColBlank = !isColBlank;
      colRemaining = col;
    }
    if (row % 3 == 0) {
      isRowBlank = !isRowBlank;
    }
    cout << (string(width - colRemaining, isColBlank ? ' ' : '*')) << endl;
  }

  return 0;
}
