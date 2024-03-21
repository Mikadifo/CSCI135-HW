/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 9 D

This program keeps printing poems and storing them dinamically
*/

#include <iostream>
using namespace std;

string *createAPoemDynamically() {
  string *p = new string;
  *p = "Roses are red, violets are blue";

  return p;
}

int main() {
  while (true) {
    string *p;
    p = createAPoemDynamically();

    // assume that the poem p is not needed at this point
    delete p;
  }

  return 0;
}
