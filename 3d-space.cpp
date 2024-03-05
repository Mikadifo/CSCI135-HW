/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 9 A

This program receives the coordinates of a point P passed as a pointer, and
computes the distance from the origin to the point P
*/

#include <cmath>
#include <iostream>
using namespace std;

class Coord3D {
public:
  double x;
  double y;
  double z;
};

double length(Coord3D *p) {
  Coord3D point = *p;
  return sqrt(pow(point.x, 2) + pow(point.y, 2) + pow(point.z, 2));
}

int main() {
  Coord3D pointP = {10, 20, 30};

  cout << length(&pointP) << endl;

  return 0;
}
