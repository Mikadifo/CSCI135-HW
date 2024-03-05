/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 9 B

This program checks which is the farthest point to the origin of 2 given 3d
points
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

// This functions returns the length of a given 3d point
double length(Coord3D *p) {
  Coord3D point = *p;
  return sqrt(pow(point.x, 2) + pow(point.y, 2) + pow(point.z, 2));
}

// This functions returns the point that is farthest from the origin
Coord3D *fartherFromOrigin(Coord3D *p1, Coord3D *p2) {
  return length(p1) > length(p2) ? p1 : p2;
}

int main() {
  Coord3D pointP = {10, 20, 30};
  Coord3D pointQ = {0, 1, 2};

  cout << "Address of P: " << &pointP << endl;
  cout << "Address of Q: " << &pointQ << endl << endl;

  Coord3D *ans = fartherFromOrigin(&pointP, &pointQ);

  cout << "ans = " << ans << endl;

  return 0;
}
