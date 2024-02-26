/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 7 A
*/

// This program reads a cpp file and removes all leading spaces from it.

#include <cctype>
#include <iostream>
using namespace std;

string removeLeadingSpaces(string line) {
  string newLine;

  for (char character : line) {
    if (!isspace(character)) {
      newLine = line.substr(line.find(character));
      break;
    }
  }

  return newLine;
}

int main() {
  string line;

  while (getline(cin, line)) {
    cout << removeLeadingSpaces(line) << endl;
  }

  return 0;
}
