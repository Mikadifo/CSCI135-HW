// This program prompts the user with random questions from a csv file and stops
// if the percentage of correct answers is at least 60% otherwise it prints the
// total percentage.

/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 1 D
*/

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
  vector<pair<string, float>> lines;
  string line, problem;
  float answer, userAnswer, percentage;
  int questions = 0, correctQuestions = 0, randomIndex;
  char grade;

  ifstream fin("problems.csv");
  if (fin.fail()) {
    cerr << "File cannot be opened for reading." << endl;
    exit(1);
  }

  while (getline(fin, line)) {
    istringstream iss(line);
    getline(iss, problem, ',');
    iss >> answer;
    lines.push_back(make_pair(problem, answer));
    questions++;
  }

  fin.close();

  while (lines.size() > 0) {
    randomIndex = rand() % lines.size();

    cout << "(" << questions - lines.size() + 1 << ") ";
    cout << "what is " << lines[randomIndex].first << "? ";
    cin >> userAnswer;

    if (lines[randomIndex].second == userAnswer) {
      cout << "true" << endl;
      correctQuestions++;
    } else {
      cout << "false" << endl;
    }

    percentage = correctQuestions * 100.0 / questions;
    if (percentage >= 60) {
      cout << endl << "percentage correct: " << percentage << "%" << endl;
      cout << endl << "At least 60% is correct. Stop." << endl;
      return 0;
    }

    lines.erase(lines.begin() + randomIndex);
  }

  cout << endl << "percentage correct: " << percentage << "%" << endl;

  return 0;
}
