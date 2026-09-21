#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h> // 한글 깨짐 방지 헤더

int main(void) {
    // 윈도우 한글 기본 인코딩(CP949) 설정 (한글 깨짐 방지)
    SetConsoleOutputCP(949);

    int menu;

    printf("==============================\n");
    printf("     단위 변환 및 실습 프로그램     \n");
    printf("==============================\n");
    printf("1. inch -> cm 변환\n");
    printf("2. 섭씨(℃) -> 화씨(℉) 변환\n");
    printf("3. 초 -> 시간·분·초 변환\n");
    printf("4. 성적 가증 평균\n");
    printf("5. EXEC 권한 추가 (비트 연산)\n");
    printf("6. 윤년 판별\n");
    printf("7. 금액 분해\n");
    printf("8. BMI 계산\n");
    printf("9. 반지름 계산\n");
    printf("==============================\n");
    printf("원하는 메뉴 번호를 선택하세요 (1~7): ");
    scanf("%d", &menu);

    if (menu == 1) {
        double inch, cm;
        printf("\n[ inch -> cm 변환 ]\n");
        printf("인치(inch)를 입력하세요: ");
        scanf("%lf", &inch);

        // 1 inch = 2.54 cm
        cm = inch * 2.54;
        printf("%.2f inch는 %.2f cm입니다.\n", inch, cm);
    }
    else if (menu == 2) {
        double celsius, fahrenheit;
        printf("\n[ 섭씨 -> 화씨 변환 ]\n");
        printf("섭씨(℃) 온도를 입력하세요: ");
        scanf("%lf", &celsius);

        // F = C * 1.8 + 32
        fahrenheit = (celsius * 1.8) + 32.0;
        printf("섭씨 %.2f℃는 화씨 %.2f℉입니다.\n", celsius, fahrenheit);
    }
    else if (menu == 3) {
        printf("\n[ 초 -> 시·분·초 변환 ]\n");

        int total;
        printf("초(sec)를 입력하세요: ");
        scanf("%d", &total);

        int hours = total / 3600;            // 1시간 = 3600초
        int minutes = (total % 3600) / 60;   // 남은 초에서 분 계산
        int seconds = total % 60;            // 최종 남은 초

        printf("%d초 = %d시간 %d분 %d초\n", total, hours, minutes, seconds);
    }
    else if (menu == 4) {
        printf("\n[ 합격 여부 판단 ]\n");

        int score, attendance;
        printf("점수를 입력하세요: ");
        scanf("%d", &score);

        printf("출석률(%%)을 입력하세요: ");
        scanf("%d", &attendance);

        // 점수 60점 이상 AND 출석률 80% 이상 조건
        int passed = (score >= 60) && (attendance >= 80);

        printf("입력된 점수: %d점, 출석률: %d%%\n", score, attendance);
        printf("합격 여부 (1: 합격, 0: 불합격): %d\n", passed);
    }
    else if (menu == 5) {
        printf("\n[ EXEC 권한 추가 (비트 연산) ]\n");

        unsigned int EXEC = 0x04; // 0000 0100 (EXEC 권한)
        unsigned int permission;

        printf("현재 권한 값(16진수, 예: 3 또는 0x03)을 입력하세요: ");
        scanf("%x", &permission);

        printf("입력 전 권한 값: 0x%02X\n", permission);

        // EXEC 권한 추가 (비트 OR 연산)
        permission |= EXEC;

        printf("EXEC 권한(0x04) 추가 후 최종 권한 값: 0x%02X\n", permission);
    }
    else if (menu == 6) {

        // 윈도우 한글 기본 인코딩(CP949) 설정
        SetConsoleOutputCP(949);

        int year;

        printf("연도를 입력하세요: ");
        scanf("%d", &year);

        // 윤년 조건 분해
        // 1. 4의 배수인가?
        int multiple_of_4 = (year % 4 == 0);
        // 2. 100의 배수인가?
        int multiple_of_100 = (year % 100 == 0);
        // 3. 400의 배수인가?
        int multiple_of_400 = (year % 400 == 0);

        // 윤년 판별 logic: 400의 배수이거나 (4의 배수이면서 100의 배수가 아님)
        int is_leap = multiple_of_400 || (multiple_of_4 && !multiple_of_100);

        printf("%d\n", is_leap);
    }


    else if (menu == 7) {
        // 윈도우 한글 기본 인코딩(CP949) 설정
        SetConsoleOutputCP(949);

        int amount;

        printf("금액을 입력하세요: ");
        scanf("%d", &amount);

        // 10,000원권 개수 계산 및 남은 금액 업데이트
        int won10000 = amount / 10000;
        amount %= 10000;

        // 1,000원권 개수 계산 및 남은 금액 업데이트
        int won1000 = amount / 1000;
        amount %= 1000;

        // 100원 동전 개수 계산 및 남은 금액 업데이트
        int won100 = amount / 100;
        amount %= 100;

        // 10원 동전 개수 계산
        int won10 = amount / 10;

        // 결과 출력
        printf("10000:%d 1000:%d 100:%d 10:%d\n", won10000, won1000, won100, won10);

        return 0;
    }
    else if (menu == 8) {
        // 윈도우 한글 기본 인코딩(CP949) 설정
        SetConsoleOutputCP(949);

        double height, weight;

        // 키(m)와 몸무게(kg) 입력받기
        printf("키(m)와 몸무게(kg)를 입력하세요 (예: 1.70 65.0): ");
        scanf("%lf %lf", &height, &weight);

        // BMI 계산 공식: 몸무게 / (키 * 키)
        double bmi = weight / (height * height);

        // 소수 둘째 자리까지 출력
        printf("bmi = %.2f\n", bmi);

        return 0;
        }
    else if (menu == 9) {
            // 윈도우 한글 기본 인코딩(CP949) 설정 (한글 깨짐 방지)
            SetConsoleOutputCP(949);

            double radius;
            const double PI = 3.141592; // 원주율 상수 선언

            // 사용자로부터 반지름 입력받기
            printf("원의 반지름을 입력하세요: ");
            scanf("%lf", &radius);

            // 계산식
            // 원의 둘레(원주) = 2 * PI * 반지름
            double circumference = 2.0 * PI * radius;

            // 원의 넓이 = PI * 반지름 * 반지름
            double area = PI * radius * radius;

            // 결과 출력 (소수점 둘째 자리까지)
            printf("\n[ 계산 결과 ]\n");
            printf("반지름: %.2f\n", radius);
            printf("원의 둘레: %.2f\n", circumference);
            printf("원의 넓이: %.2f\n", area);

            return 0;
        }

    return 0;
}
