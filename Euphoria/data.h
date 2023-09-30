#pragma once

#ifndef DATA_H
#define DATA_H

#include <stdbool.h>
#include "player.h" // Include the user data structure definition

bool doesFileExist(const char* filename);
bool createNewSaveFile(const char* username);
PlayerData getSaveData();
void savePlayerData(const PlayerData* player);
int loadPlayerData(PlayerData* player);

#endif
