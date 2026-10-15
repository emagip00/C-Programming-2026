#include <stdio.h>

void exerc1(void){
    int n, r, abs_r;
    double x;
    x = 1.0;
    
    printf("input n, r : ");
    scanf("%d%d", &n, &r);
    
    if(r < 0) abs_r = -r;
    else abs_r = r;
    
    for(int i=0;i<abs_r;i++){
        x *= n;
    }
    
    if(r < 0) x = 1.0 / x;
    
    printf("%d의 %d승은 %lf 입니다.\n", n, r, x);
}

int main()
{
    exerc1();
    return 0;
}