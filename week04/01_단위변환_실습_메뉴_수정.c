#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// [수정] 입력 실패를 한 곳에서 처리한다. 원본은 모든 scanf 의 반환값을
//        검사하지 않아 문자를 입력하면 초기화되지 않은 값으로 계산했다
static int read_int(const char *prompt, int *out) {
    printf("%s", prompt);
    if (scanf("%d", out) != 1) {
        printf("입력 오류: 정수를 입력하세요.\n");
        return 0;
    }
    return 1;
}

static int read_double(const char *prompt, double *out) {
    printf("%s", prompt);
    if (scanf("%lf", out) != 1) {
        printf("입력 오류: 숫자를 입력하세요.\n");
        return 0;
    }
    return 1;
}

int main(void) {
    int menu;

    printf("==============================\n");
    printf("     단위 변환 및 실습 프로그램     \n");
    printf("==============================\n");
    printf("1. inch -> cm 변환\n");
    printf("2. 섭씨(℃) -> 화씨(℉) 변환\n");
    printf("3. 초 -> 시간·분·초 변환\n");
    printf("4. 합격 여부 판단\n");
    printf("5. 윤년 판별\n");
    printf("6. 금액 분해\n");
    printf("7. BMI 계산\n");
    printf("8. 원의 넓이 및 둘레 계산\n");
    printf("==============================\n");

    if (!read_int("원하는 메뉴 번호를 선택하세요 (1~8): ", &menu)) {
        return 1;
    }

    if (menu == 1) {
        double inch, cm;
        printf("\n[ inch -> cm 변환 ]\n");
        if (!read_double("인치(inch)를 입력하세요: ", &inch)) return 1;

        // 1 inch = 2.54 cm
        cm = inch * 2.54;
        printf("%.2f inch는 %.2f cm입니다.\n", inch, cm);
    }
    else if (menu == 2) {
        double celsius, fahrenheit;
        printf("\n[ 섭씨 -> 화씨 변환 ]\n");
        if (!read_double("섭씨(℃) 온도를 입력하세요: ", &celsius)) return 1;

        // F = C * 1.8 + 32
        fahrenheit = (celsius * 1.8) + 32.0;
        printf("섭씨 %.2f℃는 화씨 %.2f℉입니다.\n", celsius, fahrenheit);
    }
    else if (menu == 3) {
        printf("\n[ 초 -> 시·분·초 변환 ]\n");

        int total;
        if (!read_int("초(sec)를 입력하세요: ", &total)) return 1;

        // [수정] 음수 초는 결과가 의미 없으므로 막는다
        if (total < 0) {
            printf("오류: 0 이상의 값을 입력하세요.\n");
            return 1;
        }

        int hours = total / 3600;            // 1시간 = 3600초
        int minutes = (total % 3600) / 60;   // 남은 초에서 분 계산
        int seconds = total % 60;            // 최종 남은 초

        printf("%d초 = %d시간 %d분 %d초\n", total, hours, minutes, seconds);
    }
    else if (menu == 4) {
        printf("\n[ 합격 여부 판단 ]\n");

        int score, attendance;
        if (!read_int("점수를 입력하세요: ", &score)) return 1;
        if (!read_int("출석률(%)을 입력하세요: ", &attendance)) return 1;

        // 점수 60점 이상 AND 출석률 80% 이상 조건
        int passed = (score >= 60) && (attendance >= 80);

        printf("입력된 점수: %d점, 출석률: %d%%\n", score, attendance);
        printf("합격 여부 (1: 합격, 0: 불합격): %d\n", passed);
    }
    else if (menu == 5) {
        int year;

        printf("\n[ 윤년 판별 ]\n");
        if (!read_int("연도를 입력하세요: ", &year)) return 1;

        // 윤년 조건 분해
        int multiple_of_4 = (year % 4 == 0);
        int multiple_of_100 = (year % 100 == 0);
        int multiple_of_400 = (year % 400 == 0);

        // 윤년 판별 logic
        int is_leap = multiple_of_400 || (multiple_of_4 && !multiple_of_100);

        printf("윤년 여부 (1: 윤년, 0: 평년): %d\n", is_leap);
    }
    else if (menu == 6) {
        int amount;

        printf("\n[ 금액 분해 ]\n");
        if (!read_int("금액을 입력하세요: ", &amount)) return 1;

        // [수정] 음수 금액은 분해 결과가 의미 없으므로 막는다
        if (amount < 0) {
            printf("오류: 0 이상의 금액을 입력하세요.\n");
            return 1;
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
    else if (menu == 7) {
        double height, weight;

        printf("\n[ BMI 계산 ]\n");
        printf("키(m)와 몸무게(kg)를 입력하세요 (예: 1.70 65.0): ");
        if (scanf("%lf %lf", &height, &weight) != 2) {
            printf("입력 오류: 숫자 두 개를 입력하세요.\n");
            return 1;
        }

        // [수정] 키가 0 이면 0 으로 나누게 되어 inf/nan 이 출력된다
        if (height <= 0.0) {
            printf("오류: 키는 0 보다 커야 합니다.\n");
            return 1;
        }

        double bmi = weight / (height * height);

        printf("bmi = %.2f\n", bmi);
    }
    else if (menu == 8) {
        double radius;
        const double PI = 3.141592;

        printf("\n[ 원의 넓이 및 둘레 계산 ]\n");
        if (!read_double("원의 반지름을 입력하세요: ", &radius)) return 1;

        // [수정] 음수 반지름은 둘레가 음수로 나오므로 막는다
        if (radius < 0.0) {
            printf("오류: 반지름은 0 이상이어야 합니다.\n");
            return 1;
        }

        double circumference = 2.0 * PI * radius;
        double area = PI * radius * radius;

        printf("\n[ 계산 결과 ]\n");
        printf("반지름: %.2f\n", radius);
        printf("원의 둘레: %.2f\n", circumference);
        printf("원의 넓이: %.2f\n", area);
    }
    else {
        printf("\n잘못된 메뉴 번호입니다. 1에서 8 사이의 숫자를 입력해 주세요.\n");
    }

    return 0;
}
