#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include "screens.h"
#include "menu_handlers.h"
#include "player.h"
#include "utils.h"

void ContinueAdventure() {
    printf("Continuing adventure...\n");
}

void RestartAdventure() {
    printf("Restarting adventure...\n");
}

void ChangeSettings() {
    printf("Changing settings...\n");
}

void StartNewAdventure() {
    char username[51];

    displayWelcomeScreen();
    getUsername(username);
    

    // Create save file

    // Create settings file (with default)

    // Prompt user to change settings file
    // if yes, show the "update settings" screen
    // if not, proceed to chapter 1

    /*
    * TODO: Start with implementing the logic for new players. We need to go through a "setup" first.
    * 
    * During this setup we need to get the player's username, it CANNOT be the same as "NEW_PLAYER".
    * 
    * After we must go through settings, where the user can select typing speed etc. Store these settings
    * inside of settings.txt.
    * 
    * Once these settings have been defined, we can continue to another function where we continue the 
    * story from where the player left off. If new player, we "continue" from the start.
    * 
    * This is done so that we can have menu functions separate from gameplay, we load into menu, select 
    * our option and then we leave the menus and start our gameplay.
    */
}

void ExitGame() {
    clearScreen();

    printf("Thank you for playing Euphoria");
    printLoadingDots(0, false, 1);
}


/**
 * Handles the menu options for a new player.
 */
void handleNewPlayer() {
    void (*menuOptions[])() = { StartNewAdventure, ExitGame };

    displayNewPlayerMenu();

    int choice;

    while (1) {
        char input = _getch();  // Using _getch() to read a single key without Enter

        if (input == '1') {
            StartNewAdventure();
            break;
        }
        else if (input == '2') {
            ExitGame();
            break;
        }
        else {
            printf("Invalid choice. Press 1 or 2.\n");
        }
    }
}

/**
 * Handles the menu options for a returning player.
 */
void handleReturningPlayer(PlayerData* player) {
    void (*menuOptions[])() = { ContinueAdventure, RestartAdventure, ChangeSettings, ExitGame };

    displayReturningPlayerMenu(player->username);

    int choice;

    while (1) {
        char input = _getch();  // Using _getch() to read a single key without Enter

        if (input >= '1' && input <= '4') {
            choice = input - '0';
            (*menuOptions[choice - 1])();
            break;
        }
        else {
            printf("Invalid choice. Press 1, 2, 3, or 4.\n");
        }
    }
}
