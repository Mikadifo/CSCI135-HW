// Defines constructors and methods in Road.hpp

/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 2C
*/

#include "Road.hpp"
#include <iostream>
#include <vector>

// Default constructor
Road::Road() : Road(70) {}

/*
 * @param int length
 */
Road::Road(int length) {
  blocks = std::vector<char>{};

  if (length < 0) {
    length = 70;
  }

  for (int i = 0; i < length; i++) {
    blocks.push_back(' ');
  }
}

/*
 * @param int index
 * @param char ch
 */
void Road::mark(int index, char ch) { blocks.at(index) = ch; }

/*
 * Displays the current road
 */
void Road::display() const {
  for (char block : blocks) {
    std::cout << block;
  }

  std::cout << std::endl;
}

/*
 * @return int length
 */
int Road::length() const { return blocks.size(); }
