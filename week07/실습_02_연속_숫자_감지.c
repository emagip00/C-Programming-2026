#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int num;
    int prev = 0;      // 1~9 만 유효하므로 0 은 "아직 입력 없음" 표시로 안전하다
    int streak = 0;
    int total = 0;
    int c;

    printf("[ 같은 숫자 세 번 연속 ]\n");

    while (streak < 3) {
        printf("숫자를 입력하세요 (1~9): ");

        if (scanf("%d", &num) != 1) {
            if (feof(stdin)) {
                printf("\n입력이 종료되었습니다.\n");
                break;
            }
            printf("오류: 정수만 입력할 수 있습니다.\n");
            while ((c = getchar()) != '\n' && c != EOF) { }  // 잘못된 입력 비우기
            continue;
        }

        if (num < 1 || num > 9) {
            printf("오류: 1~9 사이의 숫자만 입력할 수 있습니다.\n");
            continue;
        }

        total++;

        if (num == prev) {
            streak++;
        }
        else {
            prev = num;
            streak = 1;
        }
    }

    if (streak < 3) {
        printf("3번 연속 입력이 완성되지 않았습니다. (전체 %d회)\n", total);
    }
    else {
        printf("숫자 %d가 3번 연속 → 전체 %d회\n", prev, total);
    }

    return 0;
}
