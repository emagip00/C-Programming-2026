#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {
    int scores[SIZE];
    int max, min, sum = 0;
    double average;
    int temp;

    srand(time(NULL));

    printf("--- 정렬 전 학생별 점수 ---\n");
    for (int i = 0; i < SIZE; i++) {
        scores[i] = rand() % 101; 
        printf("학생 %2d: %3d점\n", i + 1, scores[i]);
        sum += scores[i];
    }

    max = scores[0];
    min = scores[0];

    for (int i = 1; i < SIZE; i++) {
        if (scores[i] > max) max = scores[i];
        if (scores[i] < min) min = scores[i];
    }

    average = (double)sum / SIZE;

    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - 1 - i; j++) {
            if (scores[j] > scores[j + 1]) {
                temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
            }
        }
    }

    printf("\n--- 정렬 후 학생별 점수 (오름차순) ---\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%3d점 ", scores[i]);
    }
    printf("\n");

    printf("\n--- 전체 결과 ---\n");
    printf("최댓값: %d점\n", max);
    printf("최솟값: %d점\n", min);
    printf("평  균: %.2f점\n", average);

    return 0;
}