/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 3 B
*/
/*
  This program prints the min and max in East basin in 2018
*/

#include <climits>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string junk, date;
  float eastSt;
  vector<float> eastStValues;

  ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) {
    cerr << "File cannot be opened for reading." << endl;
    exit(1);
  }

  getline(fin, junk);

  int i = 0;
  while (fin >> date >> eastSt) {
    fin.ignore(INT_MAX, '\n');
    cout << eastSt << endl;
    i++;
    eastStValues.push_back(eastSt);
  }

  cout << i << endl;
  cout << eastStValues.size() << endl;

  return 0;
}
