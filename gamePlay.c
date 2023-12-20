#include "header.h"

int isValidMoveSource(int w, int col, int row, char gameBoard[col][row]){
    w-='a';
    char checkPeak[numRings];
    int i=0,j=0;
    for (i = numRings-1; i >=0 ; i--) {
        for (j = numTowers-1 ; j >= 0; j--) {
            if (gameBoard[i][j]!='.'){
                checkPeak[i] = gameBoard[i][j];
                break;
            }
            else{
                checkPeak[i]='.';
            }
        }
    }

    char max=checkPeak[w]; //printf("%c\n",max);

    //for (i = 0; i < numRings; ++i) {printf("%c ",checkPeak[i]);} printf("\n");

    for (i = 0; i < numRings; ++i) {
        if (max<checkPeak[i]) {
            max=checkPeak[i];
            break;
        }
        if (checkPeak[i]=='.'){
            j=11;
            break;
        }
    } // printf("%c\n",max); printf("%d\n",j);

    if (gameBoard[w][0]=='.'){
        printf("your chosen tower is empty, choose again !\n");
        return 0;
    } else if (1) { 
        for (int i = 0; i < numRings; ++i) {
            if (checkPeak[w] < max || j == 11) {
                //printf("valid moves possible\n");
                j=0;
                return 1;
            } else {
                printf("your chosen tower has no valid moves possible\n");
                return 0;
            }
        }
    }
    return 0;
}

int isValidMoveDestination(int w, int x, int col, int row, char gameBoard[col][row]){
    w-=97; x-=97;
    int z=100,y=0;
    //printf("checking initiated %d\n",w);

    for (int i = numTowers-1 ; i >= 0; i--) {
        if (gameBoard[w][i]!='.'){
            z = gameBoard[w][i];
            break;
        }
    }
    for (int i = numTowers-1; i>= 0; i--) {
        if (gameBoard[x][i] !='.') {
            y = gameBoard[x][i];
            break;
        }
        else{ 
            y=0;
        }
    }
    //if(z > y || y==0){ return 1; //possible } else{ return 0; //not possible }
    return z > y || y == 0;
}

int moveRing(int sourceTower, int destinationTower, int col, int row, char gameBoard[col][row]) {
    sourceTower-=97; destinationTower-=97;
    char ring='0';

    for (int i = numTowers-1; i>= 0; i--) {
        if (gameBoard[sourceTower][i] !='.') {
            ring = gameBoard[sourceTower][i];
            gameBoard[sourceTower][i]='.';
            break;
        }
    }

    for (int i = 0; i < numTowers; i++) {
        if(gameBoard[destinationTower][i]=='.') {
            gameBoard[destinationTower][i]=ring;
            break;
        }
    }

    return 1;
}

int winCheck(int col, int row, char gameBoard[col][row]) {
    for (int i = numTowers-1, j = 0; i >= 0 && j < numTowers; i--, j++) {
        if(gameBoard[numRings-1][i] == j + '1'){
            return 1;
        } else{
            return 0;
        }
    }
    return 0;
}
