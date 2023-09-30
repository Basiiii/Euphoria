#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
    printf("Starting new adventure...\n");
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
    printLoadingDots(false, 1);
}


/**
 * Handles the menu options for a new player.
 */
void handleNewPlayer() {
    void (*menuOptions[])() = { StartNewAdventure, ExitGame };

    displayNewPlayerMenu();

    int choice;
    scanf_s("%d", &choice);

    if (choice >= 1 && choice <= 2) {
        (*menuOptions[choice - 1])();
    }
    else {
        printf("Invalid choice.\n");
    }
}

/**
 * Handles the menu options for a returning player.
 */
void handleReturningPlayer(PlayerData* player) {
    void (*menuOptions[])() = { ContinueAdventure, RestartAdventure, ChangeSettings, ExitGame };

    displayReturningPlayerMenu(player->username);

    int choice;
    scanf_s("%d", &choice);

    if (choice >= 1 && choice <= 4) {
        (*menuOptions[choice - 1])();
    }
    else {
        printf("Invalid choice.\n");
    }
}
