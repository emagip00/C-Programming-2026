#include <stdio.h>

void exerc4(void){
    int sum = 0;     
    double avg;
    int score;
    int i = 0;
    
    while(1){
        
        printf("input score (종료는 -2) : ");
        scanf("%d", &score);
        
        if(score == -2) break;     
        if(score == -1) continue; 
        
        sum += score;
        i++;
        printf("run\n");
    }
    
    if (i > 0) {
        avg = sum / (double)i;
        printf("avg = %lf\n", avg);
    } else {
        printf("입력된 유효한 점수가 없습니다.\n");
    }
}

int main()
{
    exerc4();
    return 0;
}