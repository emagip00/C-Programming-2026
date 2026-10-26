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

        // [수정] 원본은 scanf 반환값을 검사하지 않아, 문자를 입력하면
        //        num 이 이전 값(또는 초기화되지 않은 값)을 그대로 유지했고
        //        그 값끼리 계속 같다고 판정되어 "숫자 906300144가 3번 연속"
        //        같은 결과를 조용히 출력했다
        if (scanf("%d", &num) != 1) {
            if (feof(stdin)) {
                printf("\n입력이 종료되었습니다.\n");
                break;
            }
            printf("오류: 정수만 입력할 수 있습니다.\n");
            while ((c = getchar()) != '\n' && c != EOF) { }  // 잘못된 입력 비우기
            continue;
        }

        // [수정] 안내문은 1~9 라고 했지만 원본에는 범위 검사가 없었다.
        //        이 검사가 prev 의 초기값 0 과 입력값이 겹치는 문제도 막아준다
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

    // [수정] EOF 로 중간에 끝난 경우를 구분해 출력한다
    if (streak < 3) {
        printf("3번 연속 입력이 완성되지 않았습니다. (전체 %d회)\n", total);
    }
    else {
        printf("숫자 %d가 3번 연속 → 전체 %d회\n", prev, total);
    }

    return 0;
}
