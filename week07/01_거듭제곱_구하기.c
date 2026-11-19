#include <stdio.h>

void exerc1(void){
    int n, r, abs_r;
    double x;
    x = 1.0;

    printf("input n, r : ");

    if(scanf("%d%d", &n, &r) != 2){
        printf("입력 오류: 정수 두 개를 입력하세요.\n");
        return;
    }

    if(r < 0) abs_r = -r;
    else abs_r = r;

    for(int i=0;i<abs_r;i++){
        x *= n;
    }

    if(r < 0){
        if(n == 0){
            printf("오류: 0 의 음수 승은 정의되지 않습니다.\n");
            return;
        }
        x = 1.0 / x;
    }

    printf("%d의 %d승은 %lf 입니다.\n", n, r, x);
}

int main(void)
{
    exerc1();
    return 0;
}
