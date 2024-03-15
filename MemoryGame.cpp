#include "MemoryGame.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>

MemoryGame::MemoryGame() : MemoryGame(3, 8) {}

MemoryGame::MemoryGame(int numPairs, int numSlots) {
  if (numPairs < 0 || numSlots < 0 || numSlots < numPairs * 2) {
    this->numPairs = 3;
    this->numSlots = 8;
  } else {
    this->numPairs = numPairs;
    this->numSlots = numSlots;
  }

  values = new string[numSlots];
  for (int i = 0; i < numSlots; i += 2) {
    if (i < numPairs * 2) {
      int random = rand() % 1000;
      values[i] = to_string(random);
      values[i + 1] = to_string(random);
    } else {
      values[i] = "";
      if (numSlots % 2 == 0) {
        values[i + 1] = "";
      }
    }
  }

  bShown = new bool[numSlots];
  for (int i = 0; i < numSlots; i++) {
    bShown[i] = false;
  }
}

MemoryGame::MemoryGame(string *words, int size, int numSlots) {
  if (size < 0 || numSlots < 0 || numSlots < size * 2) {
    numSlots = 2 * size;
  }

  numPairs = size;
  this->numSlots = numSlots;

  values = new string[numSlots];
  int j = 0;

  for (int i = 0; i < numSlots; i += 2) {
    if (i < size * 2) {
      values[i] = words[i / 2];
      values[i + 1] = words[i / 2];
    } else {
      values[i] = "";
      if (numSlots % 2 == 0) {
        values[i + 1] = "";
      }
    }
  }

  bShown = new bool[numSlots];
  for (int i = 0; i < numSlots; i++) {
    bShown[i] = false;
  }
}

MemoryGame::~MemoryGame() {
  delete[] values;
  values = nullptr;
  delete[] bShown;
  bShown = nullptr;
}

void MemoryGame::randomize() {
  int size = numSlots;
  int randomIndex;

  while (size > 1) {
    randomIndex = rand() % size;
    swap(values[randomIndex], values[size - 1]);
    size--;
  }
}

void printSeparatedLine(int size) {
  cout << "+"; // the first +
  // draw -----+ for (size) many times
  for (int i = 0; i < size; i++)
    cout << "-----+";
  cout << endl;
}

void MemoryGame::display() const {}
