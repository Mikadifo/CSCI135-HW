/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 9 E

This program creates coordinates dinamically and calculates their new position
in a given time
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

void move(Coord3D *ppos, Coord3D *pvel, double dt) {
  (*ppos).x = (*ppos).x + (*pvel).x * dt;
  (*ppos).y = (*ppos).y + (*pvel).y * dt;
  (*ppos).z = (*ppos).z + (*pvel).z * dt;
}

Coord3D *createCoord3D(double x, double y, double z) {
  Coord3D *cpointer = new Coord3D;
  (*cpointer).x = x;
  (*cpointer).y = y;
  (*cpointer).z = z;

  return cpointer;
}

void deleteCoord3D(Coord3D *p) { delete p; }

int main() {
  double x, y, z;
  cout << "Enter position: ";
  cin >> x >> y >> z;
  Coord3D *ppos = createCoord3D(x, y, z);

  cout << "Enter velocity: ";
  cin >> x >> y >> z;
  Coord3D *pvel = createCoord3D(x, y, z);

  move(ppos, pvel, 10.0);
  cout << "Coordinates after 10 seconds: " << (*ppos).x << " " << (*ppos).y
       << " " << (*ppos).z << endl;

  deleteCoord3D(ppos);
  deleteCoord3D(pvel);

  return 0;
}
