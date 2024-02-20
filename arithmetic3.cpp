// This program opens a csv file with arithmetic problems and asks the user for
// the answers, finally it assigns a grade based on a correcteness percentage
/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 1 C
*/

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
  string line, problem;
  float answer, userAnswer, percentage;
  int questions = 0, correctQuestions = 0;
  char grade;

  ifstream fin("problems.csv");
  if (fin.fail()) {
    cerr << "File cannot be opened for reading." << endl;
    exit(1);
  }

  while (getline(fin, line)) {
    questions++;
    istringstream iss(line);

    getline(iss, problem, ',');
    cout << endl << "(" << questions << ") ";
    cout << "what is " << problem << "? ";
    cin >> userAnswer;
    iss >> answer;

    if (answer == userAnswer) {
      cout << "true" << endl;
      correctQuestions++;
    } else {
      cout << "false" << endl;
    }
  }

  fin.close();

  percentage = correctQuestions * 100.0 / questions;
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
  cout << "letter grade: " << grade;

  return 0;
}
