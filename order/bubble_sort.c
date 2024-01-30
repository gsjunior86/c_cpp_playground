#include<stdio.h>


void order(int[], int size);
void printArray(int[], int size);


int main(){

    int a[] = {30,40,50, 100, 15,10,7,5,1};

    printArray(a, sizeof(a) / sizeof(a[0]));
    order(a, sizeof(a) / sizeof(a[0]));

    printArray(a, sizeof(a) / sizeof(a[0]));


    return 0;
}


void order(int numbers[], int size){
    for(int i = 0; i < size - 1; ++i){
        for( int j = i + 1; j < size; ++j){
            if(numbers[i] > numbers[j]){
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }    
}

void printArray(int numbers[], int size){
    printf("{ ");
    for(int i=0; i < size; ++i)
        if(i == (size - 1))
            printf("%d }\n", numbers[i]);
        else
            printf("%d, ", numbers[i]);
        
}