#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define READ 0x01
#define WRITE 0x02
#define EXEC 0x04

// 입력 실패 시 공통 안내
static int read_int(const char *prompt, int *out) {
    printf("%s", prompt);
    if (scanf("%d", out) != 1) {
        printf("입력 오류: 정수를 입력하세요.\n");
        return 0;
    }
    return 1;
}

// 시, 분, 초 계산
void exerc1(void) {
    int total = 7384;
    int hours = total / 3600;
    int minutes = (total % 3600) / 60;
    int seconds = total % 60;
    printf("%d초 = %d h, %d m, %d s.\n", total, hours, minutes, seconds);
}

// 점수가 60이상, 출석률 80 이상
void exerc2(void) {
    int score, check;

    // [수정] scanf 반환값을 검사한다. 원본은 문자를 넣으면
    //        초기화되지 않은 값으로 합격 여부를 판정했다
    if (!read_int("점수를 입력하세요: ", &score)) return;
    if (!read_int("출석률(%)을 입력하세요: ", &check)) return;

    int passed = score >= 60 && check >= 80;
    printf("합격 여부 (1: 합격, 0: 불합격): %d\n", passed);
}

// EXEC 권한 추가
void exerc3(void) {
    unsigned int permission = READ | WRITE;

    printf("추가 전 권한: 0x%02X\n", permission);
    permission |= EXEC;

    // [수정] 원본은 계산만 하고 출력이 없어 결과를 확인할 수 없었다
    printf("EXEC 추가 후 권한: 0x%02X\n", permission);
    printf("READ=%d WRITE=%d EXEC=%d\n",
           (permission & READ) != 0,
           (permission & WRITE) != 0,
           (permission & EXEC) != 0);
}

// 윤년 계산
void exerc4(void) {
    int year;

    if (!read_int("연도를 입력하세요: ", &year)) return;

    int is_leap_year = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
    printf("윤년 여부 (1: 윤년, 0: 평년): %d\n", is_leap_year);
}

// 금액을 화폐 단위로 분해
void exerc5(void) {
    int amount;

    if (!read_int("금액을 입력하세요: ", &amount)) return;

    // [수정] 음수는 분해 결과가 의미 없으므로 막는다
    if (amount < 0) {
        printf("오류: 0 이상의 금액을 입력하세요.\n");
        return;
    }

    int won10000 = amount / 10000;
    amount %= 10000;

    int won1000 = amount / 1000;
    amount %= 1000;

    int won100 = amount / 100;
    amount %= 100;

    int won10 = amount / 10;

    printf("10000:%d 1000:%d 100:%d 10:%d\n", won10000, won1000, won100, won10);
}

int main(void)
{
    // [수정] 원본은 모든 호출이 주석 처리되어 실행해도 아무것도
    //        출력되지 않았다. 다섯 항목을 순서대로 실행한다
    printf("[ 1. 초 -> 시·분·초 변환 ]\n");
    exerc1();

    printf("\n[ 2. 합격 여부 판단 ]\n");
    exerc2();

    printf("\n[ 3. EXEC 권한 추가 ]\n");
    exerc3();

    printf("\n[ 4. 윤년 판별 ]\n");
    exerc4();

    printf("\n[ 5. 금액 분해 ]\n");
    exerc5();

    return 0;
}
