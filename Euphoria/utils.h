#pragma once

#ifndef UTILS_H
#define UTILS_H

void clearScreen();
void printLoadingDots(int speed, bool delete, int loops);
void printAsciiArt(const char*);
void printTyping(int speed, const char* text);
char* getUsername(char* username);

#endif
