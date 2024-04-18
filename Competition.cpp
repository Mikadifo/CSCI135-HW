// Defines constructors and methods in Competition.hpp

/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 2D
*/

#include "Competition.hpp"
#include "Hare.hpp"
#include "Road.hpp"
#include "Tortoise.hpp"
#include "iostream"

// Default constructor
Competition::Competition() {
  rabbit = Hare{};
  tor = Tortoise{};
}

/*
 * @param Hare coney
 * @param Tortoise cooter
 * @param int length
 */
Competition::Competition(Hare coney, Tortoise cooter, int length) {
  rabbit = coney;
  tor = cooter;
  lane = Road(length);
}

// Starts the competition and checks when either the Hare or the Tortoise win
void Competition::play() {
  int goal = lane.length() - 1;
  int step = 1;

  while (true) {
    rabbit.move();
    tor.move();

    int rabbitPos = rabbit.getPosition();
    int torPos = tor.getPosition();

    if (rabbitPos >= lane.length() - 1) {
      rabbitPos = lane.length() - 1;
    }

    if (torPos >= lane.length() - 1) {
      torPos = lane.length() - 1;
    }

    lane.mark(torPos, 'T');
    if (rabbitPos == torPos) {
      std::cout << "Ouch! Tortoise bites hare." << std::endl;
    } else {
      lane.mark(rabbitPos, 'H');
    }
    lane.display();

    if (rabbitPos == torPos && rabbitPos >= goal && torPos >= goal) {
      std::cout << "Yuck. Hare wins." << std::endl;
      return;
    }

    if (rabbitPos >= goal) {
      std::cout << "It is a tie." << std::endl;
      return;
    }

    if (torPos >= goal) {
      std::cout << "Yay!!! tortoise wins!" << std::endl;
      return;
    }

    step++;
  }
}
