#include <stdio.h>
#include "parking.h"
int coin[] = { 2000, 3000, 4000 ,25000 };
int park[4][10] = { {0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,1,1,1,1,1 },{0,0,0,1,1,1,1,1,1,1},{0,0,0,1,1,1,1,1,1,1} };
// 0은 주차 빈공간 1은 주차되어있는 자리 승합차랑 트럭은 각각 5자리 3자리이기 때문에 나머지는 1로 표현
// 자동차 종류에 대한 정보를 담은 배열
CarTypeInfo carTypes[] = {
	{1, "경차"},
	{2, "승합차"},
	{3, "트럭"},
	{4, "전기차"}
};
void CarTypes() { // 자동차 종류를 고르는 함수
	printf("---------------------\n");
	printf("자동차 종류를 골라주세요:\n");

	// 자동차 종류 출력
	for (int i = 0; i < sizeof(carTypes) / sizeof(carTypes[0]); ++i) {
		printf("%d. %s\n", carTypes[i].type, carTypes[i].description);
	}

	printf("---------------------\n");
}

int calcurater(int a) { // 거스름돈 함수 11/27에 추가 12/3 수정
	int money;

	while (1) {
		printf("---------------------\n");
		printf("내실돈은 %d입니다. 얼마를 내실건가요?\n", coin[a]);
		scanf_s("%d", &money);

		if (money == coin[a]) {
			printf("감사합니다. ");
			break;
		}

		else if (money > coin[a]) {
			printf("거스름돈은 %d입니다. 감사합니다.\n", money - coin[a]);
			break;
		}

		else if (money < coin[a]) {
			printf("돈이 부족합니다.\n");
			continue;
		}
	}
}

int Parkspace() { // 11/30일 주차 함수
	int num;

	printf("---------------------\n");
	printf("몇번섹션에 주차하시나요? ");
	scanf_s("%d", &num); // 주차자리 번호
	printf("---------------------\n");
	return num;
}
int parkspace2(int a) { // 12/2일 남은자리 표현하는 함수
	printf("남은섹션 번호는 ");

	for (int i = 0; i < 10; i++) {

		if (park[a][i] != 1) {
			printf("%d번 ", i + 1);
		}
	}
	printf("입니다.\n");
}
