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
char input = ' ';
int cursor_pos = 0;

void print_board(void);
void fill_board(void);
void start_position(void);
void clearConsole(void);
void kbread(void);
void move_cursor(int new_pos);


int main(int argc, char *argv[]){

    float wait = (double) 1/fps;
    __uint8_t pos_started = 0;

    

    fill_board();
    start_position();
    print_board();

    while (1 && input != 'q'){
        print_board();
        if(kbhit() == 1)
            kbread();
        sleep(wait);
        clearConsole();
    }
}

void kbread(){
    input = getchar();

    switch (input)
    {
    case 'w':
        move_cursor(cursor_pos - b_w);
        break;
    case 'a':
        move_cursor(cursor_pos - 1);
        break;
    case 's':
        move_cursor(cursor_pos + b_w);
        break;    
    case 'd':
        move_cursor(cursor_pos + 1);
        break;                
    default:
        break;
    }
}

void move_cursor(int new_pos){
    board[cursor_pos] = ' ';
    cursor_pos = new_pos;
    board[cursor_pos] = '*';
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
    srand(time(NULL));
    while(board[cursor_pos] == '#'){
        cursor_pos =  rand() % ((board_size-1) - 0 + 1) + 0;
    }

    //printf("pos: %d \n", pos);

    board[cursor_pos] = '*';
}

void clearConsole() {
    printf("\033[2J\033[H"); // ANSI escape code for clearing the console
}


