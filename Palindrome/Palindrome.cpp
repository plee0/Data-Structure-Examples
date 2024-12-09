// Palindrome.cpp : Defines the entry point for the application.
//

#include "Palindrome.h"

#include <iostream>
#include <string>
using namespace std;

// Returns True if input string is a Palindrome
// Returns False otherwise
bool isPalindrome(string str, int start, int end) {
    bool isPal;

    // Implement the base case
    if ((end - start) < 1) {
        return true;
        // if there is only one character in the string, end - start will equal 1
        // if there is no character in the string, end - start should equal 0
        // if you have recursively searched through each character and found that 
    }

    // The recursive case
    // All characters changed to lower case first
    if ( tolower(str[start]) == tolower(str[end]) ) {
        isPal = isPalindrome(str, start + 1, end - 1);
    }
    else {
        return false;
    }

    // final final answer
    return isPal;
}

// Remove all non-alphabetic characters from string input
// This includes numbers, symbols, and spaces
string strip(string str) {
    int i = 0;
    while (i < str.length() - 1) {
        while (!isalpha(str[i]) && str[i] != '\0') {
            str.erase(i, 1);
        }
        i++;
    }
    return str;
}

int main() {
    string input;

    // Input from the user
    cout << "Enter a string: ";
    getline(cin, input);

    // Write a function to ignore all the nonalphabetic characters in the string.
    input = strip(input);

    // Call the recursive function and display the result
    if (isPalindrome(input, 0, input.length() - 1)) {
        cout << "The string '" << input << "' is a palindrome." << endl;
    }
    else {
        cout << "The string '" << input << "' is not a palindrome." << endl;
    }

    return 0;
}

// Recursive function to check if a string is a palindrome
