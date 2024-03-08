/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 11 D

This program allows users to write posts
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
  // returns the full name in the format: displayName (@username)
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
  int numUsers;
  int numPosts;
  Post posts[MAX_POSTS];
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
  // Add a new post
  bool writePost(string username, string message) {
    if (findID(username) >= 0 && numPosts < MAX_POSTS) {
      Post newPost = {username, message};
      posts[numPosts] = newPost;
      numPosts++;
      return true;
    }

    return false;
  };
  // Checks if a given username is follow of userId
  bool usernameIsFollow(string username, int userId) {
    for (int col = 0; col < numUsers; col++) {
      if (following[userId][col] && profiles[col].getUsername() == username) {
        return true;
      }
    }
    return false;
  }
  // Print user's "timeline"
  bool printTimeline(string username) {
    int userId = findID(username);

    for (int i = numPosts - 1; i >= 0; i--) {
      if (posts[i].username == username) {
        cout << profiles[userId].getFullName() << ": " << posts[i].message
             << endl;
      }
      if (usernameIsFollow(posts[i].username, userId)) {
        cout << profiles[findID(posts[i].username)].getFullName() << ": "
             << posts[i].message << endl;
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

  nw.follow("mario", "luigi");
  nw.follow("luigi", "mario");
  nw.follow("luigi", "yoshi");
  nw.follow("yoshi", "mario");

  // write some posts
  nw.writePost("mario", "It's a-me, Mario!");
  nw.writePost("luigi", "Hey hey!");
  nw.writePost("mario", "Hi Luigi!");
  nw.writePost("yoshi", "Test 1");
  nw.writePost("yoshi", "Test 2");
  nw.writePost("luigi", "I just hope this crazy plan of yours works!");
  nw.writePost("mario", "My crazy plans always work!");
  nw.writePost("yoshi", "Test 3");
  nw.writePost("yoshi", "Test 4");
  nw.writePost("yoshi", "Test 5");

  cout << endl;
  cout << "======= Mario's timeline =======" << endl;
  nw.printTimeline("mario");
  cout << endl;

  cout << "======= Yoshi's timeline =======" << endl;
  nw.printTimeline("yoshi");
  cout << endl;
}
