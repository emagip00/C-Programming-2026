#include <stdio.h>

void printStar(void){
    char star = '*';
    int line;

    printf("input line : ");

    if(scanf("%d", &line) != 1){
        printf("입력 오류: 정수를 입력하세요.\n");
        return;
    }

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
