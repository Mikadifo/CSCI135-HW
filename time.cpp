/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 10 E

This program checks whether a given movie time slot overlaps with another
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
  line += " (" + to_string(ts.movie.duration) + " min)";
  line += " [starts at " + to_string(ts.startTime.h) + ":" +
          to_string(ts.startTime.m);
  line += ", ends by " + to_string(endsBy.h) + ":" + to_string(endsBy.m) + "]";

  cout << line << endl;
}

// returns a new TimeSlot for the movie nextMovie, scheduled immediately after
// the time slot ts
TimeSlot scheduleAfter(TimeSlot ts, Movie nexMovie) {
  TimeSlot newTimeSlot;
  newTimeSlot.movie = nexMovie;
  newTimeSlot.startTime = addMinutes(ts.startTime, ts.movie.duration);

  return newTimeSlot;
}

// returns true if the two time slots overlap, otherwise return false
bool timeOverlap(TimeSlot ts1, TimeSlot ts2) {
  if (minutesSinceMidnight(ts1.startTime) <
      minutesSinceMidnight(ts2.startTime)) {
    return ts1.movie.duration > minutesUntil(ts1.startTime, ts2.startTime);
  }

  return ts2.movie.duration > minutesUntil(ts2.startTime, ts1.startTime);
}

int main() {
  Movie movie1 = {"Back to the Future", COMEDY, 180};
  Movie movie2 = {"Black Panther", ACTION, 63};

  TimeSlot morning = {movie1, {10, 30}};
  TimeSlot evening = {movie2, {10, 30}};

  printTimeSlot(morning);
  printTimeSlot(evening);

  cout << (timeOverlap(morning, evening) ? "Overlap" : "Free");

  return 0;
}
