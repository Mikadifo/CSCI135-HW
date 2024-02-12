/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 6 B

This program implements a Caesar cipher encryption
*/

#include <cctype>
#include <iostream>
#include <string>
using namespace std;

const int Z_ASCII = 90;
const int z_ASCII = 122;
const int A_ASCII = 65;
const int a_ASCII = 97;

char shiftChar(char c, int rshift) {
  if (!isalpha(c)) {
    return c;
  }

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

string encryptCaesar(string plainText, int rshift) {
  string encryptedText;

  for (char character : plainText) {
    encryptedText += shiftChar(character, rshift);
  }

  return encryptedText;
}

int main() {
  string message;
  int rightShift;

  cout << "Enter a message: ";
  getline(cin, message);

  cout << "Enter shift: ";
  cin >> rightShift;

  cout << "Ciphertext: " << encryptCaesar(message, rightShift) << endl;

  return 0;
}
