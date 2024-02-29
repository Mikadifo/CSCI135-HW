/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 8 B

This program reads an image and draws a one-pixel border in the middle of it
*/

#include <cassert>
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

const int MAX_H = 512;
const int MAX_W = 512;

// Reads a PGM file.
// Notice that: height and width are passed by reference!
void readImage(int image[MAX_H][MAX_W], int &height, int &width) {
  char c;
  int x;
  ifstream instr;
  instr.open("inImage.pgm");

  // read the header P2
  instr >> c;
  assert(c == 'P');
  instr >> c;
  assert(c == '2');

  // skip the comments (if any)
  while ((instr >> ws).peek() == '#') {
    instr.ignore(4096, '\n');
  }

  instr >> width;
  instr >> height;

  assert(width <= MAX_W);
  assert(height <= MAX_H);
  int max;
  instr >> max;
  assert(max == 255);

  for (int row = 0; row < height; row++)
    for (int col = 0; col < width; col++)
      instr >> image[row][col];
  instr.close();
  return;
}

// Writes a PGM file
// Need to provide the array data and the image dimensions
void writeImage(int image[MAX_H][MAX_W], int height, int width) {
  ofstream ostr;
  ostr.open("outImage.pgm");
  if (ostr.fail()) {
    cout << "Unable to write file\n";
    exit(1);
  };

  // print the header
  ostr << "P2" << endl;
  // width, height
  ostr << width << ' ';
  ostr << height << endl;
  ostr << 255 << endl;

  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      assert(image[row][col] < 256);
      assert(image[row][col] >= 0);
      ostr << image[row][col] << ' ';
      ostr << endl;
    }
  }
  ostr.close();
  return;
}

// It receives a color number between 0-255 and return the inverse
// If colorNumber = 253 this will return 2
int getInverseColor(int colorNumber) { return 255 - colorNumber; }

// This function checks if a given number is within the half of a specified size
bool numberInCenter(int number, int size) {
  return number >= size / 2 && number <= size + (size / 2);
}

// This function checks if a given pixel is within the range of a 1px box in the
// middle of the
bool isWithinBoxBorder(int col, int row, int width, int height) {
  bool numberInTop = row == height / 2;
  bool numberInBottom = row == (height * 2 - height / 2) - 1;
  bool numberInLeft = col == width / 2 + 1;
  bool numberInRight = col == (width + width / 2) + 1;

  return (numberInCenter(col, width) && numberInTop) ||
         (numberInCenter(col, width) && numberInBottom) ||
         (numberInCenter(row, height) && numberInLeft) ||
         (numberInCenter(row, height) && numberInRight);
}

int main() {

  int img[MAX_H][MAX_W];
  int height, width;

  readImage(img, height,
            width); // read it from the file "inImage.pgm"
                    // height and width were passed by reference and
                    // now contain the dimensions of the picture
  // and the 2-dimesional array img contains the image data

  // Now we can manipulate the image the way we like
  // for example we copy its contents into a new array
  int out[MAX_H][MAX_W];
  int halfWidth = width / 2;
  int halfHeight = height / 2;

  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      if (isWithinBoxBorder(col, row, halfWidth, halfHeight)) {
        out[row][col] = 255;
      } else {
        out[row][col] = img[row][col];
      }
    }
  }

  // and save this new image to file "outImage.pgm"
  writeImage(out, height, width);

  return 0;
}
