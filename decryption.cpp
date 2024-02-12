/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 6 D

This program ecnrypts a message using Caesar and Vigenere and then it decrypts a
given Caesar or Vigenere encrypted text
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

  if (rshift < 0) {
    if (ascii >= A_ASCII && ascii <= Z_ASCII) {
      if (newAscii < A_ASCII) {
        newAscii = Z_ASCII + 1 - (A_ASCII - newAscii);
      }
    } else if (newAscii < a_ASCII) {
      newAscii = z_ASCII + 1 - (a_ASCII - newAscii);
    }
  } else {
    if (ascii >= A_ASCII && ascii <= Z_ASCII) {
      if (newAscii > Z_ASCII) {
        newAscii = A_ASCII - 1 + (newAscii - Z_ASCII);
      }
    } else if (newAscii > z_ASCII) {
      newAscii = a_ASCII - 1 + (newAscii - z_ASCII);
    }
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

string encryptCaesar(string plainText, int rshift) {
  string encryptedText;

  for (char character : plainText) {
    if (isalpha(character)) {
      encryptedText += shiftChar(character, rshift);
    } else {
      encryptedText += character;
    }
  }

  return encryptedText;
}

string decryptCaesar(string cipherText, int rshift) {
  string decyptedText;

  for (char character : cipherText) {
    if (isalpha(character)) {
      decyptedText += shiftChar(character, -rshift);
    } else {
      decyptedText += character;
    }
  }

  return decyptedText;
}

string decryptVigenere(string cipherText, string keyword) {
  string decryptedText;
  int keywordIndex = 0;

  for (char character : cipherText) {
    if (isalpha(character)) {
      if (!keyword[keywordIndex]) {
        keywordIndex -= keyword.length();
      }
      int rshift = (int)keyword[keywordIndex] - a_ASCII;
      keywordIndex++;

      decryptedText += shiftChar(character, -rshift);
    } else {
      decryptedText += character;
    }
  }

  return decryptedText;
}

int main() {
  string message, keyword;
  int rshift;

  cout << "Enter a message: ";
  getline(cin, message);

  cout << endl << "--- Caesar ---" << endl;
  cout << "Enter shift: ";
  cin >> rshift;
  string encryptedCaesar = encryptCaesar(message, rshift);
  string decryptedCaesar = decryptCaesar(encryptedCaesar, rshift);
  cout << "Ciphertext: " << encryptedCaesar << endl;
  if (message == decryptedCaesar) {
    cout << "Decrypted: " << decryptedCaesar << endl;
  } else {
    cout << "Decrypted text doesn't match with the original message." << endl;
  }

  cout << endl << "--- Vigenere ---" << endl;
  cout << "Enter a keyword: ";
  cin >> keyword;
  string encryptedVigenere = encryptVigenere(message, keyword);
  string decryptedVigenere = decryptVigenere(encryptedVigenere, keyword);
  cout << "Ciphertext: " << encryptedVigenere << endl;
  if (message == decryptedVigenere) {
    cout << "Decrypted: " << decryptedVigenere << endl;
  } else {
    cout << "Decrypted text doesn't match with the original message." << endl;
  }

  return 0;
}
