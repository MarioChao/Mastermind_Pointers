Synopsis
=======

This program lets you play the code-breaking game known as *[Mastermind](https://en.wikipedia.org/wiki/Mastermind_(board_game))*.

Run it on replit here:<br>
[![Run on Repl.it](https://replit.com/badge/github/MarioChao/Mastermind_Pointers)](https://replit.com/new/github/MarioChao/Mastermind_Pointers)

How to play
=======

To setup for the game:
-------

* First, you will need to enter a "difficulty level", alternately known as "game level":

    Level 1: you will guess 4 numbers in 8 tries (rounds)<br>
    Level 2: you will guess 6 numbers in 12 tries<br>
    Level 3: you will guess 8 numbers in 16 tries

* After choosing a difficulty, the game will generate a list that contains the respective amount of numbers. Each number generated will be from 0 to 9, or single digits.

To play the game:
-------

* In each round, the game will ask the user to enter their guess. Type your numbers on a single line, separated by whitespace.
* After making a guess, press enter, and the game will automatically provide a feedback and move on to the next round.
    If the player has correctly guessed all of the numbers in the correct positions, the game will end immediately.
* The feedback contains three numbers:

| Type          | Meaning                       |
| :-----------: | ----------------------------- |
| C             | numbers in correct positions  |
| W             | numbers in wrong positions    |
| E             | extra or wrong numbers        |

<details>
    <summary><strong>-= Explanation =-</strong></summary>

> "C" (numbers in correct positions):
>
>> This denotes how many numbers in your guess are in the correct position in the list.
>
> "W" (numbers in wrong positions):
>
>> This denotes how many numbers in your guess exist in the list, but are not in the correct position.
>>
>> **Notice:** For duplicates, the extra amount of numbers will be instead counted in "E" as extra. For example, if the list is "1 3 3 7" and you guessed "1 1 1 1", "C" will be 1, "W" will be 0, and "E" will be 3 (the three 1s at 2nd, 3rd, and 4th position are extra).
>
> "E" (extra or wrong numbers):
>
>> This denoates the number of extra or wrong numbers in your guess. This represents the remaining numbers in the guess after excluding the "C" and "W"s.
>
> <br>

</details>

More about the program
=======

A major component of this program is the use of pointers.<br>
Memories are dynamically allocated to create pointers to arrays.<br>
Values are stored in addresses by dereferencing pointers.