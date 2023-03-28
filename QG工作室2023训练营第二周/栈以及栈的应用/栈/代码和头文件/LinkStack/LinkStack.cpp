#include "LinkStack.h"

//初始化栈
Status initLStack(LinkStack* s) {
	(*s).top = (LSNode*)malloc(sizeof(LSNode));
	if ((*s).top == NULL) {
		printf("分配内存失败，未完成初始化！\n");
		return ERROR;
	}
	(*s).counnt = 0;
	(*s).top->data = 0;
	(*s).top->next = NULL;
	return SUCCESS;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack* s) {
	if ((*s).top == NULL ) {
		return SUCCESS;
	}
	else
	{
		return ERROR;
	}
}

//得到栈顶元素
Status getTopLStack(LinkStack* s, ElemType* e) {
	//先判断是否为空栈
	if ((*s).top == NULL) {
		printf("空栈！\n");
		return ERROR;
	}
	//赋值
	*e = (*s).top->data;
	return SUCCESS;
}

//清空栈
Status clearLStack(LinkStack* s) {
	if ((*s).top == NULL) {
		printf("空栈！\n");
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

//销毁栈
Status destroyLStack(LinkStack* s) {
	if (isEmptyLStack(s)) {
		return ERROR;
	}
	LStack p = (*s).top;
	while ((*s).top->next!=NULL)
	{
		//栈顶往下移
		(*s).top = (*s).top->next;
		//销毁
		free(p);
		//用p确定下一次free的结点
		p = (*s).top;
	}
	p = (*s).top;
	free(p);
	//栈顶置为NULL
	(*s).top = NULL;
	//回到未初始化的样子
	(*s).counnt = -1;
	return SUCCESS;
}

//检测栈长度
Status LStackLength(LinkStack* s, int* length) {
	if ((*s).top == NULL) {
		printf("空栈！\n");
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

//入栈
Status pushLStack(LinkStack* s, ElemType data) {
	if (s == NULL) {
		printf("入栈失败！\n");
		return ERROR;
	}
	if ((*s).top->data == 0) {
		(*s).top->data = data;
		printf("入栈成功！\n");
		return SUCCESS;
	}
	//先分配内存
	LSNode* t = (LSNode*)malloc(sizeof(LSNode));
	if (t == NULL) {
		return ERROR;
	}
	t->data = data;
	t->next = (*s).top;
	//栈顶指向新入栈的节点
	(*s).top = t;
	(*s).counnt += 1;
	printf("入栈成功！\n");
	return SUCCESS;
}

//出栈
Status popLStack(LinkStack* s, ElemType* data) {
	
	if ((*s).top == NULL) {
		return ERROR;
	}
	LSNode* t = (*s).top;
	//栈顶下移
	(*s).top = (*s).top->next;
	//删除
	free(t);
	return SUCCESS;
}


