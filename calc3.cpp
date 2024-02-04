/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 1 D
*/
/*
 This program ...
*/

#include <iostream>
using namespace std;

int main() {
  int number, total = 0;
  char sign, lastSign;

  while (cin >> number >> sign) {
    if (sign == '^') {
      number = number * number;
      cin >> sign;
    }
    if (!lastSign) {
      total = number;
    } else {
      total = (lastSign == '+') ? total + number : total - number;
    }
    lastSign = sign;
    if (sign == ';') {
      cout << total << endl;
      total = 0;
      lastSign = '\0';
    }
  }

  return 0;
}
