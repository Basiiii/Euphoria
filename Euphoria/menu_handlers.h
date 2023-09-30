#pragma once

#ifndef MENU_HANDLERS_H
#define MENU_HANDLERS_H

#include "player.h"

void ContinueAdventure();
void RestartAdventure();
void ChangeSettings();
void StartNewAdventure();
void ExitGame();
void handleNewPlayer();
void handleReturningPlayer(PlayerData* user);

#endif
