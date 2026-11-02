#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 30

int main()
{
    int number[SIZE];
    srand(time(NULL));
    
    for(int i=0; i<SIZE; i++) number[i] = rand() % 101;
    
    for(int i=0; i<SIZE; i++){
        if(i % 10 == 0) printf("\n");
        printf("%3d ", number[i]);
    }
    
    return 0;
}