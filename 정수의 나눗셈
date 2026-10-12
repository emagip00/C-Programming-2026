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

    // 1. 정수의 나눗셈 적용 (소수점이 버려짐)
    // 총합(정수) / 2(정수) 연산이 먼저 수행되어 소수점이 잘려나간 뒤 double에 저장됨
    avg_integer_div = (korean + math) / 2;

    // 2. 실수의 나눗셈 적용 (정확한 계산)
    // 2.0(실수)으로 나누어 소수점 단위까지 정확히 계산됨
    avg_real_div = (korean + math) / 2.0;

    printf("\n[ 계산 결과 ]\n");
    printf("정수 나눗셈을 사용한 평균: %.1f\n", avg_integer_div);
    printf("실수 나눗셈을 사용한 평균: %.1f\n", avg_real_div);

    return 0;
}
