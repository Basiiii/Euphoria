#include <stdio.h>
#include <stdbool.h>
#include <io.h> // Include the necessary header for _access()
#include <windows.h>
#include "player.h" // Include the player data structure definition

/**
 * Checks if a file exists.
 *
 * @param filename The file name.
 *
 */
bool doesFileExist(const char* filename) {
    return _access(filename, 0) != -1;
}

/*
 * Create a new save file with the given username and initial chapter.
 *
 * @param username The username to be saved in the new file.
 * @return True if the save file was created successfully, false otherwise.
 */
bool createNewSaveFile(const char* username) {
    FILE* file;
    errno_t err = fopen_s(&file, "save.txt", "w");
    if (err == 0 && file != NULL) {
        fprintf(file, "Username: %s\nCurrentChapter: 0\n", username);
        fclose(file);
        return true;
    }
    else {
        // Handle the error: Unable to create the save file.
        // TODO: Add error handling code here.
        return false;
    }
}

/*
 * Create a new save file with the given username and initial chapter.
 *
 * @param username The username to be saved in the new file.
 * @return True if the save file was created successfully, false otherwise.
 */
bool createNewSettingsFile(int typingSpeed) {
    FILE* file;
    errno_t err = fopen_s(&file, "settings.txt", "w");
    if (err == 0 && file != NULL) {
        fprintf(file, "TypingSpeed: %d\n", typingSpeed);
        fclose(file);
        return true;
    }
    else {
        // Handle the error: Unable to create the save file.
        // TODO: Add error handling code here.
        return false;
    }
}

/*
* Get the players saved data such as username and chapter progress.
*/
PlayerData getSaveData() {
    PlayerData player = { "NEW_PLAYER", 0 }; // Declare a PlayerData structure to store the loaded data

    if (doesFileExist("save.txt")) {
        if (loadPlayerData(&player) != 0) {
            printf("Error fetching data... Your data might be corrupt.\n\n");
        }
    }

    return player; // Return the PlayerData structure
}


/**
 * Save player data to a file.
 *
 * @param player The player data to be saved.
 */
void savePlayerData(const PlayerData* player) {
    FILE* file;
    errno_t err = fopen_s(&file, "save.txt", "w");
    if (err == 0 && file != NULL) {
        fprintf(file, "Username: %s\nCurrentChapter: %d\n", player->username, player->currentChapter);
        fclose(file);
    }
    else {
        // Handle the error: Unable to open the file for writing.
        // You can add error handling code here.
    }
}

/**
 * Load player data from a file.
 *
 * @param player The player data structure to populate.
 * @return 0 if successful, a non-zero value on error.
 */
int loadPlayerData(PlayerData* player) {
    FILE* file;
    errno_t err = fopen_s(&file, "save.txt", "r");
    if (err != 0 || file == NULL) {
        // Handle the error: Unable to open the file (e.g., file does not exist).
        // Maybe prompt the player to create a new save file or take appropriate action.
        return 2;  // Error
    }

    if (fscanf_s(file, "Username: %49s\nCurrentChapter: %d\n", player->username, 50, &player->currentChapter) == 2) {
        fclose(file);
        return 0;  // Success
    }
    else {
        fclose(file);
        // Handle error: Data in the file is corrupted or in an unexpected format.
        // Maybe prompt the player to create a new save file or take appropriate action.
        return 1;  // Error
    }
}
