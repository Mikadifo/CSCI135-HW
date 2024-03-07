/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 11 A

This program creates a Profile and prints its information
*/

#include <iostream>
using namespace std;

class Profile {
private:
  string username;
  string displayName;

public:
  Profile(string username, string displayName)
      : username(username), displayName(displayName){};
  Profile() {
    username = "";
    displayName = "";
  };
  string getUsername() { return username; };
  string getFullName() { return displayName + " (" + username + ")"; }
  void setDisplayName(string displayName) { displayName = displayName; };
};

int main() {
  Profile p1("marco", "Marco");
  cout << p1.getUsername() << endl; // marco
  cout << p1.getFullName() << endl; // Marco (@marco)

  p1.setDisplayName("Marco Rossi");
  cout << p1.getUsername() << endl; // marco
  cout << p1.getFullName() << endl; // Marco Rossi (@marco)

  Profile p2("tarma1", "Tarma Roving");
  cout << p2.getUsername() << endl; // tarma1
  cout << p2.getFullName() << endl; // Tarma Roving (@tarma1)
}
