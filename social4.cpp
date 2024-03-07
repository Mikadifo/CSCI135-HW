/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 11 D

This program ...
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

struct Post {
  string username;
  string message;
};

class Network {
private:
  static const int MAX_POSTS = 100;
  static const int MAX_USERS = 20;
  int numPosts;
  Post posts[MAX_POSTS];
  int numUsers;
  Profile profiles[MAX_USERS];
  bool following[MAX_USERS][MAX_USERS];
  int findID(string username) {
    for (int i = 0; i < sizeof(profiles); i++) {
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
  bool addUser(string username, string displayName) {
    for (Profile profile : profiles) {
      if (profile.getUsername() == username) {
        return false;
      }
    }
    profiles[numUsers] = Profile(username, displayName);
    numUsers++;

    return true;
  }
  bool follow(string username1, string username2) {
    int user1Id = findID(username1);
    int user2Id = findID(username2);

    if (user1Id >= 0 && user2Id >= 0) {
      following[user1Id][user2Id] = true;
      return true;
    }

    return false;
  }
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
  bool writePost(string username, string message) {
    if (findID(username) > 0 && numPosts < MAX_POSTS) {
      Post newPost = {username, message};
      posts[numPosts] = newPost;
      numPosts++;
      return true;
    }

    return false;
  };
  bool printTimeline(string username) {
    int userId = findID(username);

    // TODO: find where to get post.message
    for (int col = 0; col < numUsers; col++) {
      if (following[userId][col]) {
        cout << profiles[col].getFullName() << ": " << post.message << endl;
      }
    }

    for (Post post : posts) {
      if (post.username == username) {
        cout << profiles[userId].getFullName() << ": " << post.message << endl;
      }
    }

    return false;
  }
};

int main() {
  Network nw;
  // add three users
  nw.addUser("mario", "Mario");
  nw.addUser("luigi", "Luigi");
  nw.addUser("yoshi", "Yoshi");

  // make them follow each other
  nw.follow("mario", "luigi");
  nw.follow("mario", "yoshi");
  nw.follow("luigi", "mario");
  nw.follow("luigi", "yoshi");
  nw.follow("yoshi", "mario");
  nw.follow("yoshi", "luigi");

  // add a user who does not follow others
  nw.addUser("wario", "Wario");

  // add clone users who follow @mario
  for (int i = 2; i < 6; i++) {
    string usrn = "mario" + to_string(i);
    string dspn = "Mario " + to_string(i);
    nw.addUser(usrn, dspn);
    nw.follow(usrn, "mario");
  }
  // additionally, make @mario2 follow @luigi
  nw.follow("mario2", "luigi");

  nw.printDot();

  return 0;
}
