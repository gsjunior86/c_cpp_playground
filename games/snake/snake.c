#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "../../utils/utils.h"


#define rows 15
#define cols 30
#define board_size rows*cols

typedef struct{
    int x,y;
}direction;

typedef struct{
    int x,y;
} body;

typedef struct {
    int length;
    int x,y;
} snake;


int gameOver = 0;
char board[board_size];

void change_dir(int x, int y);
void kbread();
int move_snake(direction d);
int place_target();




direction dir = {.x=1,.y=0};
snake head ={.x=5,.y=5,.length=0};
body bd[256];
int target = -1;



void fill_board(){
    int x,y;

    for(x=0; x< rows; x++){
        for(y=0; y<cols; y++){
            if(x==0 || y==0 || x == rows -1 || y==cols-1)
                board[x*cols + y] = '#';
            else
                board[x*cols + y] = '.';
        }
    }
    if(target == -1){
        target = place_target();
    }

    if(head.length > 0){
        for(int i=0; i<head.length; i++)
            board[bd[i].x*cols + bd[i].y] = 'O';
       
       
    }
    board[target] = '+';

}

void print_board(){
    int x,y;

    for(x=0; x< rows; x++){
        for(y=0; y<cols; y++){
            putchar(board[x*cols + y]);
        }
        putchar('\n');
    }

}


void change_dir(int x, int y){
    dir.x=x;
    dir.y=y;
}


void print_snake(){
    board[head.x*cols + head.y]='@';
}

int place_target(){
    int pos = 0;
    while (board[pos] == '#')
        pos =  rand() % ((board_size-1) - 0 + 1) + 0;
    
    return pos;
}


int main(int argc, char *argv){

    while(!gameOver){
        fill_board();
        print_snake();
        print_board();
        printf("\n Points: %d \n", head.length);
        if(kbhit())
            kbread();
        if(move_snake(dir)){
            printf("You Lose! \n");
            gameOver = 1;
        }else{
            usleep(175000);
            system("clear");
        }
        
    }
    return 0;
}

int move_snake(direction d){
    
    for(int i = head.length; i >=1; --i){
        bd[i].x = bd[i-1].x;
        bd[i].y = bd[i-1].y;
    }
    bd[0].x = head.x;
    bd[0].y = head.y;

    head.x+= d.x;
    head.y+= d.y;
    char pos = board[head.x*cols + head.y];
    if(pos == '#')
        return 1;
    if(pos == '+'){
        head.length +=1;
        target = place_target();
    }

    return 0;
}


void kbread(){
    char input = getchar();

    switch (input)
    {
        case 'a': change_dir(0, -1); break;
        case 'd': change_dir(0, 1); break;
        case 'w': change_dir(-1, 0); break;
        case 's': change_dir(1, 0); break;
        
    }
    
}