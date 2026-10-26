#include <stdio.h>

void printStar(void){
    char star = '*';
    int line;

    printf("input line : ");

    // [수정] scanf 반환값을 검사한다. 원본은 문자를 입력하면
    //        초기화되지 않은 line 으로 반복 횟수를 정했다
    if(scanf("%d", &line) != 1){
        printf("입력 오류: 정수를 입력하세요.\n");
        return;
    }

    // [수정] 범위를 확인한다 (원본은 0 이하면 아무것도 출력하지 않고 끝났다)
    if(line < 1 || line > 50){
        printf("오류: 1 부터 50 사이의 값을 입력하세요.\n");
        return;
    }

    for(int i = 0; i < line; i++){

        for(int space = 0; space < line - 1 - i; space++) {
            printf(" ");
        }

        int star_count = i * 2 + 1;
        for(int j = 0; j < star_count; j++) {
            printf("%c", star);
        }

        printf("\n");
    }
}

int main(void)
{
    printStar();
    return 0;
}
