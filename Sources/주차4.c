#include <stdio.h>
#include <stdlib.h>
int coin[] = { 2000, 3000, 4000 };

void CarTypes() { // �ڵ��� ������ ���� �Լ�
	printf("---------------------\n");
	printf("�ڵ��� ������ ����ּ���:\n");
	printf("1. ����\n");
	printf("2. ������\n");
	printf("3. Ʈ��\n");
	printf("---------------------\n\n");
}

int calcurater(int a) { // �Ž����� �Լ� 11/27�� �߰�
	int money;
	printf("---------------------\n");
	printf("���ǵ��� %d�Դϴ�. �󸶸� ���ǰǰ���?\n", coin[a]);
	scanf_s("%d", &money);
	if (money > coin[a]) {
		printf("�Ž������� %d�Դϴ�. �����մϴ�.\n", money - coin[a]);
	}
	
}
int main() {
	int car; // �ڵ����� ����

	int count_1 = 10; // �����ڸ��� ���� �����ڸ�
	int count_2 = 5; // �������� ���� �����ڸ�
	int count_3 = 3; // Ʈ���� ���� �����ڸ�
	int chose = 0; // �����ϴ°��� ���ϴ°��� ����
	while (1) {
		if (count_1 <= 0 && count_2 <= 0 && count_3 <= 0) {
			printf("�����ڸ��� �����ϴ�. �˼��մϴ�.\n");
			break;
		}
		printf("������ �Ͻô°ǰ��� �����ô°ǰ���? (�Ͻø� 1 �����ø� 2)\n");

		scanf_s("%d", &chose);
		
		if (chose == 1) {

			CarTypes();
			scanf_s("%d", &car); // �ڵ��� ������ �޾ƿ�
			if (car == 1) { // if������ �ڵ����� ������ݰ� ���� �����ڸ� ������ �˷���
				printf("---------------------\n");

				printf("������ ������ �������� ���ø� �˴ϴ�.\n", coin[0]);
				count_1--;
				printf("������ ���� �����ڸ� ������ %d�� �Դϴ�.\n", count_1);

				printf("---------------------\n\n");
			}
			else if (car == 2) {
				printf("---------------------\n");
				printf("�������� ������ ��ȸ�� �Ͻø� �˴ϴ�.\n", coin[1]);
				count_2--;
				printf("�������� ���� �����ڸ� ������ %d�� �Դϴ�.\n", count_2);

				printf("---------------------\n\n");
			}
			else if (car == 3) {
				printf("---------------------\n");
				printf("Ʈ���� 2������ �ö󰡽ø� �˴ϴ�.\n", coin[2]);
				count_3--;
				printf("Ʈ���� ���� �����ڸ� ������ %d�� �Դϴ�.\n", count_3);

				printf("---------------------\n\n");
			}
			else {
				printf("---------------------\n");
				printf("\n��ȣ�� �߸��Է��ϼ̽��ϴ�.\n\n");
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
				printf("������ ���� �����ڸ� ������ %d�� �Դϴ�.\n", count_1);
				printf("---------------------\n\n");
				break;
			case 2:
				calcurater(1);
				count_2++;
				printf("�������� ���� �����ڸ� ������ %d�� �Դϴ�.\n", count_2);
				printf("---------------------\n\n");

				break;
			case 3:
				calcurater(2);
				count_3++;
				printf("Ʈ���� ���� �����ڸ� ������ %d�� �Դϴ�.\n", count_3);
				printf("---------------------\n\n");
				break;
			}

		}
		else if (chose == 99) {
			printf("���α׷��� �����մϴ�...");
			break;
		}
		else {
			printf("---------------------\n");
			printf("\n��ȣ�� �߸��Է��ϼ̽��ϴ�.\n\n");
			printf("---------------------\n\n");
		}
	
		
	}

	return 0;
}

