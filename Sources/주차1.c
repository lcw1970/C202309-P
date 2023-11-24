#include <stdio.h>
#include <stdlib.h>

void CarTypes() { // 자동차 종류를 고르는 함수
	printf("주차 가능한 자동차 종류:\n");
	printf("1. 경차\n");
	printf("2. 승합차\n");
	printf("3. 트럭\n");
}
int main() {
	int car; // 자동차의 종류
	int coin; // 주차 기본요금
	int car_seat[3][10]; // 주차자리 배열
	int count_1 = 30; // 경차자리의 남은 주차자리
	int count_2 = 20; // 승합차의 남은 주차자리
	int count_3 = 10; // 트럭의 남은 주차자리
	CarTypes();
	scanf_s("%d", &car); // 자동차 종류를 받아옴
	if (car == 1) { // if문으로 자동차별 주차요금과 남은 주차자리 갯수를 알려줌
		printf("경차는 기본요금은 2000원 1시간당 1000원입니다.\n");
		coin = 2000;
		printf("경차의 남은 주차자리 개수는 %d개 입니다.\n", count_1);
	}
	else if (car == 2) {
		printf("승합차는 기본요금은 3000원 1시간당 1500원입니다.\n");
		coin = 3000;
		printf("승합차의 남은 주차자리 개수는 %d개 입니다.\n", count_2);
	}
	else if (car == 3) {
		printf("트럭은 기본요금은 3500원 1시간당 2000원입니다.\n");
		coin = 3500;
		printf("트럭의 남은 주차자리 개수는 %d개 입니다.\n", count_3);
	}
	else {
		printf("번호를 잘못입력하셨습니다.");
	}
	return 0;
}