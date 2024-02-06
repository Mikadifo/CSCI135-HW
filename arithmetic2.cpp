// This program asks for the number of questions and prompts the user with those
// questions and grades it
/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 1 B
*/

#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
  int OPERATORS[5] = {'+', '-', '*', '/', '%'};
  int questions, randomIndex, firstNumber, secondNumber, result, userAnswer,
      correctAnswers = 0;
  float percentage;
  char randomOperator, grade;

  cout << "Enter the total number of questions to ask: ";
  cin >> questions;

  while (questions <= 0) {
    cout << "The number of questions cannot be zero or negative. Re-enter: ";
    cin >> questions;
  }

  for (int i = 0; i < questions; i++) {
    randomIndex = rand() % 5;
    firstNumber = rand() % 10;
    randomOperator = OPERATORS[randomIndex];

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

    cout << endl << "(" << i + 1 << ") ";
    cout << "what is " << firstNumber << randomOperator << secondNumber << "? ";
    cin >> userAnswer;

    if (userAnswer == result) {
      cout << "true" << endl;
      correctAnswers++;
    } else {
      cout << "false" << endl;
    }
  }

  percentage = correctAnswers * 100.0 / questions;
  if (percentage >= 90)
    grade = 'A';
  else if (percentage >= 80)
    grade = 'B';
  else if (percentage >= 70)
    grade = 'C';
  else if (percentage >= 60)
    grade = 'D';
  else
    grade = 'F';

  cout << endl << "percentage correct: " << percentage << "%" << endl;
  cout << "letter grade: " << grade << endl;

  return 0;
}
