#include "LQueue.h"

void InitLQueue(LQueue* Q){
	
	(*Q).front = (*Q).rear = (Node*)malloc(sizeof(Node));
	if ((*Q).front == NULL)
	{
		printf("�����ڴ�ʧ�ܣ�\n");
		printf("��ʼ��ʧ�ܣ�\n");
		return;
	}
	//��ʼֵΪ0
	//(*Q).front->data = malloc(1);
	(*Q).front->data = 0;
	(*Q).rear->next = NULL;
	printf("�����ѳ�ʼ����\n");
}

void DestoryLQueue(LQueue* Q) {
	
	if ((*Q).front == NULL) {
		printf("�ǿն��У�\n");
		return;
	}
	//pȷ�����ٵĽ��
	Node* p = (*Q).front;
	for (int i = 0; i < (*Q).length && (*Q).front->next != NULL; i++) {
		(*Q).front = (*Q).front->next;
		free(p);
		p = (*Q).front;
	}
	p = (*Q).front;
	free(p);
	//����ͷ����β����Ϊ��ָ��
	(*Q).front = NULL;
	(*Q).front = NULL;
	(*Q).length = 0;
	printf("����������ɣ�\n");
}

Status IsEmptyLQueue(const LQueue* Q){
	if ((*Q).front == NULL) {
		printf("����Ϊ�գ�\n");
		return FALSE;
	}
	printf("���в�Ϊ�գ�\n");
	return FALSE;
}

Status GetHeadLQueue(LQueue* Q, void* e) {
	if ((*Q).front == NULL) {
		printf("����Ϊ�գ�\n");
		return FALSE;
	}
	if ((*Q).front->data == 0) {
		printf("�����ݣ�\n");
		return FALSE;
	}
	else
	{
		//��ֵ
		e = (*Q).front->data;
		return TRUE;
	}
}

int LengthLQueue(LQueue* Q) {
	if ((*Q).front == NULL) {
		printf("����Ϊ�գ�\n");
		return FALSE;
	}
	
	int length = 1;
	//p��������
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
			printf("�����ڴ�ʧ�ܣ�\n");
			return FALSE;
		}
		(*Q).front->data = data;
		return TRUE;
	}
	
	if ((*Q).front->data == 0) {
		(*Q).front->data = data;
		return TRUE;
	}
	//�ȿ���һ���µĶ�̬�洢�ռ�
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL) {
		printf("�����ڴ�ʧ�ܣ�\n");
		return FALSE;
	}
	//��ֵ
	p->data = data;
	//ʹp�����������
	assert(Q);
	(*Q).rear->next = p;
	p->next = NULL;
	//ָ���β��ָ���Ƶ�pָ��Ľڵ�
	(*Q).rear = p;
	return TRUE;
}

Status DeLQueue(LQueue* Q) {
	if ((*Q).front == NULL) {
		printf("�ö���Ϊ�գ��޷����г��Ӳ�����\n");
		return FALSE;
	}
	//����pָ��Ľڵ㣬����ʹpָ����ͷ
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
		printf("���б�Ϊ�գ�\n");
		return;
	}
	//����pָ��Ľڵ�
	Node* p = (*Q).front;
	while ((*Q).front->next != NULL) {
		(*Q).front = (*Q).front->next;
		free(p);
		//p������һ��ɾ���Ľڵ�
		p = (*Q).front;
	}
	(*Q).front = (*Q).rear = NULL;
	printf("����ն��У�\n");
}

Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q)) {
	if ((*Q).front == NULL) {
		printf("�ö���Ϊ�գ�\n");
		return FALSE;
	}

	//p�Ӷ�ͷ��ʼ����
	Node* p = (*Q).front;
	(*foo)(p->data);
	
	while (p->next!=NULL)
	{
		//���
		//LPrint(p->data);
		p = p->next;
		assert(p);
		(*foo)(p->data);
	}
	
	return TRUE;
}

void LPrint(void* q) {
	char TYPE[20];
	printf("1������(Int)\n2���ַ���(Char)\n3��������(Double)\n");
	printf("ѡ��������������ͣ�");
	scanf_s("%s", TYPE, 20);
	q = getData(q, TYPE);
	if (strcmp(TYPE, "����") == 0 || strcmp(TYPE, "Int") == 0 || strcmp(TYPE, "1") == 0) {
		int len = strlen((char*)q), num = 0;
		for (int i = 0; i < len && (*((char*)q + i) != '.'); i++) {
			num = *((char*)q + i) - 48 + num * 10;
		}
		printf("%d\n", num);
	}
	else if(strcmp(TYPE, "�ַ���") == 0 || strcmp(TYPE, "Char") == 0 || strcmp(TYPE, "2") == 0)
	{
		printf("%s\n", (char*)q);
		
	}
	else if(strcmp(TYPE, "������") == 0 || strcmp(TYPE, "Double") == 0 || strcmp(TYPE, "3") == 0)
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
		printf("���벻��ȷ��\n");
	}
}
