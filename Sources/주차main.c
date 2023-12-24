#include <stdio.h>
#include <stdlib.h>
#include "parking.h"



// 12/13일 전기차 추가

// 자동차 종류를 나타내는 구조체 정의


int main() {
	int car; // 자동차의 종류
	int num; // 주차자리 번호
	int count_1 = 10; // 경차자리의 남은 주차자리
	int count_2 = 5; // 승합차의 남은 주차자리
	int count_3 = 3; // 트럭의 남은 주차자리
	int count_4 = 3; // 전기차의 남은 주차자리
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

				if (count_1 <= 0) { // 11/29일에 추가 만약 자동차 별 주차자리가 없을 때 출력
					printf("---------------------\n");
					printf("\n현재 경차는 주차자리가 없습니다. 죄송합니다.\n\n");
					printf("---------------------\n\n");
					continue;
				}

				printf("현재 경차의 남은 주차자리 개수는 %d개 입니다.\n", count_1);
				parkspace2(0);
				num = Parkspace();

				if (num >= 1 && num <= 10) {

					if (park[0][num - 1] == 0) {
						park[0][num - 1] = 1;
						printf("---------------------\n");
						printf("경차의 %d번 섹션은 직진후 왼쪽으로 가시면 됩니다.\n", num);
						count_1--;
						printf("---------------------\n\n");
					}
					else if (park[0][num - 1] == 1) {
						printf("죄송합니다. 그 자리에는 이미 주차되어있습니다.\n");
						printf("---------------------\n");
						continue;
					}
				}

				else {
					printf("번호를 잘못입력하셨습니다.\n");
					printf("---------------------\n");
					continue;
				}

			}

			else if (car == 2) {

				if (count_2 <= 0) {
					printf("---------------------\n");
					printf("\n현재 승합차는 주차자리가 없습니다. 죄송합니다.\n\n");
					printf("---------------------\n\n");
					continue;
				}

				printf("현재 승합차의 남은 주차자리 개수는 %d개 입니다.\n", count_2);
				parkspace2(1);
				num = Parkspace();

				if (num >= 1 && num <= 5) {

					if (park[1][num - 1] == 0) {
						park[1][num - 1] = 1;
						printf("---------------------\n");
						printf("승합차의 %d번 섹션은 직진후 우회전 하시면 됩니다.\n", num);
						count_2--;
						printf("---------------------\n\n");
					}
					else if (park[1][num - 1] == 1) {
						printf("죄송합니다. 그 자리에는 이미 주차되어있습니다.\n");
						printf("---------------------\n");
						continue;
					}
				}

				else {
					printf("번호를 잘못입력하셨습니다.\n");
					printf("---------------------\n");
					continue;
				}

			}

			else if (car == 3) {

				if (count_3 <= 0) {
					printf("---------------------\n");
					printf("\n현재 트럭는 주차자리가 없습니다. 죄송합니다.\n\n");
					printf("---------------------\n\n");
					continue;
				}

				printf("현재 트럭의 남은 주차자리 개수는 %d개 입니다.\n", count_3);
				parkspace2(2);
				num = Parkspace();

				if (num >= 1 && num <= 3) {

					if (park[2][num - 1] == 0) {
						park[2][num - 1] = 1;
						printf("---------------------\n");
						printf("트럭의 %d번 섹션은 2층으로 올라가 오른쪽으로 가시면 됩니다.\n", num);
						count_3--;
						printf("---------------------\n\n");
					}

					else if (park[2][num - 1] == 1) {
						printf("죄송합니다. 그 자리에는 이미 주차되어있습니다.\n");
						printf("---------------------\n");
						continue;
					}
				}

				else {
					printf("번호를 잘못입력하셨습니다.\n");
					printf("---------------------\n");
					continue;
				}

			}
			else if (car == 4) {
				int charge;
				if (count_4 <= 0) {
					printf("---------------------\n");
					printf("\n현재 전기차는 주차자리가 없습니다. 죄송합니다.\n\n");
					printf("---------------------\n\n");
					continue;
				}
				printf("현재 전기차의 남은 주차자리 개수는 %d개 입니다.\n", count_4);
				parkspace2(3);
				num = Parkspace();

				if (num >= 1 && num <= 3) { // 전기차는 충전요금이 따로 마련되어있음 전기차는 따로 충전을 해줘야하기때문에 3자리를 따로마련
					// 전기차 충전 요금은 25000원					
					printf("---------------------\n");
					printf("충전요금은 50kw 25000원 입니다.\n");
					printf("---------------------\n");
					printf("전기차 충전을 원하시면 1 필요없으시면 2를 입력해주세요.");
					scanf_s("%d", &charge);
					if (charge == 1) {
						calcurater(3);
						printf("\n");
					}
					else {

					}
					if (park[3][num - 1] == 0) {
						park[3][num - 1] = 1;
						printf("---------------------\n");
						printf("전기차의 %d번 섹션은 2층으로 올라가 왼쪽으로 가시면 됩니다.\n", num);
						count_4--;
						printf("---------------------\n\n");
					}

					else if (park[3][num - 1] == 1) {
						printf("죄송합니다. 그 자리에는 이미 주차되어있습니다.\n");
						printf("---------------------\n");
						continue;
					}
				}

				else {
					printf("번호를 잘못입력하셨습니다.\n");
					printf("---------------------\n");
					continue;
				}


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
			printf("몇번섹션에 주차를 하셨나요? "); // 섹션의 여부
			scanf_s("%d", &num);

			if (park[car - 1][num - 1] == 1) {
				park[car - 1][num - 1] = 0;

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
				case 4:
					calcurater(2);
					count_4++;
					printf("전기차의 남은 주차자리 개수는 %d개 입니다.\n", count_4);
					printf("---------------------\n\n");
					break;
				}
			}

			else {
				printf("---------------------\n");
				printf("\n번호를 잘못입력하셨습니다.\n\n");
				printf("---------------------\n\n");
				continue;
			}

		}
		else if (chose == 99) { // 프로그램을 종료하는 번호 코드
			printf("=======================\n");
			printf("프로그램 관리자 명령어\n");
			printf("=======================\n");

			printf("프로그램을 종료합니다...");
			break;
		}

		else {
			printf("---------------------\n");
			printf("\n번호를 잘못입력하셨습니다.\n\n");
			printf("---------------------\n\n");
		}


	}

	return 0;
}