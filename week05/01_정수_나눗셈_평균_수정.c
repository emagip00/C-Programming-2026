#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int korean = 0;
    int math = 0;
    double avg_integer_div;
    double avg_real_div;

    printf("국어 점수를 입력하세요: ");
    if (scanf("%d", &korean) != 1) {
        printf("입력 오류: 정수를 입력하세요.\n");
        return 1;
    }

    printf("수학 점수를 입력하세요: ");
    if (scanf("%d", &math) != 1) {
        printf("입력 오류: 정수를 입력하세요.\n");
        return 1;
    }

    // 정수 나눗셈: 두 정수의 합을 정수 2로 나누므로 소수점이 버려진다
    avg_integer_div = (korean + math) / 2;

    // [수정] 실수 나눗셈: 2.0 으로 나눠 소수점을 살린다
    //        원본은 이 계산이 없어 초기화되지 않은 값을 그대로 출력했다
    avg_real_div = (korean + math) / 2.0;

    printf("\n[ 계산 결과 ]\n");
    printf("정수 나눗셈을 사용한 평균: %.1f\n", avg_integer_div);
    printf("실수 나눗셈을 사용한 평균: %.1f\n", avg_real_div);

    return 0;
}
