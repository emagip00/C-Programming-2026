#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int score;
    int count = 0;
    int sum = 0;

    printf("[ 유효한 점수 세 개 ]\n");

    while (count < 3) {
        printf("점수를 입력하세요 (0~100, 종료는 -1): ");
        scanf("%d", &score);

        if (score == -1) {
            break;
        }

        if (score < 0 || score > 100) {
            printf("오류: 0~100 사이의 점수만 입력할 수 있습니다.\n");
            continue;
        }

        sum += score;
        count++;
    }

    if (count == 0) {
        printf("입력된 점수가 없습니다.\n");
    }
    else {
        double average = (double)sum / count;
        printf("유효한 점수: %d개, 평균: %.2f\n", count, average);
    }

    return 0;
}
