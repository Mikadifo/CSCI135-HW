/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: E 8.1

This program opens 'hello.txt', stores the message "Hello, World!" in it, closes
the file, opens it again and reads the message into a variable and prints it.
*/

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string line;
  ofstream fileOut;
  ifstream fileIn;

  fileOut.open("hello.txt");
  fileOut << "Hello, World!";
  fileOut.close();

  fileIn.open("hello.txt");
  getline(fileIn, line);
  cout << line << endl;
  fileIn.close();

  return 0;
}
