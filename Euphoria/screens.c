#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include "utils.h"
#include "screens.h"
#include "data.h"
#include "constants.h"
#include "menu_handlers.h"

/**
 * Displays the loading screen.
 * Makes the game feel more immersive.
 */
void displayLoadingScreen() {
    clearScreen();
    
    printAsciiArt(GAME_LOGO);

    printLoadingDots(false, 1);

    Sleep(500);
}

/**
 * Displays the menu for returning players.
 *
 * @param username The username of the returning player.
 */
void displayReturningPlayerMenu(const char* username) {
    printf("Welcome back %s, what would you like to do?\n\n", username);
    printf("1. Continue your adventure\n");
    printf("2. Restart your adventure!\n");
    printf("3. Change your settings\n");
    printf("4. Exit\n");
    printf("\nEnter your choice: ");
}

/**
 * Displays the menu for new players.
 */
void displayNewPlayerMenu() {
    printf("Welcome adventurer, what would you like to do?\n\n");
    printf("1. Start a new adventure!\n");
    printf("2. Exit\n");
    printf("\nEnter your choice: ");
}

/**
 * Displays the main menu screen.
 *
 * Displays the menu options based on if they are a new or returning player.
 *
 */
void displayMenuScreen() {
    clearScreen();

    printAsciiArt(GAME_LOGO);
    printf("\n=== Euphoria ===\n");

    PlayerData user = getSaveData();

    if (strcmp(user.username, "NEW_PLAYER") == 0) {
        handleNewPlayer();
    }
    else {
        handleReturningPlayer(&user);
    }
}
