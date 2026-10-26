#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
 * 과제 8 - 성적 가중평균
 *
 * 항목마다 비중이 다를 때의 평균(가중평균)을 구한다.
 *
 *   가중평균 = (점수1 x 가중치1 + 점수2 x 가중치2 + ...) / 가중치 합계
 *
 * 비교를 위해 모든 항목을 똑같이 취급하는 산술평균도 함께 출력한다.
 *
 * [가중치 변경 방법]
 * 과제 명세의 비율이 아래와 다르면 이 네 상수만 바꾸면 된다.
 * 합이 100.0 이 아니면 프로그램이 알려준다.
 */
#define W_MIDTERM    30.0   // 중간고사 30%
#define W_FINAL      30.0   // 기말고사 30%
#define W_HOMEWORK   20.0   // 과제     20%
#define W_ATTENDANCE 20.0   // 출석     20%

// 점수 하나를 입력받아 0~100 범위인지까지 확인한다
static int read_score(const char *item, double *out) {
    printf("%s 점수를 입력하세요 (0~100): ", item);

    if (scanf("%lf", out) != 1) {
        printf("입력 오류: 숫자를 입력하세요.\n");
        return 0;
    }
    if (*out < 0.0 || *out > 100.0) {
        printf("오류: 0 부터 100 사이의 점수만 입력할 수 있습니다.\n");
        return 0;
    }
    return 1;
}

int main(void) {
    double midterm, final, homework, attendance;

    const double total_weight = W_MIDTERM + W_FINAL + W_HOMEWORK + W_ATTENDANCE;

    printf("==============================\n");
    printf("        성적 가중평균 계산        \n");
    printf("==============================\n");
    printf("가중치 - 중간고사 %.0f%%, 기말고사 %.0f%%, 과제 %.0f%%, 출석 %.0f%%\n",
           W_MIDTERM, W_FINAL, W_HOMEWORK, W_ATTENDANCE);
    printf("==============================\n");

    // 가중치 합이 100 이 아니면 가중평균이 성적 범위를 벗어나므로 먼저 확인
    if (total_weight != 100.0) {
        printf("\n오류: 가중치의 합이 %.1f%% 입니다. 100%% 가 되도록 맞춰 주세요.\n",
               total_weight);
        return 1;
    }

    if (!read_score("중간고사", &midterm))    return 1;
    if (!read_score("기말고사", &final))      return 1;
    if (!read_score("과제", &homework))       return 1;
    if (!read_score("출석", &attendance))     return 1;

    // 각 항목이 최종 점수에 기여하는 몫 (점수 x 가중치 / 100)
    double part_midterm    = midterm    * W_MIDTERM    / 100.0;
    double part_final      = final      * W_FINAL      / 100.0;
    double part_homework   = homework   * W_HOMEWORK   / 100.0;
    double part_attendance = attendance * W_ATTENDANCE / 100.0;

    double weighted_avg = part_midterm + part_final + part_homework + part_attendance;

    // 가중치를 무시하고 네 항목을 똑같이 나눈 평균
    double simple_avg = (midterm + final + homework + attendance) / 4.0;

    printf("\n[ 항목별 기여 점수 ]\n");
    printf("중간고사 : %6.2f점 x %.0f%% = %6.2f점\n", midterm,    W_MIDTERM,    part_midterm);
    printf("기말고사 : %6.2f점 x %.0f%% = %6.2f점\n", final,      W_FINAL,      part_final);
    printf("과제     : %6.2f점 x %.0f%% = %6.2f점\n", homework,   W_HOMEWORK,   part_homework);
    printf("출석     : %6.2f점 x %.0f%% = %6.2f점\n", attendance, W_ATTENDANCE, part_attendance);

    printf("\n[ 계산 결과 ]\n");
    printf("가중평균 : %.2f점\n", weighted_avg);
    printf("산술평균 : %.2f점\n", simple_avg);
    printf("차이     : %+.2f점 (가중평균 - 산술평균)\n", weighted_avg - simple_avg);

    return 0;
}
