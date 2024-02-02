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
#include <vector>
using namespace std;

int main() {
  int size, inSpaces, outSpaces;
  string row;
  vector<string> rows;

  cout << "Enter size: ";
  cin >> size;
  inSpaces = size - 2;

  cout << "Shape:" << endl;

  while (inSpaces >= -1) {
    row = "";
    outSpaces = (size - 2 - inSpaces) / 2;

    row += std::string(outSpaces, ' ');
    if (inSpaces < 0) {
      row += "*";
    } else {
      row += "*" + std::string(inSpaces, ' ') + "*";
    }
    row += std::string(outSpaces, ' ') + '\n';

    inSpaces -= 2;
    rows.push_back(row);
  }

  for (string row : rows) {
    cout << row;
  }

  for (int i = rows.size() - (size % 2 == 0 ? 1 : 2); i < rows.size(); i--) {
    cout << rows[i];
  }

  return 0;
}
