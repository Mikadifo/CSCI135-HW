/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: E 5.6

This program returns the middle character in a string if the length is odd,
otherwise the two middle characters.
*/

#include <string>
using namespace std;

string middle(string word) {
  int wordLength = word.length();
  if (wordLength % 2 == 0) {
    return word.substr((wordLength / 2) - 1, 2);
  }

  return word.substr((wordLength - 1) / 2, 1);
}

int main() { return 0; }
