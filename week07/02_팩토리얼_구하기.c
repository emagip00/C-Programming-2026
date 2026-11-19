#include <stdio.h>

void exerc2(void){
    int n;

    unsigned long long result = 1;

    printf("input n : ");

    if(scanf("%d", &n) != 1){
        printf("입력 오류: 정수를 입력하세요.\n");
        return;
    }

    if(n < 0){
        printf("오류: 0 이상의 정수를 입력하세요.\n");
        return;
    }
    if(n > 20){
        printf("오류: 21! 이상은 표현할 수 없습니다. 0~20 을 입력하세요.\n");
        return;
    }

    for(int i = n; i > 0; i--) {
        result *= (unsigned long long)i;
    }

    printf("%d factorial = %llu입니다.\n", n, result);
}

int main(void)
{
    exerc2();
    return 0;
}
