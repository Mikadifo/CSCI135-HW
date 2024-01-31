/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 3 A
*/
/*
 This program asks the user for a date and prints the East basin storage on that
 date.
*/

#include <climits>
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
  ifstream fin("Current_Reservoir_Levels.tsv");
  string date, userDate, eastSt, junk;

  cout << "Enter date: ";
  cin >> userDate;

  if (fin.fail()) {
    cerr << "File cannot be opened for reading." << endl;
    exit(1);
  }

  getline(fin, junk);

  while (fin >> date >> eastSt) {
    fin.ignore(INT_MAX, '\n');

    if (date == userDate) {
      cout << "East basin storage: " << eastSt << endl;
      break;
    }
  }

  fin.close();

  return 0;
}
