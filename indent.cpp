/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 7 B
*/

//

#include <algorithm>
#include <cctype>
#include <iostream>

using namespace std;

int countChar(string line, char c) {
  return count(line.begin(), line.end(), c);
}

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
  int open = 0;

  while (getline(cin, line)) {
    line = removeLeadingSpaces(line);
    if (line[0] == '}') {
      line = string(open - 1, '\t') + line;
    } else {
      line = string(open, '\t') + line;
    }
    cout << line << endl;
    open += countChar(line, '{');
    open -= countChar(line, '}');
  }

  return 0;
}
