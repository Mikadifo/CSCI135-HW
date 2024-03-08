/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 11 B

This program implements the Network class and its methods
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
  string getFullName() { return displayName + " (@" + username + ")"; }
  void setDisplayName(string displayName) { this->displayName = displayName; };
};

class Network {
private:
  static const int MAX_USERS = 20;
  int numUsers;
  Profile profiles[MAX_USERS];
  int findID(string username) {
    for (int i = 0; i < numUsers; i++) {
      if (profiles[i].getUsername() == username) {
        return i;
      }
    }

    return -1;
  }

public:
  Network() { numUsers = 0; }
  bool addUser(string username, string displayName) {
    if (findID(username) == -1 && numUsers < MAX_USERS) {
      profiles[numUsers] = Profile(username, displayName);
      numUsers++;
      return true;
    }

    return false;
  }
};

int main() {
  Network nw;
  cout << nw.addUser("mario", "Mario") << endl; // true (1)
  cout << nw.addUser("luigi", "Luigi") << endl; // true (1)

  cout << nw.addUser("mario", "Mario2") << endl; // false (0)
  cout << nw.addUser("mario", "Mario2") << endl; // false (0)
  cout << nw.addUser("mario", "Mario2") << endl; // false (0)

  for (int i = 2; i < 20; i++)
    cout << nw.addUser("mario" + to_string(i),
                       "Mario" + to_string(i))
         << endl; // true (1)

  cout << nw.addUser("yoshi", "Yoshi") << endl; // false (0)
}
