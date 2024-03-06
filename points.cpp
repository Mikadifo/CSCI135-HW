/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Homework E1.16

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
  return sqrt(pow((b.x - a.x), 2) + pow(b.y - b.x, 2));
}

int main() {
  Point pointA = Point({4, 2});
  Point pointB = Point({6, 0});

  cout << distance(pointA, pointB) << endl;

  return 0;
}
