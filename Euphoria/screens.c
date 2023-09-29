#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include "utils.h"
#include "screens.h"
#include "data.h"
#include "constants.h"

/**
 * Displays the entry screen (loading screen).
 * Makes the game feel more immersive.
 */
void displayEntryScreen() {
    clearScreen();

    printAsciiArt(GAME_LOGO);

    printLoadingDots(false, 1);

    Sleep(500);
}

/**
 * Displays the menu screen.
 * 
 * Checks if save.txt exists to determine if the user has saved games.
 * 
 * If there are no saved games, it treats the user as a new player.
 * If there are saved games, it allows the user to continue their game.
 *
 */
void displayMenuScreen() {
    clearScreen();

    printAsciiArt(GAME_LOGO);

    printf("\n=== Euphoria ===\n");

    if (doesFileExist("save.txt")) {

        /*TODO: Change the logic here, since file exists, then add a function
        to check if we can get the users data (username & progress).
        
        If we can't, we should print a message saying there is a problem with save 
        data and send them back to main menu or give other option (think about it).
        
        If we can, we should print the users name in the welcome back message
        and also when they continue game we should say "are you sure you want to
        continue at chapter x".

        Also think about how we will structure and save the user data.
        */
        char* user_name = "";

        printf("Welcome back %s, what would you like to do?\n\n", user_name);
        printf("1. Continue your adventure\n");
        printf("2. Restart your adventure!\n");
        printf("3. Change your settings");
        printf("4. Exit\n");
    }
    else {
        printf("Welcome adventurer, what would you like to do?\n\n");
        printf("1. Start a new adventure!\n");
        printf("2. Exit\n");
    }

    printf("\nEnter your choice: ");
}
