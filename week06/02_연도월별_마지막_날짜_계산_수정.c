#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int isleapyear(int year) {
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
        return 1;
    }
    return 0;
}

void exerc(void) {
    int year, month, days;

    printf("연도 입력 : ");

    // [수정] scanf 반환값을 검사한다. 원본은 문자를 입력하면
    //        초기화되지 않은 year / month 로 계산했다
    if (scanf("%d", &year) != 1) {
        printf("입력 오류: 연도를 정수로 입력하세요.\n");
        return;
    }

    printf("월 입력(1~12) : ");
    if (scanf("%d", &month) != 1) {
        printf("입력 오류: 월을 정수로 입력하세요.\n");
        return;
    }

    if (month >= 1 && month <= 12) {
        switch (month) {
            case 2:
                if (isleapyear(year) == 1) {
                    days = 29;
                } else {
                    days = 28;
                }
                break;

            case 4:
            case 6:
            case 9:
            case 11:
                days = 30;
                break;

            default: // 1, 3, 5, 7, 8, 10, 12월
                days = 31;
                break;
        }

        printf("%d년 %d월은 %d일까지 있습니다.\n", year, month, days);

    } else {
        printf("1부터 12사이의 값을 입력하세요.\n");
    }
}

int main(void) {
    exerc();
    return 0;
}
