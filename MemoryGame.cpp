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

void MemoryGame::display() const {
  cout << " ";
  for (int i = 0; i < numSlots; i++)
    cout << setw(3) << i << setw(3) << " ";
  // setw(3) before i means i occupies 3-character,
  // For example, if i has only two digits,
  // then pad a space to its left.
  cout << endl;
  printSeparatedLine(numSlots);
  cout << "|";
  for (int i = 0; i < numSlots; i++) {
    if (bShown[i]) {
      if (values[i] == "") {
        cout << setw(6) << "|";
      } else {
        cout << setw(5) << values[i] << "|";
      }
    } else {
      cout << setw(6) << "|";
    }
  }
  cout << endl;
  printSeparatedLine(numSlots);
}

int MemoryGame::input() const {
  int userInput;
  bool inputOutOfRange, cardFlipped;

  cout << "Enter a unfipped card in [0, " << numSlots - 1 << "]: ";
  cin >> userInput;

  inputOutOfRange = userInput < 0 || userInput >= numSlots;
  cardFlipped = bShown[userInput];

  while (inputOutOfRange || cardFlipped) {
    if (inputOutOfRange) {
      cout << "input is not in [0, " << numSlots - 1 << "]. Re-enter: ";
      cin >> userInput;
    } else if (cardFlipped) {
      cout << "The card is flipped already. Re-enter: ";
      cin >> userInput;
    }

    inputOutOfRange = userInput < 0 || userInput >= numSlots;
    cardFlipped = bShown[userInput];
  }

  return userInput;
}

void MemoryGame::play() {
  int round = 1, lastInput, newInput, pairs = 0;
  bool isGuessing = false;

  randomize();
  display();
  while (pairs < numPairs) {
    cout << "Round " << round << ":" << endl;
    newInput = input();

    if (!isGuessing) {
      bShown[newInput] = true;
    } else if (values[lastInput] == values[newInput]) {
      bShown[newInput] = true;
      pairs++;
    } else {
      bShown[lastInput] = false;
    }
    isGuessing = !isGuessing;
    round++;
    lastInput = newInput;
    display();
  }

  cout << "Congratulations! Found out all pairs in " << round - 1 << " rounds";
}
