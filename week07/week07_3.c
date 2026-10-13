#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int n;

    printf("[ 속이 빈 정사각형 ]\n");
    printf("정수 n을 입력하세요 (1~9): ");
    scanf("%d", &n);

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