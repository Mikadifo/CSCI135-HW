/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 10 A

This program uses a Time class to calculate interval of times in minutes
*/

#include <iostream>
using namespace std;

class Time {
public:
  int h;
  int m;
};

int minutesSinceMidnight(Time time) { return time.h * 60 + time.m; }

int minutesUntil(Time earlier, Time later) {
  return minutesSinceMidnight(later) - minutesSinceMidnight(earlier);
}

int main() {
  int h, m;

  cout << "Enter first time: ";
  cin >> h >> m;
  Time time1 = {h, m};

  cout << "Enter first time: ";
  cin >> h >> m;
  Time time2 = {h, m};

  cout << "These moments of time are " << minutesSinceMidnight(time1) << "and "
       << minutesSinceMidnight(time2) << " minutes after midnight" << endl;
  cout << "The interval between them is " << minutesUntil(time1, time2)
       << " minutes" << endl;

  return 0;
}
