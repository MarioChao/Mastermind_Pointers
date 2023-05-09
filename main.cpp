#include <iostream>
#include "inc/setup.h"
#include "inc/gameplay.h"
using namespace std;

bool isDebug = false;

void printInfo() {
    // Print info
    cout << '\n';
    cout << "Welcome to Mastermind!\n";
    cout << "This is a code-breaking game, based on the board game \"Mastermind\"!\n";
    cout << '\n';
    cout << "After you make each guess, you will be provided with a feedback of three numbers:\n";
    cout << "-the number of correct numbers in correct positions \"C\",\n";
    cout << "-the number of correct numbers in wrong positions \"W\",\n";
    cout << "-the total number of extra numbers and wrong numbers \"E\".\n";
    cout << '\n';
    cout << "All numbers generated will be single-digit (between 0 and 9, inclusive).\n";
    cout << "Enjoy!\n";
    cout << '\n';
}

void runProgram() {
    // Print info
    printInfo();

    // Setup
    int *flag, flagSize;
    setup(&flag, &flagSize);
    // Debug (print the code)
    if (isDebug) {
        for (int i = 0; i < flagSize; i++) {
            cout << *(flag + i) << ' ';
        }
        cout << '\n';
    }

    // Gameplay
    playGame(flag, flagSize);
    // Print array
    cout << "The code is:\n";
    for (int i = 0; i < flagSize; i++) {
        cout << *(flag + i) << ' ';
    }
    cout << '\n';

    // Delete
    delete[] flag;
}

int main() {
    runProgram();
}