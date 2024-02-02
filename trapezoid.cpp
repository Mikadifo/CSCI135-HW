/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 4 F
*/

/*
 This program print an upside-down trapezoid of a given width and height.
*/

#include <iostream>
using namespace std;

int main() {
  int width, height;
  int spaces = 0;

  cout << "Enter width: ";
  cin >> width;
  cout << "Enter height: ";
  cin >> height;

  cout << "Shape:" << endl;

  if (2 * height - 1 >= width) {
    cout << "Impossible shape!";
    return 0;
  }

  for (int i = 0; i < height; i++) {
    cout << std::string(spaces, ' ');
    cout << std::string(width, '*');
    cout << std::string(spaces, ' ') << endl;
    width -= 2;
    spaces += 1;
  }

  return 0;
}
