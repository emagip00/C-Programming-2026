#include <stdio.h>

void exerc4(void){
    int sum = 0;
    double avg;
    int score;
    int i = 0;
    int c;

    while(1){

        printf("input score (종료는 -2) : ");

        // [수정] 원본은 scanf 반환값을 검사하지 않아, 문자를 입력하거나
        //        입력이 끝나면(EOF) 같은 문자가 버퍼에 남아 영원히 반복됐다
        //        (2초에 약 280MB 출력 후 강제 종료되는 것을 확인)
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
        // [수정] 디버그용으로 남아 있던 printf("run\n") 을 제거했다
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
