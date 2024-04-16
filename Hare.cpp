// Defines constructors and methods in Hare.hpp

/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 2A
*/

#include "Hare.hpp"
#include <cstdlib>

// Default constructor
Hare::Hare() {
  patterns = {0, 0, 9, 9, -12, 1, 1, 1, -2, -2};
  position = 0;
}

/*
 * @param vector<int> patterns
 * @param int position
 */
Hare::Hare(std::vector<int> patterns, int position)
    : patterns(patterns), position(position) {}

/*
 * @param int* arr
 * @param int size
 * @param int position
 */
Hare::Hare(int *arr, int size, int position) {
  this->position = position;
  patterns = std::vector<int>{};

  for (int i = 0; i < size; i++) {
    patterns.push_back(arr[i]);
  }
}

/*
 * @return int position
 */
int Hare::getPosition() const { return position; }

/*
 * @param int position
 */
void Hare::setPosition(int position) { this->position = position; }

/*
 * Generates a random number and moves the Hare to the new position.
 * It also checks if the new position is within the range of the road(0 to 9).
 */
void Hare::move() {
  int randomNumber = rand() % patterns.size();
  position += patterns[randomNumber];

  if (position < 0) {
    position = 0;
  }
}
