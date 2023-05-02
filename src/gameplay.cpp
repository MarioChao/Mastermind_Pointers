#include "../inc/gameplay.h"

bool compareGuess(int *, int *, int, string *);

/// @brief Simulates the gameplay of guessing an array of numbers.
/// @param code The array representing the code.
/// @param codeSize The size of the array.
void playGame(int *code, int codeSize) {
    // Variable to store guess
    int *userGuess = new int[codeSize]();
    // Guess gameplay
    int maxGuess = codeSize * 2;
    bool result = false;
    string feedback;
    while (maxGuess > 0) {
        // Number of guesses left
        cout << '\n';
        cout << "-= You have " << maxGuess << " guesses left =-\n";
        maxGuess--;
        // Print feedback
        if (feedback.length() > 0) {
            cout << "Current feedback:\n";
            cout << feedback << '\n';
        }
        // Input guess
        /*for (int i = 0; i < codeSize; i++) {
            cout << "Enter number " << i << ": >";
            cin >> *(userGuess + i);
            if (!cin) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                i--;
                continue;
            }
        }*/
        string inp;
        cout << "Enter your guess of " << codeSize << " numbers:\n";
        while (true) {
            // Input guess from lines
            cout << ">";
            if (!getline(cin >> ws, inp)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            // Attempt to convert the guess into a number array
            try {
                int startPos = 0;
                size_t delimPos;
                for (int i = 0; i < codeSize; i++) {
                    // Find the next whitespace
                    delimPos = inp.find_first_of(" \t\r\n", startPos);
                    if (delimPos == string::npos) {
                        delimPos = (int) inp.length();
                    }
                    // Iterate again if the first character is whitespace
                    if (startPos == delimPos) {
                        startPos = delimPos + 1;
                        i--;
                        continue;
                    }
                    // Convert the substring to a number and store it in array
                    *(userGuess + i) = stoi(inp.substr(startPos, delimPos - startPos));
                    startPos = delimPos + 1;
                }
            } catch (...) {
                continue;
            }
            break;
        }
        // Compare guess
        result = compareGuess(code, userGuess, codeSize, &feedback);
        if (result) {
            break;
        }
    }
    // Print game result
    cout << '\n';
    if (result) {
        cout << "You won!\n";
    } else {
        cout << "You ran out of guesses!\n";
    }
    // Delete
    delete[] userGuess;
}

/// @brief Compare the code to the guess and prints out a feedback.
/// @param code The array representing the code.
/// @param guess The array representing the guess.
/// @param codeSize The size of the arrays.
/// @param feedback The string pointer that stores the current guess's feedback on a new line.
/// @return Whether all of the numbers in the guess matches the code.
bool compareGuess(int *code, int *guess, int codeSize, string *feedback) {
    bool *lookedCode = new bool[codeSize](); // Initialized to 0
    bool *lookedGuess = new bool[codeSize]();
    // Get correct numbers in correct positions
    int correctNums = 0;
    for (int i = 0; i < codeSize; i++) {
        // Code matches guess
        if (code[i] == guess[i]) {
            lookedCode[i] = true;
            lookedGuess[i] = true;
            correctNums++;
        }
    }
    // Get correct numbers in wrong positions, and extra numbers
    int wrongPosNums = 0;
    int extraNums = 0;
    for (int guessI = 0; guessI < codeSize; guessI++) {
        // If unlooked guess
        if (!lookedGuess[guessI]) {
            for (int codeI = 0; codeI < codeSize; codeI++) {
                // If unlooked code matches unlooked guess
                if (!lookedCode[codeI] && code[codeI] == guess[guessI]) {
                    lookedCode[codeI] = true;
                    lookedGuess[guessI] = true;
                    wrongPosNums++;
                    break;
                }
            }
        }
        // If unlooked guess doesn't match any unlooked code
        if (!lookedGuess[guessI]) {
            extraNums++;
        }
    }
    // Print feedback
    cout << "-- Guess Feedback --\n";
    // cout << "Correct positions: " << correctNums << '\n';
    // cout << "Numbers in wrong positions: " << wrongPosNums << '\n';
    // cout << "Extra numbers (including wrong numbers): " << extraNums << '\n';
    cout << "C: " << correctNums << '\n';
    cout << "W: " << wrongPosNums << '\n';
    cout << "E: " << extraNums << '\n';
    // Store feedback
    string tmpFeedback;
    if ((int) (*feedback).length() > 0) tmpFeedback = '\n';
    for (int i = 0; i < codeSize; i++) tmpFeedback += to_string(guess[i]) + " ";
    tmpFeedback += string("| ") + "C:" + to_string(correctNums);
    tmpFeedback += " W:" + to_string(wrongPosNums);
    tmpFeedback += " E:" + to_string(extraNums);
    *feedback += tmpFeedback;
    // Delete
    delete[] lookedCode;
    delete[] lookedGuess;
    // Return
    return correctNums == codeSize;
}