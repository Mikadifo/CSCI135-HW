/*
Author: Michael Padilla
Course: CSCI-136
Instructor: Tong Yi
Assignment: Homework E3.8

Prints out a word given by the user one character per line.
*/

#include <iostream>
using namespace std;

int main() {
    string word;

    cout << "Enter a word: ";
    cin >> word;

    for (int i = 0; i < word.length(); i ++) {
	cout << word[i] << endl;
    }

    return 0;
}
