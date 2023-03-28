#include "LinkStack.h"


void show() {
	printf("\n\n\nMenu<��ջ��������>\n");
	printf("\t1.��ʼ����ջ\n");
	printf("\t2.�ж���ջ�Ƿ�Ϊ��\n");
	printf("\t3.�õ�ջ��Ԫ��\n");
	printf("\t4.���ջ\n");
	printf("\t5.����ջ\n");
	printf("\t6.���ջ����\n");
	printf("\t7.��ջ\n");
	printf("\t8.��ջ\n");
	printf("\t9.�˳�\n");
	printf("��������Ҫ���еĲ�����Ӧ�����֣�");
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

int main() {
	int choice, num = 0, * length = (int*)malloc(4);
	LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
	ElemType* e = (ElemType*)malloc(4);

	do
	{
		show();
		choice = judge_int();
		system("cls");
		switch (choice)
		{
		case 1:
		{
			if (initLStack(s)) {
				printf("ջ��ʼ���ɹ���\n");
			}
			break;
		}
		case 2:
		{
			if (isEmptyLStack(s)) {
				printf("�ǿ�ջ��\n");
			}
			else
			{
				printf("���ǿ�ջ��\n");
			}
			break;
		}
		case 3:
		{
			if (getTopLStack(s, e)) {
				printf("�õ���ջ��Ԫ��Ϊ��");
				assert(e);
				printf("%d\n", *e);
			}
			break;
		}
		case 4:
		{
			if (clearLStack(s)) {
				printf("ջ����գ�\n");
			}
			break;
		}
		case 5:
		{
			if (destroyLStack(s)) {
				printf("ջ�����٣�\n");
			}
			else
			{
				printf("�ǿ�ջ��\n");
			}
			break;
		}
		case 6:
		{
			if (LStackLength(s,length)) {
				assert(length);
				printf("%d\n", *length);
			}
			break;
		}
		case 7:
		{
			printf("���������ݣ�\n");
			assert(e);
			assert(e);
			*e = judge_int();
			assert(e);
			if (pushLStack(s, *e)) {

			}
			break;
		}
		case 8:
		{
			
			if (popLStack(s, e)) {
				printf("��ջ�ɹ���\n");
			}
			else
			{
				printf("�ǿ�ջ���޷���ջ��\n");
			}
			printf("����ն��У�\n");
			break;
		}
		case 9:
		{
			destroyLStack(s);
			break;
		}
		default:
		{
			printf("�������������֣���1-10��\n");
			break;
		}
		}
	} while (choice != 9);
}