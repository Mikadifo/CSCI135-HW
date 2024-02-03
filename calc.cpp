/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 1 B
*/
/*
 This program
*/

#include <iostream>
using namespace std;

int main() {
  int number, total = 0;
  char sign;

  while (cin >> number) {
    if (!sign) {
      total = number;
    } else {
      total = (sign == '+') ? total + number : total - number;
    }
    cin >> sign;
  }

  cout << total << endl;

  return 0;
}
