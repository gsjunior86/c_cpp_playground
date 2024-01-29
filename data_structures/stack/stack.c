#include<stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int n){
    if(top == MAX - 1){
        printf("Full Stack !!!\n");
        return;
    }
    stack[++top] = n;        
}

int pop(){
    if(top == -1){
        printf("Stack is empty\n");
        return -1;
    }
    printf("Top Value: %d", top);
    return stack[top--];
}
