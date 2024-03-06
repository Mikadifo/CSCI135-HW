/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Homework E7.16

This program calculates the distance between two Points
*/

#include <cmath>
#include <iostream>
using namespace std;

class Point {
public:
  double x;
  double y;
};

double distance(Point a, Point b) {
  return sqrt(pow((b.x - a.x), 2) + pow(b.y - a.y, 2));
}

int main() {
  Point pointA = Point({1, 3});
  Point pointB = Point({5, 7});

  cout << distance(pointA, pointB) << endl;

  return 0;
}
