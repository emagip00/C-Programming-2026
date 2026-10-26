#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
# define READ 0x01
# define WRITE 0x02
# define EXEC 0x04

// 시, 분, 초 계산
void exerc1(void) {
	int total = 7384;
	int hours = total/3600;
	int minutes = (total % 3600) / 60;
	int seconds = total % 60;
	printf("%d h, %d m, %d s. \n", hours, minutes, seconds);
}

// 점수가 60이상, 출석률 80 이상
void exerc2(void) {
	int score, check;
	scanf("%d", &score);
	scanf("%d", &check);

	int passed = score >= 60 && check >= 80;
	printf("%d \n", passed);
}

// EXEC 권한 추가
void exerc3(void) {
	unsigned int permission = READ | WRITE;
	permission |= EXEC;
}

// 윤년 계산
void exerc4(void) {
	int year;
	scanf("%d", &year);

	int is_leap_year = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
	printf("%d\n", is_leap_year);
}

// 금액을 화폐 단위로 분해
void exerc5(void) {
	int amount;
	scanf("%d", &amount);

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
	// exerc1();
	// exerc2();
	// exerc3();
	// exerc4();
	// exerc5();
}
