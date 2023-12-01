#include <stdio.h>
#include <stdlib.h>
int coin[] = { 2000, 3000, 4000 };
int park[3][10] = { {0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,1,1,1,1,1 },{0,0,0,1,1,1,1,1,1,1} }; // 0은 주차 빈공간 1은 주차되어있는 자리 승합차랑 트럭은 각각 5자리 3자리이기 때문에 나머지는 1로 표현

void CarTypes() { // 자동차 종류를 고르는 함수
	printf("---------------------\n");
	printf("자동차 종류를 골라주세요:\n");
	printf("1. 경차\n");
	printf("2. 승합차\n");
	printf("3. 트럭\n");
	printf("---------------------\n");
}

int calcurater(int a) { // 거스름돈 함수 11/27에 추가
	int money;
	printf("---------------------\n");
	printf("내실돈은 %d입니다. 얼마를 내실건가요?\n", coin[a]);
	scanf_s("%d", &money);
	if (money > coin[a]) {
		printf("거스름돈은 %d입니다. 감사합니다.\n", money - coin[a]);
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
int main() {
	int car; // 자동차의 종류
	int num; // 주차자리 번호
	int count_1 = 10; // 경차자리의 남은 주차자리
	int count_2 = 5; // 승합차의 남은 주차자리
	int count_3 = 3; // 트럭의 남은 주차자리
	int chose = 0; // 주차하는건지 안하는건지 선택
	while (1) {
		if (count_1 <= 0 && count_2 <= 0 && count_3 <= 0) {
			printf("주차자리가 없습니다. 죄송합니다.\n");
			break;
		}
		printf("주차를 하시는건가요 나가시는건가요? (하시면 1 나가시면 2)\n");

		scanf_s("%d", &chose);
		
		if (chose == 1) {
			
			CarTypes();
			scanf_s("%d", &car); // 자동차 종류를 받아옴
			if (car == 1) { // if문으로 자동차별 주차요금과 남은 주차자리 갯수를 알려줌
				printf("현재 경차의 남은 주차자리 개수는 %d개 입니다.\n", count_1);
				parkspace2(0);
				num = Parkspace();
				if (park[0][num - 1] != 1) {
					park[0][num - 1] = 1;

				}
				else if (park[0][num -1] == 1){
					printf("죄송합니다. 그 자리에는 이미 주차되어있습니다.\n");
					printf("---------------------\n");
					continue;
				}
				else {
					printf("번호를 잘못입력하셨습니다.\n");
					printf("---------------------\n");
					continue;
				}
				printf("---------------------\n");

				printf("경차의 %d번 섹션은 직진후 왼쪽으로 가시면 됩니다.\n",num);
				count_1--;
				
				printf("---------------------\n\n");
			}
			else if (car == 2) {
				printf("현재 승합차의 남은 주차자리 개수는 %d개 입니다.\n", count_2);
				parkspace2(1);
				num = Parkspace();
				if (park[1][num - 1] != 1) {
					park[1][num - 1] = 1;

				}
				else if (park[0][num - 1] == 1) {
					printf("죄송합니다. 그 자리에는 이미 주차되어있습니다.\n");
					printf("---------------------\n");
					continue;
				}
				else {
					printf("번호를 잘못입력하셨습니다.\n");
					printf("---------------------\n");
					continue;
				}
				printf("---------------------\n");
				printf("승합차의 %d번 섹션은 직진후 우회전 하시면 됩니다.\n",num);
				count_2--;
				

				printf("---------------------\n\n");
			}
			else if (car == 3) {
				printf("현재 트럭의 남은 주차자리 개수는 %d개 입니다.\n", count_3);
				parkspace2(2);
				num = Parkspace();
				if (park[2][num - 1] != 1) {
					park[2][num - 1] = 1;

				}
				else if (park[0][num - 1] == 1) {
					printf("죄송합니다. 그 자리에는 이미 주차되어있습니다.\n");
					printf("---------------------\n");
					continue;
				}
				else {
					printf("번호를 잘못입력하셨습니다.\n");
					printf("---------------------\n");
					continue;
				}
				printf("---------------------\n");
				printf("트럭의 %d번 섹션은 2층으로 올라가시면 됩니다.\n",num);
				count_3--;
				

				printf("---------------------\n\n");
			}
			else {
				printf("---------------------\n");
				printf("\n번호를 잘못입력하셨습니다.\n\n");
				printf("---------------------\n\n");
			}

		}
		else if (chose == 2) {
			CarTypes();
			scanf_s("%d", &car);
			switch (car) {
			case 1:
				calcurater(0);
				count_1++;
				printf("경차의 남은 주차자리 개수는 %d개 입니다.\n", count_1);
				printf("---------------------\n\n");
				break;
			case 2:
				calcurater(1);
				count_2++;
				printf("승합차의 남은 주차자리 개수는 %d개 입니다.\n", count_2);
				printf("---------------------\n\n");

				break;
			case 3:
				calcurater(2);
				count_3++;
				printf("트럭의 남은 주차자리 개수는 %d개 입니다.\n", count_3);
				printf("---------------------\n\n");
				break;
			}

		}
		else if (chose == 99) { // 프로그램을 종료하는 번호 코드
			printf("프로그램을 종료합니다...");
			break;
		}
		else {
			printf("---------------------\n");
			printf("\n번호를 잘못입력하셨습니다.\n\n");
			printf("---------------------\n\n");
		}
		if (count_1 <= 0) { // 11/29일에 추가 만약 자동차 별 주차자리가 없을 때 출력
			printf("---------------------\n");
			printf("\n경차는 주차자리가 없습니다. 죄송합니다.\n\n");
			printf("---------------------\n\n");
			count_1++;
			continue;
		}
		if (count_2 <= 0) {
			printf("---------------------\n");
			printf("\n승합차는 주차자리가 없습니다. 죄송합니다.\n\n");
			printf("---------------------\n\n");
			count_2++;
			continue;
		}
		if (count_3 <= 0) {
			printf("---------------------\n");
			printf("\n트럭는 주차자리가 없습니다. 죄송합니다.\n\n");
			printf("---------------------\n\n");
			count_3++;
			

			continue;
		}
		
	}

	return 0;
}

