#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
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
 * @param delete Whether or not it will delete the dots at the end.
 * @param loops The number of times it will loop.
 *
 */
void printLoadingDots(bool delete, int loops) {
    int delete_cycles = 0;

    if (delete == true) {
        int delete_cycles = 3;
    }
    else {
        int delete_cycles = 2;
    }

    for (int i = 0; i < loops; i++) {

        Sleep(1000);

        for (int j = 0; j < 3; j++) {
            printf(". ");
            Sleep(1000);
        }

        for (int j = 0; j < delete_cycles; j++) {
            printf("\b\b \b");
            Sleep(500);
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
 * Default is speed 1 (100ms).
 */
void printTyping(int speed, const char* text) {
    int delays[] = { 50, 100, 150, 200 }; // delay values in ms

    for (int i = 0; text[i] != '\0'; i++) {
        printf("%c", text[i]);
        fflush(stdout); // Flush the output buffer to ensure immediate printing
        Sleep(delays[speed]);
    }
}
