#include "../inc/setup.h"

void chooseLevel(int *);
int *generateCode(int);
int generateRandom(int, int);

/**
 * @brief Ask the user for difficulty level, then generate an array of random numbers of corresponding size.
 * 
 * @param code The pointer that will save the array generated.
 * @param codeSize The pointer that will save the size of the array generated.
 */
void setup(int **code, int *codeSize) {
    // Choose difficulty level
    int level = 1;
    chooseLevel(&level);
    cout << "Chosen Game Level: " << level << '\n';

    // Choose size of array based on level
    switch (level) {
        case 1:
            *codeSize = 4;
            break;
        case 2:
            *codeSize = 6;
            break;
        case 3:
            *codeSize = 8;
            break;
    }
    // Generate secret code (store in pointer)
    *code = generateCode(*codeSize);
}

/**
 * @brief Ask the user to input a difficulty level.
 * 
 * @param level The pointer that will save the inputted difficulty level.
 */
void chooseLevel(int *level) {
    assert(level != nullptr);
    cout << "Enter your Game Level (1-3)\n";
    while (true) {
        cout << "> ";
        cin >> *level;
        if (!cin) {
            /* cin fails */
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    }
    *level = max(1, min(3, *level));
}

/**
 * @brief Generate an array of random single-digit numbers.
 * 
 * @param size The number of elements in the generated array.
 * @return int* A pointer representing the array of random single-digit numbers.
 */
int *generateCode(int size) {
    // Allocate a new array to pointer
    int *arr = new int[size];
    // Populate it with random numbers
    int *ptr = arr;
    srand(time(0));
    while (ptr != arr + size) {
        *ptr = generateRandom(0, 9);
        ptr++;
    }
    return arr;
}

/**
 * @brief Generate a random number between min and max, inclusive.
 * 
 * @param min The minimum number to be returned.
 * @param max The maximum number to be returned.
 * @return int A random number in the range [min, max].
 */
int generateRandom(int min, int max) {
    return rand() % (max - min + 1) + min;
}