#include <stdio.h>

void printStar(void){
    char star = '*';
    int line;
    
    printf("input line : ");
    scanf("%d", &line);
    
    for(int i = 0; i < line; i++){
        
        for(int space = 0; space < line - 1 - i; space++) {
            printf(" ");
        }
        
        
        int star_count = i * 2 + 1;
        for(int j = 0; j < star_count; j++) {
            printf("%c", star);
        }
        
        
        printf("\n");
    }
}

int main()
{
    printStar(); 
    return 0;
}