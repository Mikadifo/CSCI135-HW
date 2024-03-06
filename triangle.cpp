/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Homework E7.18

This program calculates the perimeter of a triangle
*/

#include <cmath>
#include <iostream>
using namespace std;

class Point {
public:
  double x;
  double y;
};

class Triangle {
public:
  Point a;
  Point b;
  Point c;
};

double distance(Point a, Point b) {
  return sqrt(pow((b.x - a.x), 2) + pow(b.y - a.y, 2));
}

double perimeter(Triangle triangle) {
  double a = distance(triangle.a, triangle.b);
  double b = distance(triangle.b, triangle.c);
  double c = distance(triangle.c, triangle.a);

  return a + b + c;
}

int main() {
  Point pointA = Point({1, 2});
  Point pointB = Point({3, 2});
  Point pointC = Point({3, 6});
  Triangle triangle = Triangle({pointA, pointB, pointC});

  cout << perimeter(triangle) << endl;

  return 0;
}
