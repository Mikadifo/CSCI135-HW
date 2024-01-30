/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 2 D
*/
/*
 This prints a fibonacci sequence
*/

#include <iostream>
using namespace std;

/*
 * As the numbers grow they start to be negative
 */
int main() {
  int fibonacci[60];
  fibonacci[0] = 0;
  fibonacci[1] = 1;

  for (int i = 2; i < 60; i++) {
    fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
  }

  for (int i = 0; i < 60; i++) {
    cout << fibonacci[i] << endl;
  }

  return 0;
}
