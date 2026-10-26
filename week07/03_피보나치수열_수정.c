#include <stdio.h>

// [수정] 원본의 빈 스텁 함수 exerc1(), exerc2() 를 제거했다

void exerc3(void){
    int n;

    // [수정] int 는 47 번째 항부터 넘치므로 long long 을 쓴다
    long long n_1, n_2, result;
    n_2 = 0;
    n_1 = 1;

    printf("input n : ");

    // [수정] scanf 반환값을 검사한다
    if(scanf("%d", &n) != 1){
        printf("입력 오류: 정수를 입력하세요.\n");
        return;
    }

    // [수정] 원본은 n 이 음수일 때 result 에 아무것도 대입하지 않은 채
    //        출력해서 쓰레기값(관측값 0)이 나왔다
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
