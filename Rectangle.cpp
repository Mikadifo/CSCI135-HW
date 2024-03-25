/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Homework E9.5

Class rectangle with methods to compute area, perimeter and resize the ractangle
*/

class Rectangle {
public:
  Rectangle(double width, double height) : width(width), height(height) {}

  double get_perimeter() { return 2 * width + 2 * height; }

  double get_area() { return width * height; }

  void resize(double factor) {
    width *= factor;
    height *= factor;
  }

private:
  double width;
  double height;
};
