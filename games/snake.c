#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>
#include"../utils/utils.h"

#define fps 30
#define b_w 20
#define b_h 20
#define board_size b_w * b_h


char board [board_size];

void print_board(void);
void fill_board(void);
void start_position(void);
void clearConsole(void);


int main(int argc, char *argv[]){

    float wait = (double) 1/fps;
    __uint8_t pos_started = 0;

    char input = ' ';

    while (1 && input != 'q'){
        fill_board();
        start_position();
        print_board();
        if(kbhit() == 1)
            input = getchar();

        sleep(wait);
        clearConsole();
    }
}

void fill_board(void){
    for (int i = 0; i < b_w; i++){
        for(int j = 0; j< b_h; j++){
            if(i == 0 || j == 0 || i == b_w -1 || j == b_h -1){
                board[i*b_w + j] = '#';
            }else{
                board[i*b_w + j] = ' ';
            }
        }
    }
}


void print_board(void){
    for (int i =0; i< b_w; i++){
        for(int j = 0; j< b_h; j++){
            putchar(board[i*b_w + j]);
        }
        putchar('\n');
    }

}

void start_position(){
    int pos = 0;
    srand(time(NULL));
    while(board[pos] == '#'){
        pos =  rand() % ((board_size-1) - 0 + 1) + 0;
    }

    //printf("pos: %d \n", pos);

    board[pos] = '*';
}

void clearConsole() {
    printf("\033[2J\033[H"); // ANSI escape code for clearing the console
}


