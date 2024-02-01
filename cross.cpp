/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 4 C
*/
/*
 This program prints a cross of asterisks using the given size
*/

#include <iostream>
using namespace std;

int main() {
  int size, inSpaces, outSpaces;
  bool isUpHalf = true;

  cout << "Enter size: ";
  cin >> size;
  inSpaces = size - 2;

  cout << "Shape:" << endl;

  for (int row = 0; row < size; row++) {
    outSpaces = size - 2 - inSpaces;

    cout << std::string(outSpaces / 2, ' ');
    cout << "*" << std::string(inSpaces, ' ') << "*";
    cout << std::string(outSpaces / 2, ' ') << endl;

    if (inSpaces == 0) {
      isUpHalf = false;
    }

    if (isUpHalf) {
      inSpaces -= 2;
    } else {
      inSpaces += 2;
    }
  }

  return 0;
}
