/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 9 C

This program calculates the new position of a 3d point given a initial pos,
velocity and time
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

int main() {
  Coord3D pos = {0, 0, 100.0};
  Coord3D vel = {1, -5, 0.2};

  move(&pos, &vel, 2.0);
  cout << pos.x << " " << pos.y << " " << pos.z << endl;

  return 0;
}
