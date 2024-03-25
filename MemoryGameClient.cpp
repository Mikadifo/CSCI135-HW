#include "MemoryGame.hpp"

using namespace std;

int main() {
  MemoryGame game;
  game.play();
  game.~MemoryGame();

  string words[] = {"Hello", "Hi"};
  int size = sizeof(words) / sizeof(words[0]);
  MemoryGame game2(words, size, 7);
  game.play();
  game2.~MemoryGame();

  return 0;
}
