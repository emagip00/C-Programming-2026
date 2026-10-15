#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int year;

    printf("연도를 입력하세요: ");
    if (scanf("%d", &year) != 1) {
        return 1;
    }

    if (year % 400 == 0) {
        printf("윤년입니다.\n");
    }
    else if (year % 100 == 0) {
        printf("평년입니다.\n");
    }
    else if (year % 4 == 0) {
        printf("윤년입니다.\n");
    }
    else {
        printf("평년입니다.\n");
    }

    return 0;
}
