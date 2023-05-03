#include  <stdio.h>
#include <stdlib.h>
#include <time.h>

//game constants 
#define ROWS 9
#define COLS 9
#define MINES 10

int main()
{
    //declare variables 
    int field[ROWS][COLS];
    int i, j;
    int x, y;
    int remain_mines = MINES;
    int remain_cells = ROWS * COLS; 
    
    //initialize the field with all zeros 
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            field[i][j] = 0;
        }
    }
    
    //place the mines randomly 
    srand(time(NULL));
    while(remain_mines > 0) {
        x = rand() % ROWS;
        y = rand() % COLS;
        if(field[x][y] != -1) {
            field[x][y] = -1;
            remain_mines--;
        }
    }
    
    //fill the rest of the cells with numbers 
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(field[i][j] == -1) {
                // count the adjacent mines 
                int count = 0;
                int k, l;
                for(k = i - 1; k <= i + 1; k++) {
                    for(l = j - 1; l <= j + 1; l++) {
                        if(k >= 0 && k < ROWS && l >= 0 && l < COLS) {
                            if(field[k][l] == -1) {
                                count++;
                            }
                        }
                    }
                }
                field[i][j] = count;
            }
        }
    }
    
    //game loop
    while(remain_cells > MINES) {
       //TODO: implement the game loop here 
    }
    
    return 0;
}