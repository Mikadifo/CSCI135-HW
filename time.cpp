/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 10 C

This program prints the info of different movies after calculating its time
slots
*/

#include <iostream>
#include <string>
using namespace std;

enum Genre { ACTION, COMEDY, DRAMA, ROMANCE, THRILLER };
static const string genreStrings[] = {"ACTION", "COMEDY", "DRAMA", "ROMANCE",
                                      "THRILLER"};

class Time {
public:
  int h;
  int m;
};

class Movie {
public:
  string title;
  Genre genre;
  int duration;
};

class TimeSlot {
public:
  Movie movie;
  Time startTime;
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

// prints a timeSlot in the format: title GENRE (duration) [starts at startTime,
// ends by Time]
void printTimeSlot(TimeSlot ts) {
  Time endsBy = addMinutes(ts.startTime, ts.movie.duration);
  string line = ts.movie.title + " " + genreStrings[ts.movie.genre];
  line += " (" + to_string(ts.movie.duration) + ")";
  line += " [starts at " + to_string(ts.startTime.h) + ":" +
          to_string(ts.startTime.m);
  line += ", end by " + to_string(endsBy.h) + ":" + to_string(endsBy.m);

  cout << line << endl;
}

int main() {
  Movie movie1 = {"Back to the Future", COMEDY, 116};
  Movie movie2 = {"Black Panther", ACTION, 134};
  Movie movie3 = {"Kung Fu Panda 4", ACTION, 94};
  Movie movie4 = {"Poor Things", ROMANCE, 211};

  TimeSlot morning = {movie1, {9, 15}};
  TimeSlot daytime = {movie2, {12, 15}};
  TimeSlot evening = {movie2, {16, 45}};
  TimeSlot noon = {movie3, {11, 30}};
  TimeSlot lateNight = {movie4, {20, 00}};

  printTimeSlot(morning);
  printTimeSlot(daytime);
  printTimeSlot(evening);
  printTimeSlot(noon);
  printTimeSlot(lateNight);

  return 0;
}
