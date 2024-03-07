/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 10 B

This program asks the users for a time and how many minutes extra will be added
to the time and return a new moment of time
*/

#include <iostream>
using namespace std;

class Time {
public:
  int h;
  int m;
};

// returns the number of minutes from 0:00AM until time
int minutesSinceMidnight(Time time) { return time.h * 60 + time.m; }

// returns how many minutes separate the two moments
int minutesUntil(Time earlier, Time later) {
  return minutesSinceMidnight(later) - minutesSinceMidnight(earlier);
}

// returns a new moment of time that is min minutes after time0
Time addMinutes(Time time0, int min) {
  int newMin = time0.m + min;
  int extraHours = newMin / 60;
  Time time;
  time.h = time0.h + extraHours;
  time.m = time0.m + min - 60 * extraHours;

  return time;
}

int main() {
  int h, m, mins;

  cout << "Enter time: ";
  cin >> h >> m;
  cout << "Enter extra minutes: ";
  cin >> mins;

  Time time = {h, m};
  time = addMinutes(time, mins);

  cout << "New Time: " << time.h << ":" << time.m << endl;

  return 0;
}
