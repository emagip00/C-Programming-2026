#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int n;

    printf("[ 속이 빈 정사각형 ]\n");
    printf("정수 n을 입력하세요 (1~9): ");

    // [수정] 원본은 scanf 반환값을 검사하지 않아, 문자나 EOF 입력 시
    //        초기화되지 않은 n (관측값 수억)으로 이중 반복문을 돌며
    //        사실상 무한루프에 빠졌다 (2초에 약 200MB 출력 확인)
    if (scanf("%d", &n) != 1) {
        printf("입력 오류: 정수를 입력하세요.\n");
        return 1;
    }

    // [수정] 안내문은 1~9 라고 했지만 원본에는 범위 검사가 없었다
    if (n < 1 || n > 9) {
        printf("오류: 1 부터 9 사이의 값을 입력하세요.\n");
        return 1;
    }

    printf("\n");

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= n; j++) {

            if (i == 1 || i == n || j == 1 || j == n) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}
