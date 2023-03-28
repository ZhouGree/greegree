#include "LinkStack.h"

//��ʼ��ջ
Status initLStack(LinkStack* s) {
	(*s).top = (LSNode*)malloc(sizeof(LSNode));
	if ((*s).top == NULL) {
		printf("�����ڴ�ʧ�ܣ�δ��ɳ�ʼ����\n");
		return ERROR;
	}
	(*s).counnt = 0;
	(*s).top->data = 0;
	(*s).top->next = NULL;
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack* s) {
	if ((*s).top == NULL ) {
		return SUCCESS;
	}
	else
	{
		return ERROR;
	}
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack* s, ElemType* e) {
	//���ж��Ƿ�Ϊ��ջ
	if ((*s).top == NULL) {
		printf("��ջ��\n");
		return ERROR;
	}
	//��ֵ
	*e = (*s).top->data;
	return SUCCESS;
}

//���ջ
Status clearLStack(LinkStack* s) {
	if ((*s).top == NULL) {
		printf("��ջ��\n");
		return ERROR;
	}
	while ((*s).top->next != NULL) {
		LSNode* f = (*s).top;
		(*s).top = (*s).top->next;
		free(f);
	}
	free((*s).top);
	(*s).top = NULL;
	return SUCCESS;
}

//����ջ
Status destroyLStack(LinkStack* s) {
	if (isEmptyLStack(s)) {
		return ERROR;
	}
	LStack p = (*s).top;
	while ((*s).top->next!=NULL)
	{
		//ջ��������
		(*s).top = (*s).top->next;
		//����
		free(p);
		//��pȷ����һ��free�Ľ��
		p = (*s).top;
	}
	p = (*s).top;
	free(p);
	//ջ����ΪNULL
	(*s).top = NULL;
	//�ص�δ��ʼ��������
	(*s).counnt = -1;
	return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack* s, int* length) {
	if ((*s).top == NULL) {
		printf("��ջ��\n");
		*length = 0;
		return ERROR;
	}
	else
	{
		int count = 1;
		LSNode* p = (*s).top;
		while (p->next != NULL)
		{
			p = p->next;
			count++;
		}
		*length = count;
	}

}

//��ջ
Status pushLStack(LinkStack* s, ElemType data) {
	if (s == NULL) {
		printf("��ջʧ�ܣ�\n");
		return ERROR;
	}
	if ((*s).top->data == 0) {
		(*s).top->data = data;
		printf("��ջ�ɹ���\n");
		return SUCCESS;
	}
	//�ȷ����ڴ�
	LSNode* t = (LSNode*)malloc(sizeof(LSNode));
	if (t == NULL) {
		return ERROR;
	}
	t->data = data;
	t->next = (*s).top;
	//ջ��ָ������ջ�Ľڵ�
	(*s).top = t;
	(*s).counnt += 1;
	printf("��ջ�ɹ���\n");
	return SUCCESS;
}

//��ջ
Status popLStack(LinkStack* s, ElemType* data) {
	
	if ((*s).top == NULL) {
		return ERROR;
	}
	LSNode* t = (*s).top;
	//ջ������
	(*s).top = (*s).top->next;
	//ɾ��
	free(t);
	return SUCCESS;
}


