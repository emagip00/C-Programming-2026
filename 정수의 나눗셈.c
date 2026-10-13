#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int korean = 0;
    int math = 0;
    double avg_integer_div;
    double avg_real_div;

    printf("국어 점수를 입력하세요: ");
    scanf("%d", &korean); // 에러 원인 수정: & 기호 추가

    printf("수학 점수를 입력하세요: ");
    scanf("%d", &math);

  
    avg_integer_div = (korean + math) / 2;

    printf("\n[ 계산 결과 ]\n");
    printf("정수 나눗셈을 사용한 평균: %.1f\n", avg_integer_div);
    printf("실수 나눗셈을 사용한 평균: %.1f\n", avg_real_div);

    return 0;
}
