#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int a, b;
    int quotient, remainder;

    printf("두 정수를 입력하세요 (a b): ");
    if (scanf("%d %d", &a, &b) != 2) {
        printf("입력 오류: 정수 두 개를 입력하세요.\n");
        return 1;
    }

    if (b == 0) {
        printf("오류: 0 으로는 나눌 수 없습니다.\n");
        return 1;
    }

    quotient = a / b;
    remainder = a % b;

    printf("몫: %d\n", quotient);
    printf("나머지: %d\n", remainder);

    return 0;
}
