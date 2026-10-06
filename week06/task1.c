#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int grade;
    printf("학년을 입력하세요 : ");
    scanf("%d", &grade);

    // switch-case 변환 버전
    switch (grade) {
        case 1:
            printf("1학년입니다.\n");
            break;
        case 2:
            printf("2학년입니다.\n");
            break;
        case 3:
            printf("3학년입니다.\n");
            break;
        default:
            printf("잘못된 값을 입력함\n");
            break;
    }

    return 0;
}