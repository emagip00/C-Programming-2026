#include <stdio.h>

void exerc1(void){ }
void exerc2(void){ }

void exerc3(void){
    int n;
    int n_1, n_2, result;
    n_2 = 0;
    n_1 = 1;
    
    printf("input n : ");
    scanf("%d", &n);
    
    if(n==0) result = n_2;
    else if(n==1) result = n_1;
    else{
        for(int i=2; i<=n; i++){
            result = n_1 + n_2;
            n_2 = n_1;
            n_1 = result;
        }
    }
    printf("%d 번째 숫자는 %d 입니다.", n, result);
}

int main()
{
    exerc3();
    return 0;
}