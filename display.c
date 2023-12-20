#include "header.h"

void board(int col, int row, char gameBoard[col][row]) {
    for (int j = numTowers-1; j >=0; j--) {
        for (int i = 0; i < numRings; i++) {
            printf("%c  ",gameBoard[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < numRings; ++i) {
        printf("%c  ",i+65);
    } printf("\n");
}

void printUltimateBoard(int playerNameLength, char playerName[playerNameLength], int col, int row, int move, char gameBoard[col][row], char ring[10][50]) {
    clearScreen();
    char cliGameBoard[numTowers][numRings];

    for (int i = 0, j = numTowers-1; j >= 0 && i < numTowers; i++, j--) {
        for (int k = 0; k < numRings; k++) {
            cliGameBoard[i][k]=gameBoard[k][j];
        }
    }

    int x = (numRings*20+1)+(numTowers-3)*numRings*4;
    int y = (numRings*10-8)+(numTowers-3)*numRings*2;
    int z = (numTowers-3)*2;

    printf("++");for (int i = 0; i < x; ++i)printf("=");printf("++\n");
    printf("||  ");    printf("%s", playerName);for (int i = 0; i < y-playerNameLength-2; ++i)printf(" ");printf(" Towers of Hanoi ");for (int i = 0; i < y-11; ++i)printf(" ");printf("Moves: %2d",move);printf("  ||\n");
    printf("++");for (int i = 0; i < x; ++i)printf("=");printf("++\n");
    printf("|| ");for (int i = 0; i < numRings; ++i){for (int j = 0; j < (numTowers-3)*2; j++){printf(" ");}printf("         %c         ",i+65);for (int k = 0; k < (numTowers-3)*2; k++){printf(" ");}if(i==numRings-1){printf(" ||\n");}else printf("|");}
    printf("||");for (int i = 0; i < x; ++i)printf("-");printf("||\n");
    printf("|| ");for (int i = 0; i < numRings; ++i){for (int j = 0; j < (numTowers-3)*2; j++){printf(" ");}printf("        _^_        ");for (int k = 0; k < (numTowers-3)*2; k++){printf(" ");}if(i==numRings-1){printf(" ||\n");}else printf("|");}
    
    for (int k = 0; k < numTowers; k++){
        printf("|| ");
        for (int i = 0; i < numRings; ++i){
            
            if((cliGameBoard[k][i]-48) > 4 && cliGameBoard[k][i] != '.'){
                z=z-(2*(cliGameBoard[k][i]-48))+9;
            }

            for (int j = 0; j < z ; j++){
                printf("-");
            }

            int digitIndex = cliGameBoard[k][i] - '0';
            if (digitIndex >= 1 && digitIndex <= 9) {
                printf("%s", ring[digitIndex]);
            } else {
                printf("       | . |       ");
            }

            for (int j = 0; j < z; j++){
                printf("-");
            }

            z = (numTowers-3)*2;

            if(i==numRings-1){
                printf(" ||\n");
            }else printf("|");
        }
    }
    
    printf("|| ");for (int i = 0; i < numRings; ++i){printf("  +=======");for (int j = 0; j < (numTowers-3)*4; j++){printf("=");}printf("======+  ");if(i==numRings-1){printf(" ||\n");}else printf("|");}
    printf("++");for (int i = 0; i < x; ++i)printf("=");printf("++\n");
}

void clearScreen() {
    // FILE *fp = popen("paplay /usr/share/sounds/freedesktop/stereo/bell.oga", "r");
    // pclose(fp);
    // system("clear");
    printf("\033[H\033[J");
}
