#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

extern int numRings;
extern int numTowers;
extern int winFlag;

// Function declarations

//input.c
void getName(char *name, int *length);
int inputBoardSize(const char *prompt, int minValue, int maxValue);
void generateRing(char digit, char output[50]);
char scanValue(const char *prompt, char minValue, int maxValue);
void clearInputBuffer();

//gamePlay.c
int isValidMoveSource(int w, int col, int row, char gameBoard[col][row]);
int isValidMoveDestination(int w, int x, int col, int row, char gameBoard[col][row]);
int moveRing(int sourceTower, int destinationTower, int col, int row, char gameBoard[col][row]);
int winCheck(int col, int row, char gameBoard[col][row]);

//display.c
void board(int col, int row, char gameBoard[col][row]);
void printUltimateBoard(int playerNameLength, char playerName[playerNameLength], int col, int row, int move, char gameBoard[col][row], char ring[10][50]);
void clearScreen();

#endif /* HEADER_H */
