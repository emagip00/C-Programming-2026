#include <stdio.h>

// [수정] 원본의 빈 스텁 함수 exerc1() 을 제거했다

void exerc2(void){
    int n;

    // [수정] int 는 13! 부터 넘쳐 음수/엉뚱한 값이 나왔다.
    //        unsigned long long 으로 바꾸면 20! 까지 정확하다
    unsigned long long result = 1;

    printf("input n : ");

    // [수정] scanf 반환값을 검사한다
    if(scanf("%d", &n) != 1){
        printf("입력 오류: 정수를 입력하세요.\n");
        return;
    }

    // [수정] 음수 입력과 오버플로 범위를 막는다
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
