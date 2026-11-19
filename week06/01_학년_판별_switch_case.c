#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int grade;
    printf("학년을 입력하세요 : ");

    if (scanf("%d", &grade) != 1) {
        printf("입력 오류: 정수를 입력하세요.\n");
        return 1;
    }

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
