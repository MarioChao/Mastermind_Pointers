#include "../inc/gameplay.h"

bool compareGuess(int *, int *, int, string *);

/**
 * @brief Simulates the gameplay of guessing an array of numbers.
 * 
 * @param code The array representing the code.
 * @param codeSize The size of the array.
 */
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
        string inp;
        cout << "Enter your guess of " << codeSize << " numbers:\n";
        while (true) {
            // Input guess from lines
            cout << ">";
            if (!getline(cin >> ws, inp)) { // Skips leading whitespaces
                /* getline fails */
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            // Attempt to convert the guess into a number array
            try {
                int startPos = 0;
                size_t delimPos;
                for (int i = 0; i < codeSize; i++) {
                    // Find the first non-whitespace
                    startPos = inp.find_first_not_of(" \t\r\n", startPos);
                    // Find the next whitespace
                    delimPos = inp.find_first_of(" \t\r\n", startPos);
                    if (delimPos == string::npos) {
                        delimPos = (int) inp.length();
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

/**
 * @brief Compare the code to the guess and prints out a feedback.
 * 
 * @param code The array representing the code.
 * @param guess The array representing the guess.
 * @param codeSize The size of the arrays.
 * @param feedback The string pointer that stores the current guess's feedback on a new line.
 * @return true All numbers in the guess matches the code.
 * @return false The guess doesn't fully match the code.
 */
bool compareGuess(int *code, int *guess, int codeSize, string *feedback) {
    bool *lookedCode = new bool[codeSize](); // Initialized to 0
    bool *lookedGuess = new bool[codeSize]();
    // Get correct positions
    int correctNums = 0;
    for (int i = 0; i < codeSize; i++) {
        /* Iterate over the code */
        if (code[i] == guess[i]) {
            /* Code matches guess */
            lookedCode[i] = true;
            lookedGuess[i] = true;
            correctNums++;
        }
    }
    // Get wrong positions and extra numbers
    int wrongPosNums = 0;
    int extraNums = 0;
    for (int guessI = 0; guessI < codeSize; guessI++) {
        /* Look through the guess */
        if (!lookedGuess[guessI]) {
            /* If unlooked guess */
            for (int codeI = 0; codeI < codeSize; codeI++) {
                /* Look through the code */
                if (!lookedCode[codeI] && code[codeI] == guess[guessI]) {
                    /* If unlooked code matches unlooked guess */
                    lookedCode[codeI] = true;
                    lookedGuess[guessI] = true;
                    wrongPosNums++;
                    break;
                }
            }
        }
        if (!lookedGuess[guessI]) {
            /* If unlooked guess doesn't match any unlooked code */
            extraNums++;
        }
    }
    // Print feedback
    cout << "-- Guess Feedback --\n";
    cout << "C: " << correctNums << '\n'; // Correct positions
    cout << "W: " << wrongPosNums << '\n'; // Wrong positions
    cout << "E: " << extraNums << '\n'; // Extra or wrong numbers
    // Store feedback
    string tmpFeedback;
    if ((int) (*feedback).length() > 0) tmpFeedback = '\n';
    for (int i = 0; i < codeSize; i++) tmpFeedback += to_string(guess[i]) + " "; // The guess
    tmpFeedback += string("| ") + "C:" + to_string(correctNums); // Correct positions
    tmpFeedback += " W:" + to_string(wrongPosNums); // Wrong positions
    tmpFeedback += " E:" + to_string(extraNums); // Extra or wrong numbers
    *feedback += tmpFeedback;
    // Delete
    delete[] lookedCode;
    delete[] lookedGuess;
    // Return
    return correctNums == codeSize;
}