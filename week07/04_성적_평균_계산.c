#include <stdio.h>

void exerc4(void){
    int sum = 0;
    double avg;
    int score;
    int i = 0;
    int c;

    while(1){

        printf("input score (종료는 -2) : ");

        if(scanf("%d", &score) != 1){
            if(feof(stdin)){
                printf("\n입력이 종료되었습니다.\n");
                break;
            }
            printf("오류: 정수만 입력할 수 있습니다.\n");
            while((c = getchar()) != '\n' && c != EOF) { }  // 잘못된 입력 비우기
            continue;
        }

        if(score == -2) break;
        if(score == -1) continue;

        sum += score;
        i++;
    }

    if (i > 0) {
        avg = sum / (double)i;
        printf("avg = %lf\n", avg);
    } else {
        printf("입력된 유효한 점수가 없습니다.\n");
    }
}

int main(void)
{
    exerc4();
    return 0;
}
