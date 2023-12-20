#include "header.h"

int numRings = 3, numTowers = 3, winFlag = 0;

int main() {
    clearScreen();

    printf(" Made with <3 by KRUPAL VIRANI \n");
    printf("                           ~pSwaqtch\n\n");
    char playerName[200];
    int playerNameLength = 0;
    getName(playerName, &playerNameLength);

    printf("\n Hello %s!\n Let's start The Towers of Hanoi!...\n\n Press 'enter' to start>>> ", playerName);
    clearInputBuffer();

    int firstMove = 0;
    int move=0;
    char gameBoard[numRings][numTowers];
    char ring[10][50];

    while(!firstMove){

    //Board Initialization
        for (int i = 0; i < numRings; i++) {
            for (int j = 0; j < numTowers; j++) {
                gameBoard[i][j] = '.';
            }
        }
        for (int i = numTowers-1, j = 0; i >= 0 && j < numTowers; i--, j++) {
            gameBoard[0][i] = j + '1';
        }
        //rings
        char ringi[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};

        strcpy(ring[0], "       | . |       ");

        for (int i = 0; i < 10; ++i) {
            char output[50];
            generateRing(ringi[i], output);
            strcpy(ring[i + 1], output);
        }

        //board(numRings, numTowers, gameBoard);
        printUltimateBoard(playerNameLength, playerName, numRings, numTowers, move, gameBoard, ring);


        printf("\n\nAIM: \n");
        printf("To Form get all the rings in Last Tower !!\n");

        printf("FORMAT :\n");
        printf("A B C ... --  Towers\n");
        printf("1 2 3 ... --  Rings\n");
        printf("\nFirst choose the initial and then the final tower...");

        printf("\nCONDITION: \n");
        printf("1. Only Small Ring goes over a Bigger Ring.\n");
        printf("2. You may take as many maves as you wish.\n");
        
        printf("\n\n");

        numRings = inputBoardSize("Choose the no. of rings(3 - 9) : ", 3, 9);
        numTowers = inputBoardSize("Choose the no. of towers(3 - 9) : ", 3, 9);

        printUltimateBoard(playerNameLength, playerName, numRings, numTowers, move, gameBoard, ring);
        firstMove++;
    }

    //The Game-Play
    while(!winFlag) {
        char selectedSource = 'a';
        char z;
        int check=0;
        while(!check){
            clearInputBuffer();
            selectedSource=scanValue("Choose the initial tower: ", 'a', numRings);
            check=isValidMoveSource(selectedSource,numRings,numTowers,gameBoard);
        }

        check=0;
        while(!check){
            clearInputBuffer();
            z=scanValue("Choose the final tower: ", 'a', numRings);
            check = isValidMoveDestination(z,selectedSource,numRings,numTowers,gameBoard);
        }

        move+=moveRing(selectedSource,z,numRings,numTowers,gameBoard);
        // board(numRings,numTowers,gameBoard);
        printUltimateBoard(playerNameLength, playerName, numRings, numTowers, move, gameBoard, ring);

        winFlag=winCheck(numRings,numTowers,gameBoard);
    }
    winFlag=0;
    
    printf("\nYay %s !!! You Won !!!\n",playerName);
    
    printf("\nEnter q to exit, 'return' to play again...");
    clearInputBuffer();
    char gameFlag = getchar();
    if ( gameFlag == '\n' ){
        main();
    } else if ( gameFlag == 'q' ) {
        clearScreen();
        clearInputBuffer();
    }
    return 0;
}