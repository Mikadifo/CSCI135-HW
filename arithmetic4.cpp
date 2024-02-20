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
#include <random>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
  vector<pair<string, float>> lines;
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
    istringstream iss(line);
    getline(iss, problem, ',');
    iss >> answer;
    lines.push_back(make_pair(problem, answer));

    questions++;
  }

  fin.close();

  // pick random index from vector, then move it to the end and pick another
  // from 0 to size-1
  int size = lines.size();
  int randomIndex;

  while (size > 0) {
    randomIndex = rand() % size;

    cout << lines[randomIndex].second; // TODO REMOVE THIS LINE
    cout << endl << "(" << questions - size << ") ";
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
      cout << "At least 60% is correct. Stop.";
      return 0;
    }

    swap(lines[randomIndex], lines.back());
    size--;
  }

  cout << endl << "percentage correct: " << percentage << "%" << endl;

  return 0;
}
