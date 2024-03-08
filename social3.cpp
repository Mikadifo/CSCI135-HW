/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 11 C

This program creates a Network of users that are following each other and prints
the code for a digraph graph
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
  bool following[MAX_USERS][MAX_USERS];

  // Returns user ID (index in the 'profiles' array) by their username
  // (or -1 if username is not found)
  int findID(string username) {
    for (int i = 0; i < numUsers; i++) {
      if (profiles[i].getUsername() == username) {
        return i;
      }
    }

    return -1;
  }

public:
  Network() {
    numUsers = 0;
    for (int row = 0; row < MAX_USERS; row++) {
      for (int col = 0; col < MAX_USERS; col++) {
        following[row][col] = false;
      }
    }
  }
  // Attempts to sign up a new user with specified username and displayname
  // return true if the operation was successful, otherwise return false
  bool addUser(string username, string displayName) {
    if (findID(username) == -1 && numUsers < MAX_USERS) {
      profiles[numUsers] = Profile(username, displayName);
      numUsers++;
      return true;
    }

    return false;
  }
  // Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
  // return true if success (if both usernames exist), otherwise return false
  bool follow(string username1, string username2) {
    int user1Id = findID(username1);
    int user2Id = findID(username2);

    if (user1Id >= 0 && user2Id >= 0) {
      following[user1Id][user2Id] = true;
      return true;
    }

    return false;
  }
  // Print Dot file (graphical representation of the network)
  void printDot() {
    string graph = "digraph {\n";
    for (int i = 0; i < numUsers; i++) {
      graph += "\"@" + profiles[i].getUsername() + "\"\n";
    }
    for (int row = 0; row < numUsers; row++) {
      for (int col = 0; col < numUsers; col++) {
        if (following[row][col]) {
          graph += "\n\"@" + profiles[row].getUsername() + "\" -> \"@" +
                   profiles[col].getUsername() + "\"";
        }
      }
    }

    graph += "\n}";

    cout << graph << endl;
  }
};

int main() {
  Network nw;
  cout << nw.addUser("mario", "Mario") << endl;
  cout << nw.addUser("luigi", "Luigi") << endl;
  // true (1)
  // true (1)
  cout << nw.addUser("mario", "Mario2") << endl;
  // false (0)
  cout << nw.addUser("mario 2", "Mario2")
       << endl; // false (0) cout « nw. addUser ("mario-2",
                // "Mario2") « endl; // false (0)
  for (int i = 2; i < 20; i++)
    cout << nw.addUser("mario" + to_string(i), "Mario" + to_string(i)) << endl;
  // true (1)
  cout << nw.addUser("yoshi", "Yoshi") << endl;
  // false (0)
}
