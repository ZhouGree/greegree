#include "LQueue.h"

void show() {
	printf("\n\n\n     <<<Menu���в���>>>\n");
	printf("\t1.��ʼ������\n");
	printf("\t2.���ٶ���\n");
	printf("\t3.�ж϶����Ƿ�Ϊ��\n");
	printf("\t4.��ȡ��ͷԪ��\n");
	printf("\t5.ȷ�����г���\n");
	printf("\t6.��Ӳ���\n");
	printf("\t7.���Ӳ���\n");
	printf("\t8.��ն���\n");
	printf("\t9.��������\n");
	//printf("\t10.��������\n");
	printf("\t10.�˳�\n");
	printf("    �������Ӧ������");
}

int judge_int(void)
{
	int len, num = 0, arg = 1;
	char word[10] = "\0";
	int m, j = 1, k = 0;
	while (j)
	{
		scanf_s("\t\t\t\t\t%s", word, 10);
		len = strlen(word);
		for (m = 0; m < len; m++)
		{
			//��������������
			if (word[m] < '0' || word[m]>'9')
			{
				printf("������������");
				break;
			}
			else
			{
				if (m == len - 1)
					j = 0;
			}
		}
	}
	j = len - 1;
	//���ַ���������
	for (m = 0; m < len; m++)
	{
		for (int i = 0; i <= j; i++)
			arg *= 10;
		num += (word[m] - '0') * arg;
		arg = 1;
		j--;
	}
	num = num / 10;
	return num;
}

void* getData(void* data, char TYPE[]) {

	if (strcmp(TYPE, "����") == 0 || strcmp(TYPE, "Int") == 0 || strcmp(TYPE, "1") == 0) {
		if (data == NULL) {
			data = (int*)malloc(4);
		}
		data = (int*)data;

	}
	else if (strcmp(TYPE, "�ַ���") == 0 || strcmp(TYPE, "Char") == 0 || strcmp(TYPE, "2") == 0)
	{
		if (data == NULL) {
			data = (char*)malloc(20);
		}
		data = (char*)data;
	}
	else if (strcmp(TYPE, "������") == 0 || strcmp(TYPE, "Double") == 0 || strcmp(TYPE, "3") == 0)
	{
		if (data == NULL) {
			data = (double*)malloc(8);
		}
		data = (double*)data;
	}
	else
	{
		printf("�������벻��ȷ��\n");
	}
	return data;
}

int main() {
	int choice, num = 0;
	LQueue* Q = (LQueue*)malloc(sizeof(LQueue));
	assert(Q);
	(*Q).front = NULL;
	void* data = NULL;
	void (*foo)(void* q);
	
	do
	{
		show();
		choice = judge_int();
		system("cls");
		switch (choice)
		{
		case 1:
		{
			InitLQueue(Q);
			break;
		}
		case 2:
		{
			DestoryLQueue(Q);
			break;
		}
		case 3:
		{
			IsEmptyLQueue(Q);
			break;
		}
		case 4:
		{
			
			if (GetHeadLQueue(Q, data)) {
				LPrint(data);
			}
			break;
		}
		case 5:
		{
			if (LengthLQueue(Q)) {
				num = LengthLQueue(Q);
				printf("�ö��г���Ϊ��%d\n", num);
			}

			break;
		}
		case 6:
		{
			printf("���������ݣ�");
			data = malloc(sizeof(20));
			scanf_s("%s", (char*)data,20);
			if (EnLQueue(Q, data)) {
				printf("��Ӳ�������ɣ�\n");
			}
			break;
		}
		case 7:
		{
			if (DeLQueue(Q)) {
				printf("���Ӳ�������ɣ�\n");
			}
			break;
		}
		case 8:
		{
			ClearLQueue(Q);
			break;
		}
		case 9:
		{
			foo = &LPrint;
			TraverseLQueue(Q, foo);
			break;
		}
		case 10:
		{
			DestoryLQueue(Q);
			system("cls");
			break;
		}
		default:
		{
			printf("�������������֣���1-10��\n");
			break;
		}
		}
	} while (choice != 10);
}