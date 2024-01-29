#include<stdio.h>
#include "stack.h"

int printMenu(void);

int main(){
    int op = printMenu();

    while(op == 1 || op == 2){

        if(op == 1){
            int n;
            printf("Type a number: ");
            scanf("%d", &n);
            push(n);
            printf("\n");
        }
        else if(op == 2){
            int n = pop();
            if(n != -1)
                printf("Popped number: %d \n", n);
        }

        op = printMenu();

    }   

}


int printMenu(){
    int op;
    printf("Select an option: \n");
    printf("-- 1. Push a number. \n");
    printf("-- 2. Pop a number.\n");
    scanf("%d", &op);
    printf("\n\n\n");
    return op;
}