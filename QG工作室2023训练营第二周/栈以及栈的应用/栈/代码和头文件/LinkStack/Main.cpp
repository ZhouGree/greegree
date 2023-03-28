#include "LinkStack.h"


void show() {
	printf("\n\n\nMenu<链栈基本操作>\n");
	printf("\t1.初始化链栈\n");
	printf("\t2.判断链栈是否为空\n");
	printf("\t3.得到栈顶元素\n");
	printf("\t4.清空栈\n");
	printf("\t5.销毁栈\n");
	printf("\t6.检测栈长度\n");
	printf("\t7.入栈\n");
	printf("\t8.出栈\n");
	printf("\t9.退出\n");
	printf("请输入想要进行的操作相应的数字：");
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
				printf("栈初始化成功！\n");
			}
			break;
		}
		case 2:
		{
			if (isEmptyLStack(s)) {
				printf("是空栈！\n");
			}
			else
			{
				printf("不是空栈！\n");
			}
			break;
		}
		case 3:
		{
			if (getTopLStack(s, e)) {
				printf("得到的栈顶元素为：");
				assert(e);
				printf("%d\n", *e);
			}
			break;
		}
		case 4:
		{
			if (clearLStack(s)) {
				printf("栈已清空！\n");
			}
			break;
		}
		case 5:
		{
			if (destroyLStack(s)) {
				printf("栈已销毁！\n");
			}
			else
			{
				printf("是空栈！\n");
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
			printf("请输入数据：\n");
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
				printf("出栈成功！\n");
			}
			else
			{
				printf("是空栈，无法出栈！\n");
			}
			printf("已清空队列！\n");
			break;
		}
		case 9:
		{
			destroyLStack(s);
			break;
		}
		default:
		{
			printf("请重新输入数字！（1-10）\n");
			break;
		}
		}
	} while (choice != 9);
}