// This program creates a random mathematical problem and tests if the user's
// answer is correct

/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 1 Task A
*/

#include <cstdlib>
#include <ctime>
#include <ios>
#include <iostream>

using namespace std;

int main() {
  srand(time(NULL));

  int OPERATORS[] = {'+', '-', '*', '/', '%'};
  int randomIndex = rand() % 6;
  int firstNumber = rand() % 10;
  int secondNumber, result, userAnswer;
  char randomOperator = OPERATORS[randomIndex];

  if (randomOperator == '/' || randomOperator == '%') {
    secondNumber = rand() % 9 + 1;
  } else {
    secondNumber = rand() % 10;
  }

  result = firstNumber;
  if (randomOperator == '+')
    result += secondNumber;
  else if (randomOperator == '-')
    result -= secondNumber;
  else if (randomOperator == '*')
    result *= secondNumber;
  else if (randomOperator == '/')
    result /= secondNumber;
  else
    result %= secondNumber;

  cout << "What is " << firstNumber << randomOperator << secondNumber << "? ";
  cin >> userAnswer;

  cout << boolalpha << (userAnswer == result) << endl;

  return 0;
}
