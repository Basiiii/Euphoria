#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>
#include "utils.h"

/**
 * Clears the screen.
 */
void clearScreen() {
    //printf("\033[H\033[J");
    system("cls");
}

/**
 * Prints loading dots (". . .") with a typing effect.
 *
 * @param speed The typing speed (0 or 1).
 * @param delete Whether or not it will delete the dots at the end.
 * @param loops The number of times it will loop.
 * 
 * Default is speed 1 (1000ms).
 */
void printLoadingDots(int speed, bool delete, int loops) {
    int delete_cycles = 0;
    int delays[] = { 500, 1000}; // delay values in ms

    if (delete == true) {
        int delete_cycles = 3;
    }
    else {
        int delete_cycles = 2;
    }

    for (int i = 0; i < loops; i++) {

        Sleep(delays[speed]);

        for (int j = 0; j < 3; j++) {
            printf(". ");
            Sleep(delays[speed]);
        }

        for (int j = 0; j < delete_cycles; j++) {
            printf("\b\b \b");
            Sleep(delays[speed] / 2);
        }
    }
}

/**
 * Print ASCII art.
 *
 * @param art The ASCII art as a single string.
 */
void printAsciiArt(const char* art) {
    printf("%s\n", art);
}

/**
 * Prints a typing effect at the specified speed.
 *
 * @param speed The typing speed (0 to 3).
 * @param text  The text to be typed.
 * 
 * Default is speed 1 (50ms).
 */
void printTyping(int speed, const char* text) {
    int delays[] = { 20, 35, 50, 100 }; // delay values in ms

    for (int i = 0; text[i] != '\0'; i++) {
        printf("%c", text[i]);
        fflush(stdout); // Flush the output buffer to ensure immediate printing

        if (_kbhit()) {
            // If a key has been pressed, print the rest of the text and break the loop
            printf("%s", text + i + 1);
            (void)_getch(); // Read and discard the pressed key, ignoring its value
            break;
        }

        Sleep(delays[speed]);
    }
}

/**
 * Gets the Username from user and checks to make sure it's under 50 chars and 
 * follows the rules.
 */
char* getUsername(char* username) {
    do {
        printf("What is your name, traveler?\n");
        fgets(username, 51, stdin);

        if (strchr(username, '\n') == NULL) {
            // Input was too long, discard remaining characters in input buffer
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            printf("Username is too long. Please enter a username with less than 50 characters.\n");
        }
        else {
            // Replace newline character with null-terminating character
            username[strcspn(username, "\n")] = '\0';
            break;
        }
    } while (1);
}
