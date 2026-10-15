#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int num;
    int prev = 0;
    int streak = 0;
    int total = 0;

    printf("[ 같은 숫자 세 번 연속 ]\n");

    while (streak < 3) {
        printf("숫자를 입력하세요 (1~9): ");
        scanf("%d", &num);

        total++;

        if (num == prev) {
            streak++;
        }
        else {
            prev = num;
            streak = 1;
        }
    }

    printf("숫자 %d가 3번 연속 → 전체 %d회\n", prev, total);

    return 0;
}
