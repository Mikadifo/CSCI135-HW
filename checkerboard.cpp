/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 4 B
*/
/*
 This program prints a checkerboard using a given width and height
*/

#include <iostream>
using namespace std;

int main() {
  int width, height;
  bool isSpace;

  cout << "Enter width: ";
  cin >> width;
  cout << "Enter height: ";
  cin >> height;

  cout << "Shape: " << endl;

  for (int i = 0; i < height; i++) {
    isSpace = i % 2 != 0;
    for (int j = 0; j < width; j++) {
      cout << (isSpace ? " " : "*");
      isSpace = !isSpace;
    }
    cout << endl;
  }

  return 0;
}
