// Lab Number : CS 008 Lab 1
// Student Name & ID: Chi Chiu Pong, 10413663
// Submission Date: 8/31/2024
// Time taken to complete the code: 90 minutes (Review on String & C-String, Dynamic Memory)

#include <iostream> // for cout, cin
#include <cassert> // for assert()
#include <string> // for string
#include <cstdlib> // for EXIT_SUCCESS
#include <ctime> // for time()
#include <cstring> // for strlen()

using namespace std;

string guessWords[] = { // list of 7 possible words to guess
    "algorithm",
    "university",
    "programming",
    "windows",
    "computer",
    "pasadena",
    "science"
};

static int wordRandGen()
// Precondition: no precondition
// Postcondition: returns a random number between 0 and 6
{
    srand(time(0));
    return rand() % 7;
}

static int charFinder(char* c, const char* answer, char guess)
// Precondition: c is a csting of range of search, answer is a const char array filed with current guesses, guess is a char 
// Postcondition: will find the guess char in answer and replace the corresponding position in c with guess char, return the number of guesses found

{
    int count = 0;
    int length = strlen(answer);

    for (int i = 0; i < length; i++) {
        if (answer[i] == guess) {
            /* cout << "in finder, c is : ";
            for (int i = 0; i < length; i++) {
                cout << c[i];
            }
            cout << endl;
            */
            count++;
            c[i] = guess;
        }
    }
    return count;
}

int main() {

    // 1. pick a random answer from guesswords, answer stores original answer
    string str = guessWords[wordRandGen()];
    // cout << "Rand picked : " << str << endl;
    const char* answer = str.c_str();

    // 2. determine length of string and create a array of the same length with all underscores
    int length = strlen(answer);
    char* c = new char[length + 1];
    fill(c, c + length, '_');
    c[length] = '\0';  // Correctly place the null terminator

    int wrongGuess = 0;
    int correctGuess = 0;

    // 3, Loop until wrongGuess or correctGuess reaches length
    while (wrongGuess < length && correctGuess < length) {
        cout << "Guess the word: ";
        for (int i = 0; i < length; i++) {
            cout << c[i];
        }
        cout << endl;

        cout << "The number of correct guesses: " << correctGuess << endl;
        cout << "Enter a guess character: ";
        char guess;
        cin >> guess;

        cout << "Letter entered : " << guess << endl;

        // 4, check if the guess is in the answer 
        int found = charFinder(c, answer, guess);
        if (found) {
            correctGuess += found;
            cout << "Correct Guess!\n" << endl;
        }
        else {
            wrongGuess++;
            cout << "Incorrect Guess!\n" << endl;
        }
    }

    // 5, determin if we win or lose
    if (correctGuess == length) {
        cout << "You Win!" << endl;
    }
    else {
        cout << "Sorry, you lose. The word was " << str << endl;
    }

    // Clean up dynamically allocated memory
    delete[] c;

    return EXIT_SUCCESS;
}