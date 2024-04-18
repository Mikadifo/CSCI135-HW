// Defines constructors and methods in Tortoise.hpp

/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 2B
*/

#include "Tortoise.hpp"
#include <cstdlib>

// Default constructor
Tortoise::Tortoise() {
  patterns = {3, 3, 3, 3, 3, -6, -6, 1, 1, 1};
  position = 0;
}

/*
 * @param vector<int> patterns
 * @param int position
 */
Tortoise::Tortoise(std::vector<int> patterns, int position)
    : patterns(patterns), position(position) {}

/*
 * @param int* arr
 * @param int size
 * @param int position
 */
Tortoise::Tortoise(int *arr, int size, int position) {
  this->position = position;
  patterns = std::vector<int>{};

  for (int i = 0; i < size; i++) {
    patterns.push_back(arr[i]);
  }
}

/*
 * @return int position
 */
int Tortoise::getPosition() const { return position; }

/*
 * @param int position
 */
void Tortoise::setPosition(int position) { this->position = position; }

/*
 * Generates a random number and moves the Hare to the new position.
 * It also checks if the new position is within the range of the road(0 to 9).
 */
void Tortoise::move() {
  int randomNumber = rand() % patterns.size();
  position += patterns[randomNumber];
}
