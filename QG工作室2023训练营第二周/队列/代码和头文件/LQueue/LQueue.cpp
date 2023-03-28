#include "LQueue.h"

void InitLQueue(LQueue* Q){
	
	(*Q).front = (*Q).rear = (Node*)malloc(sizeof(Node));
	if ((*Q).front == NULL)
	{
		printf("分配内存失败！\n");
		printf("初始化失败！\n");
		return;
	}
	//初始值为0
	//(*Q).front->data = malloc(1);
	(*Q).front->data = 0;
	(*Q).rear->next = NULL;
	printf("队列已初始化！\n");
}

void DestoryLQueue(LQueue* Q) {
	
	if ((*Q).front == NULL) {
		printf("是空队列！\n");
		return;
	}
	//p确定销毁的结点
	Node* p = (*Q).front;
	for (int i = 0; i < (*Q).length && (*Q).front->next != NULL; i++) {
		(*Q).front = (*Q).front->next;
		free(p);
		p = (*Q).front;
	}
	p = (*Q).front;
	free(p);
	//将列头、列尾都置为空指针
	(*Q).front = NULL;
	(*Q).front = NULL;
	(*Q).length = 0;
	printf("队列销毁完成！\n");
}

Status IsEmptyLQueue(const LQueue* Q){
	if ((*Q).front == NULL) {
		printf("队列为空！\n");
		return FALSE;
	}
	printf("队列不为空！\n");
	return FALSE;
}

Status GetHeadLQueue(LQueue* Q, void* e) {
	if ((*Q).front == NULL) {
		printf("队列为空！\n");
		return FALSE;
	}
	if ((*Q).front->data == 0) {
		printf("无数据！\n");
		return FALSE;
	}
	else
	{
		//赋值
		e = (*Q).front->data;
		return TRUE;
	}
}

int LengthLQueue(LQueue* Q) {
	if ((*Q).front == NULL) {
		printf("队列为空！\n");
		return FALSE;
	}
	
	int length = 1;
	//p遍历队列
	Node* p = (*Q).front;
	while (p->next != NULL) {
		length++;
		p = p->next;
	}
	(*Q).length = length;
	return length;
}

Status EnLQueue(LQueue* Q, void* data) {
	if ((*Q).front == NULL) {
		(*Q).front= (Node*)malloc(sizeof(Node));
		if ((*Q).front == NULL) {
			printf("分配内存失败！\n");
			return FALSE;
		}
		(*Q).front->data = data;
		return TRUE;
	}
	
	if ((*Q).front->data == 0) {
		(*Q).front->data = data;
		return TRUE;
	}
	//先开辟一个新的动态存储空间
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL) {
		printf("分配内存失败！\n");
		return FALSE;
	}
	//赋值
	p->data = data;
	//使p连接入队列中
	assert(Q);
	(*Q).rear->next = p;
	p->next = NULL;
	//指向队尾的指针移到p指向的节点
	(*Q).rear = p;
	return TRUE;
}

Status DeLQueue(LQueue* Q) {
	if ((*Q).front == NULL) {
		printf("该队列为空，无法进行出队操作！\n");
		return FALSE;
	}
	//销毁p指向的节点，所以使p指向列头
	Node* p = (*Q).front;
	if (p->next == NULL)
		(*Q).front = NULL;
	else 
		(*Q).front = (*Q).front->next;
	
	free(p);
	return TRUE;
}

void ClearLQueue(LQueue* Q) {
	if ((*Q).front == NULL) {
		printf("该列表为空！\n");
		return;
	}
	//销毁p指向的节点
	Node* p = (*Q).front;
	while ((*Q).front->next != NULL) {
		(*Q).front = (*Q).front->next;
		free(p);
		//p移向下一个删除的节点
		p = (*Q).front;
	}
	(*Q).front = (*Q).rear = NULL;
	printf("已清空队列！\n");
}

Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q)) {
	if ((*Q).front == NULL) {
		printf("该队列为空！\n");
		return FALSE;
	}

	//p从队头开始遍历
	Node* p = (*Q).front;
	(*foo)(p->data);
	
	while (p->next!=NULL)
	{
		//输出
		//LPrint(p->data);
		p = p->next;
		assert(p);
		(*foo)(p->data);
	}
	
	return TRUE;
}

void LPrint(void* q) {
	char TYPE[20];
	printf("1、整型(Int)\n2、字符型(Char)\n3、浮点型(Double)\n");
	printf("选择输出的数据类型：");
	scanf_s("%s", TYPE, 20);
	q = getData(q, TYPE);
	if (strcmp(TYPE, "整型") == 0 || strcmp(TYPE, "Int") == 0 || strcmp(TYPE, "1") == 0) {
		int len = strlen((char*)q), num = 0;
		for (int i = 0; i < len && (*((char*)q + i) != '.'); i++) {
			num = *((char*)q + i) - 48 + num * 10;
		}
		printf("%d\n", num);
	}
	else if(strcmp(TYPE, "字符型") == 0 || strcmp(TYPE, "Char") == 0 || strcmp(TYPE, "2") == 0)
	{
		printf("%s\n", (char*)q);
		
	}
	else if(strcmp(TYPE, "浮点型") == 0 || strcmp(TYPE, "Double") == 0 || strcmp(TYPE, "3") == 0)
	{
		int len = strlen((char*)q), i = 0;
		double num = 0;
		
		for (i = 0; i < len && (*((char*)q+i) != '.'); i++) {
			num = *((char*)q + i) - 48 + num * 10;
		}
		i = i + 1;
		for (int j=i-1; i < len; i++) {
			num = num + (*((char*)q + i) - 48) * pow(10, j - i);
		}
		
		printf("%lf\n", num);
	}
	else
	{
		printf("输入不正确！\n");
	}
}
