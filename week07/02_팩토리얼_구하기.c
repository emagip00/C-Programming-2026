#include <stdio.h>

void exerc1(void){ }

void exerc2(void){
    int n, result;
    result = 1;
    
    printf("input n : ");
    scanf("%d", &n);
    
    for(int i = n; i > 0; i--) {
        result *= i;
    }
    
    printf("%d factorial = %d입니다.", n, result);
}

int main()
{
    exerc2();
    return 0;
}