#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int a, b;
    int quotient, remainder;

    printf("두 정수를 입력하세요 (a b): ");
    scanf("%d %d", &a, &b);

    quotient = a / b;
    remainder = a % b;

    printf("몫: %d\n", quotient);
    printf("나머지: %d\n", remainder);

    return 0;
}