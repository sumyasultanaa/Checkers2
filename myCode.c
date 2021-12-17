#include<stdio.h>
#include "myCode.h"
  
void printDisplay(int d[][COLS]);
void swapIJKL(int d[ROWS][COLS], int i, int j, int k, int l);
char value2symbol(int i);
void printDisplayFancy(int d[][COLS]);
int Playersturn(int d[][COLS], int player,int i,int j,int k,int l);
 
/* Rachel coded the checkerboard which implements 8 rows and 8 columns. At the bottom of the board, the letters a-h will be printed. On the side, there will be numbers 1-8 */ 
void printDisplayFancy(int d[][COLS])
{
    int rr, cc, pp;
    
    printf("  +---+---+---+---+---+---+---+---+\n");
    
    for (rr=0; rr<ROWS; ++rr)
    {
        printf("%d |", rr+1);
        for (cc=0; cc<COLS; ++cc)
        {
            printf(" %c |", value2symbol(d[rr][cc]) );
        }
        printf("\n");
        printf("  +---+---+---+---+---+---+---+---+\n");
    }
    
    printf("    a   b   c   d   e   f   g   h\n");
}

/* swaps the pieces */ 
void swapIJKL(int d[ROWS][COLS], int i, int j, int k, int l)
{
    int temp;
    
    printf("SWAP: %d,%d to %d,%d\n", i, j, k, l);
    
    temp = d[i][j];
    
    d[i][j] = d[k][l];
    
    d[k][l] = temp;
}
 
char value2symbol(int i) 
{
    switch(i)
    {
        case 0:
            return ' ';
        case 1:
            return 'E';  /* E stands for empty space, $ stands for red pieces, and @ stands for black pieces */
        case 2:
            return '$';
        case 3:
            return '@';     
    }
    return ('?');
}

/* Sumya created conditionals to mirror the rules of Checkers to account for being out of bounds, moving the wrong piece, and moving to an occupied location */
int Playersturn(int d[][COLS], int player,int i,int j,int k,int l)
{
    int jmp_r;
    int jmp_c;
    
    if(player == RED){
        printf("RED move from %d,%d to %d,%d\n", i, j, k, l);
    } else {
        printf("BLACK move from %d,%d to %d,%d\n", i, j, k, l);
    }
    
    if(i < 0 && ROWS <= i){ 
        printf("i is out of bounds\n");
        return -1;
    }
    if(j < 0 && COLS <= j){
        printf("j is out of bound");
        return -1;
    }
        
    if(k < 0 && ROWS <= k){
        printf("k is out of bounds");
        return -1;
        
    }
    if(l < 0 && COLS<= l){
        printf("l is out of bounds\n");
        return -1;
    }
    /* code is for if player moves the wrong piece */    
    if(player == RED){
        if(d[i][j] != RED){
            printf("move your own piece!\n");
            return -1;
        }
    } else { 
        if(d[i][j] != BLACK){
            printf("move your own piece!\n");
            return -1;
        }
    }
    /* code for when the player moves to an occupied location */
    if(d[k][l] != EMPTY){
        printf("You must move to a empty location");
        return -1;
    }
    
    /* code for when player moves in the wrong direction */
    if(player == RED){
        if(i >= k){
            printf("RED player must move down\n");
            return -1;
        }
    } else { 
        if(i <= k){
            printf("BLACK player must move up\n");   
            return -1;
        }
    }
    
    if(i - k == -1 || i - k == 1){
        if(j - l == 1 || j - l == -1){
            swapIJKL(d,i,j,k,l);
            return 0;
        }
    }  
    if(i - k == -2 || i - k == 2){
        if(j - l == -2 || j - l == 2){
            if(i < k){ 
                jmp_r = i + 1;
            } else { 
                jmp_r = i - 1;
            }
            if(j < l){ 
                jmp_c = j + 1;
            } else { 
                jmp_c = j - 1;
            }
            
            if(player==RED && d[jmp_r][jmp_c]!=BLACK)
            {
                printf("Enemy is not Black at %d%d",jmp_r, jmp_c);
                return -1;
            }
            if(player==BLACK && d[jmp_r][jmp_c] != RED){
                printf("you can only jump over an enemy player\n");
                return -1;
            }
 
            d[jmp_r][jmp_c] = 1;
            swapIJKL(d,i,j,k,l);
            return 0;
        }
    }
    
    printf("You can only move diagnally\n");
    return -1;
    
}
 
/* Both members worked on creating the conditionals for this part by having the game print when an action is illegal. Player will be notified of when it is their turn by the scan function which determines if the conditions match where the program will print either Red's turn or Black's turn */

int main()
{
        int r,c;
        int pr, pb;
        int i, k;
        char j, l;
        int d[ROWS][COLS]={
    {0,2,0,2,0,2,0,2},
    {2,0,2,0,2,0,2,0}, 
    {0,2,0,2,0,2,0,2}, 
    {1,0,1,0,1,0,1,0},    
    {0,1,0,1,0,1,0,1}, 
    {3,0,3,0,3,0,3,0},
    {0,3,0,3,0,3,0,3},
        {3,0,3,0,3,0,3,0}};
 
/* the 0's are spaces that can't be occupied. the red pieces will occupy where the 2's are, the 1's are where the empty spaces are, and the 3's are where the black pieces are */

    for(;;){
        printDisplayFancy(d);
        while(1){
            printf("Red's turn: ");
            scanf("%d%c",&i,&j);
            printf("to: ");
                scanf("%d%c",&k,&l);
                if(Playersturn(d, RED, i-1,j - 'a',k-1,l - 'a') == 0)
                    break;
                printf("Illegal move, try again\n");
        }
 
        printDisplayFancy(d);
        while(1){
            printf("Black's turn: ");
            scanf("%d%c",&i,&j);
            printf("to :");
                scanf("%d%c",&k,&l);
                if(Playersturn(d, BLACK, i-1,j - 'a',k-1,l - 'a') == 0)
                    break;
                printf("Illegal move, try again\n");
        }
    }
 
        getchar();
        getchar();
    return 0;
}
