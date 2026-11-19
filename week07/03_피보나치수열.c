#include <stdio.h>

void exerc3(void){
    int n;

    long long n_1, n_2, result;
    n_2 = 0;
    n_1 = 1;

    printf("input n : ");

    if(scanf("%d", &n) != 1){
        printf("입력 오류: 정수를 입력하세요.\n");
        return;
    }

    if(n < 0){
        printf("오류: 0 이상의 정수를 입력하세요.\n");
        return;
    }
    if(n > 90){
        printf("오류: 90 번째 항까지만 계산할 수 있습니다.\n");
        return;
    }

    if(n==0) result = n_2;
    else if(n==1) result = n_1;
    else{
        for(int i=2; i<=n; i++){
            result = n_1 + n_2;
            n_2 = n_1;
            n_1 = result;
        }
    }
    printf("%d 번째 숫자는 %lld 입니다.\n", n, result);
}

int main(void)
{
    exerc3();
    return 0;
}
