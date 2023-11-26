#include <stdio.h>
#include <stdlib.h>

void CarTypes() { // 자동차 종류를 고르는 함수
	printf("----------------\n");
	printf("자동차 종류를 골라주세요:\n");
	printf("1. 경차\n");
	printf("2. 승합차\n");
	printf("3. 트럭\n");
	printf("----------------\n\n");
}
int main() {
	int car; // 자동차의 종류
	int coin[] = { 2000, 3000, 4000 };
	int count_1 = 10; // 경차자리의 남은 주차자리
	int count_2 = 5; // 승합차의 남은 주차자리
	int count_3 = 3; // 트럭의 남은 주차자리
	int chose = 0; // 주차하는건지 안하는건지 선택
	while (count_1 != 0 && count_2 != 0 && count_3 != 0) {
		
		printf("주차를 하시는건가요 나가시는건가요? (하시면 1 나가시면 2)\n");
		
		scanf_s("%d", &chose);
		if (chose == 1) {
			
				CarTypes();
				scanf_s("%d", &car); // 자동차 종류를 받아옴
				if (car == 1) { // if문으로 자동차별 주차요금과 남은 주차자리 갯수를 알려줌
					printf("----------------\n");
					
					printf("경차는 직진후 왼쪽으로 가시면 됩니다.\n", coin[0]);
					count_1--;
					printf("경차의 남은 주차자리 개수는 %d개 입니다.\n", count_1);
					
					printf("----------------\n\n");
				}
				else if (car == 2) {
					printf("----------------\n");
					printf("승합차는 직진후 우회전 하시면 됩니다.\n", coin[1]);
					count_2--;
					printf("승합차의 남은 주차자리 개수는 %d개 입니다.\n", count_2);
					
					printf("----------------\n\n");
				}
				else if (car == 3) {
					printf("----------------\n");
					printf("트럭은 2층으로 올라가시면 됩니다.\n", coin[2]);
					count_3--;
					printf("트럭의 남은 주차자리 개수는 %d개 입니다.\n", count_3);
					
					printf("----------------\n\n");
				}
				else {
					printf("번호를 잘못입력하셨습니다.");
				}

			}
		else if (chose == 2) {
			CarTypes();
			scanf_s("%d", &car);
			switch (car) {
			case 1:
				printf("----------------\n");
				printf("경차의 요금은 %d입니다.\n", coin[0]);
				count_1++;
				printf("경차의 남은 주차자리 개수는 %d개 입니다.\n", count_1);
				printf("----------------\n\n");
				break;
			case 2:
				printf("----------------\n");
				printf("승합차의 요금은 %d입니다.\n", coin[1]);
				count_2++;
				printf("승합차의 남은 주차자리 개수는 %d개 입니다.\n", count_2);
				printf("----------------\n\n");

				break;
			case 3:
				printf("----------------\n");
				printf("트럭의 요금은 %d입니다.\n", coin[2]);
				count_3++;
				printf("트럭의 남은 주차자리 개수는 %d개 입니다.\n", count_3);
				printf("----------------\n\n");
				break;
			}

		}
		else if (chose == 3) {
			printf("프로그램을 종료합니다...");
			break;
		}
		}
	printf("주차자리가 없습니다. 죄송합니다.");
			}
			
		
	

