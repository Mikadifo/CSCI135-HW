/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 6 C

This program implements a Vigenere cipher encryption with a keyword
*/

#include <cctype>
#include <iostream>
#include <string>
using namespace std;

const int Z_ASCII = 90;
const int A_ASCII = 65;
const int z_ASCII = 122;
const int a_ASCII = 97;

char shiftChar(char c, int rshift) {
  int ascii = (int)c;
  int newAscii = ascii + rshift;

  if (ascii >= A_ASCII && ascii <= Z_ASCII) {
    if (newAscii > Z_ASCII) {
      newAscii = A_ASCII - 1 + (newAscii - Z_ASCII);
    }
  } else if (newAscii > z_ASCII) {
    newAscii = a_ASCII - 1 + (newAscii - z_ASCII);
  }

  return (char)newAscii;
}

string encryptVigenere(string plainText, string keyword) {
  string encryptedText;
  int keywordIndex = 0;

  for (char character : plainText) {
    if (isalpha(character)) {
      if (!keyword[keywordIndex]) {
        keywordIndex -= keyword.length();
      }
      int rshift = (int)keyword[keywordIndex] - a_ASCII;
      keywordIndex++;

      encryptedText += shiftChar(character, rshift);
    } else {
      encryptedText += character;
    }
  }

  return encryptedText;
}

int main() {
  string message, keyword;

  cout << "Enter a message: ";
  getline(cin, message);

  cout << "Enter a keyword: ";
  cin >> keyword;

  cout << "Ciphertext: " << encryptVigenere(message, keyword) << endl;

  return 0;
}
