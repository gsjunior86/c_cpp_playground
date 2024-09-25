#include <stdio.h>

#define HOST_SIZE 250

typedef struct Params {
    char host[HOST_SIZE];
    char output_format;
};

char isEquals(char *str1, char *str2);

int main(int argc, char *argv[]){

    //printf("%d \n",);

    if(argc < 2){
        printf("Missing database \n");
    }else{
    

    printf("Equals: %d \n", isEquals);
    }
  

    return 0;
}

