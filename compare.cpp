/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 3 B
*/

/*
 This program compares the elevation of basins based on two dates as an
 interval.
 */

#include <climits>
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
  string dateStart, dateEnd, junk, date, eastSt, westSt;
  float eastEl, westEl;
  bool dateInRange = false;
  ifstream fin("Current_Reservoir_Levels.tsv");

  cout << "Enter starting date: ";
  cin >> dateStart;
  cout << "Enter ending date: ";
  cin >> dateEnd;

  if (fin.fail()) {
    cerr << "File cannot be opened for reading." << endl;
    exit(1);
  }

  getline(fin, junk);

  while (fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
    fin.ignore(INT_MAX, '\n');

    if (date == dateStart) {
      dateInRange = true;
    }

    if (dateInRange) {
      if (eastEl > westEl) {
        cout << date << " "
             << "East" << endl;
      } else if (eastEl < westEl) {
        cout << date << " "
             << "West" << endl;
      } else {
        cout << date << " "
             << "Equal" << endl;
      }
    }

    if (date == dateEnd) {
      break;
    }
  }

  return 0;
}
