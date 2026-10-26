#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int score;
    int count = 0;
    int sum = 0;
    int c;

    printf("[ 유효한 점수 세 개 ]\n");

    while (count < 3) {
        printf("점수를 입력하세요 (0~100, 종료는 -1): ");

        // [수정] 원본은 scanf 반환값을 검사하지 않아, 문자나 EOF 입력 시
        //        초기화되지 않은 score 를 3번 세고 "유효한 점수: 3개,
        //        평균: 0.00" 같은 엉뚱한 결과를 조용히 출력했다
        if (scanf("%d", &score) != 1) {
            if (feof(stdin)) {
                printf("\n입력이 종료되었습니다.\n");
                break;
            }
            printf("오류: 정수만 입력할 수 있습니다.\n");
            while ((c = getchar()) != '\n' && c != EOF) { }  // 잘못된 입력 비우기
            continue;
        }

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
