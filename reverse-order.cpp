/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 3 D
*/

/*
 * This program
 */

#include <climits>
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
  string junk, earlyDate, lateDate, date, eastSt, eastEl, westSt, westEl;
  bool dateInRange = false;
  vector<string> dates, elevations;

  cout << "Enter earlier date: ";
  cin >> earlyDate;
  cout << "Enter later date: ";
  cin >> lateDate;

  ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) {
    cerr << "File cannot be opened for reading." << endl;
    exit(1);
  }

  getline(fin, junk);

  while (fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
    fin.ignore(INT_MAX, '\n');

    if (date == earlyDate) {
      dateInRange = true;
    }

    if (dateInRange) {
      dates.push_back(date);
      elevations.push_back(westEl);
    }

    if (date == lateDate) {
      break;
    }
  }

  for (int i = dates.size() - 1; i >= 0; i--) {
    cout << dates[i] << " ";
    cout << elevations[i] << " ft" << endl;
  }

  return 0;
}
