#include <stdio.h>
#include "parking.h"
int coin[] = { 2000, 3000, 4000 ,25000 };
int park[4][10] = { {0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,1,1,1,1,1 },{0,0,0,1,1,1,1,1,1,1},{0,0,0,1,1,1,1,1,1,1} };
// 0�� ���� ����� 1�� �����Ǿ��ִ� �ڸ� �������� Ʈ���� ���� 5�ڸ� 3�ڸ��̱� ������ �������� 1�� ǥ��
// �ڵ��� ������ ���� ������ ���� �迭
CarTypeInfo carTypes[] = {
	{1, "����"},
	{2, "������"},
	{3, "Ʈ��"},
	{4, "������"}
};
void CarTypes() { // �ڵ��� ������ ���� �Լ�
	printf("---------------------\n");
	printf("�ڵ��� ������ ����ּ���:\n");

	// �ڵ��� ���� ���
	for (int i = 0; i < sizeof(carTypes) / sizeof(carTypes[0]); ++i) {
		printf("%d. %s\n", carTypes[i].type, carTypes[i].description);
	}

	printf("---------------------\n");
}

int calcurater(int a) { // �Ž����� �Լ� 11/27�� �߰� 12/3 ����
	int money;

	while (1) {
		printf("---------------------\n");
		printf("���ǵ��� %d�Դϴ�. �󸶸� ���ǰǰ���?\n", coin[a]);
		scanf_s("%d", &money);

		if (money == coin[a]) {
			printf("�����մϴ�. ");
			break;
		}

		else if (money > coin[a]) {
			printf("�Ž������� %d�Դϴ�. �����մϴ�.\n", money - coin[a]);
			break;
		}

		else if (money < coin[a]) {
			printf("���� �����մϴ�.\n");
			continue;
		}
	}
}

int Parkspace() { // 11/30�� ���� �Լ�
	int num;

	printf("---------------------\n");
	printf("������ǿ� �����Ͻó���? ");
	scanf_s("%d", &num); // �����ڸ� ��ȣ
	printf("---------------------\n");
	return num;
}
int parkspace2(int a) { // 12/2�� �����ڸ� ǥ���ϴ� �Լ�
	printf("�������� ��ȣ�� ");

	for (int i = 0; i < 10; i++) {

		if (park[a][i] != 1) {
			printf("%d�� ", i + 1);
		}
	}
	printf("�Դϴ�.\n");
}
