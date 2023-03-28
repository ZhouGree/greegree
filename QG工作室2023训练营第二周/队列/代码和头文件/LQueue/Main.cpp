#include "LQueue.h"

void show() {
	printf("\n\n\n     <<<Menu队列操作>>>\n");
	printf("\t1.初始化队列\n");
	printf("\t2.销毁队列\n");
	printf("\t3.判断队列是否为空\n");
	printf("\t4.获取队头元素\n");
	printf("\t5.确定队列长度\n");
	printf("\t6.入队操作\n");
	printf("\t7.出队操作\n");
	printf("\t8.清空队列\n");
	printf("\t9.遍历队列\n");
	//printf("\t10.操作队列\n");
	printf("\t10.退出\n");
	printf("    请输入对应操作：");
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
			//出错处理，接受数字
			if (word[m] < '0' || word[m]>'9')
			{
				printf("请输入整数：");
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
	//把字符换成整型
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

	if (strcmp(TYPE, "整型") == 0 || strcmp(TYPE, "Int") == 0 || strcmp(TYPE, "1") == 0) {
		if (data == NULL) {
			data = (int*)malloc(4);
		}
		data = (int*)data;

	}
	else if (strcmp(TYPE, "字符型") == 0 || strcmp(TYPE, "Char") == 0 || strcmp(TYPE, "2") == 0)
	{
		if (data == NULL) {
			data = (char*)malloc(20);
		}
		data = (char*)data;
	}
	else if (strcmp(TYPE, "浮点型") == 0 || strcmp(TYPE, "Double") == 0 || strcmp(TYPE, "3") == 0)
	{
		if (data == NULL) {
			data = (double*)malloc(8);
		}
		data = (double*)data;
	}
	else
	{
		printf("类型输入不正确！\n");
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
				printf("该队列长度为：%d\n", num);
			}

			break;
		}
		case 6:
		{
			printf("请输入数据：");
			data = malloc(sizeof(20));
			scanf_s("%s", (char*)data,20);
			if (EnLQueue(Q, data)) {
				printf("入队操作已完成！\n");
			}
			break;
		}
		case 7:
		{
			if (DeLQueue(Q)) {
				printf("出队操作已完成！\n");
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
			printf("请重新输入数字！（1-10）\n");
			break;
		}
		}
	} while (choice != 10);
}