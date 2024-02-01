/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 4 A
*/
/*
 This program  prints a box of asterisks using a given width and height.
*/

#include <iostream>
using namespace std;

int main() {
  int width, height;

  cout << "Enter width: ";
  cin >> width;
  cout << "Enter height: ";
  cin >> height;

  cout << "Shape:" << endl;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cout << "*";
    }
    cout << endl;
  }

  return 0;
}
