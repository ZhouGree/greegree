#include "Homework1.h"

typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode,* LinkedList;

typedef enum Status {
	error,
	SUCCESS,
} Status;

typedef struct DuLNode
{
	ElemType data;
	struct DuLNode* prior, * next;
}DuLNode, * DuLinkedList;


int judge_int(void);

Status InitList(LinkedList* L) 
{
	int num = 0;
	LinkedList list;
	LinkedList p1, p2;
	//分配动态存储空间
	list = (LinkedList)malloc(sizeof(LNode));
	p1 = p2 = (LinkedList)malloc(sizeof(LNode));
	
	//判断内存分配是否成功
	if (list == NULL)
	{
		printf("分配内存失败\n");
		return error;
	}
	//list->next = NULL;
	list->next = p1;
	//作为头节点
	*L = list;
	printf("请输入数据：\n");
	assert(p1);
	num = judge_int();
	p1->data = num;
	
	while (p1->data != 0)
	{
		p2 = p1;
		p1 = (LinkedList)malloc(sizeof(LNode));
		p2->next = p1;
		printf("请输入数据：\n");
		assert(p1);
		num = judge_int();
		p1->data = num;
		
		//printf("%d\n", (*L)->data);
	}
	p2->next = NULL;

	return SUCCESS;
}

void DestroyList(LinkedList* L)
{
	LinkedList temp;
	//遍历链表，逐个销毁
	while (*L != NULL)
	{
		temp = *L;
		*L = (*L)->next;
		free(temp);
	}
}

Status InsertList(LNode* p, ElemType e)
{
	assert(p);
	if (p == NULL && p->next == NULL)
	{
		printf("链表为空，无法插入\n");
		return error;
	}
	LinkedList current = p;
	LinkedList newNode = (LinkedList)malloc(sizeof(LNode));
	
	if (newNode == NULL)
	{
		printf("分配空间失败！\n");
		return error;
	}
	else
	{
		assert(newNode);
		newNode->data = e;
		if (current->next == NULL)
		{
			current->next = newNode;
			newNode->next = NULL;
		}
		
		else
		{
			/*newNode->next = current->next;
			current->next = newNode;
			前面会断开,行不通*/
			//使current移到最后结点
			assert(current);
			newNode->next = current->next;
			current->next = newNode;
		}
		//free(newNode);
		return SUCCESS;
	}
	
 }

Status DeleteList(LNode* p, ElemType e)
{
	assert(p);
	if (p == NULL && p->next == NULL)
	{
		printf("链表为空，无法删除\n");
		return error;
	}
	else
	{
		LinkedList posNodeFront = p;
		LinkedList posNode = p->next;
		while (posNode->next != NULL)
		{
			//指针移到表尾也找不到数据
			if (posNode->data == e)
			{
				//删除posNode
				//posNodeFront->next->data = posNode->next->data;
				posNodeFront->next = posNode->next;
				free(posNode);
				//posNode = NULL;
				//free(posNodeFront);

				return SUCCESS;
			}

			//posNodeFront为posNode上一个结点
			posNodeFront = posNode;
			posNode = posNode->next;

		}
		printf("没有该数据，删除失败！\n");
		return error;
		
	}
}

void TraverseList (LinkedList L)
{
	assert(L);
	if (L == NULL && L->next == NULL)
	{
		printf("链表为空，无法插入！\n");
		return;
	}

	LinkedList temp = L->next;
	//printf("%d\n", L->next->data);
	while (temp != NULL)
	{
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

Status SearchList (LinkedList L, ElemType e)
{
	assert(L);
	if (L == NULL && L->next == NULL)
		return error;
	LinkedList SNode = (LinkedList)malloc(sizeof(LNode));
	SNode = L;
	while (SNode->next != NULL)
	{
		if (SNode->data == e)
		{
			printf("查找成功，存在该数据！\n");
			return SUCCESS;
		}
		SNode = SNode->next;
	}
	
	return error;
}

Status ReverseList(LinkedList* L)
{
	assert((*L));
	if ((*L) == NULL && (*L)->next == NULL)
		return error;
	//p2遍历链表，p3与p2一致，用p3插入转置，则p2就是用来确定p3下一次的位置，p1是p3转置后的新位置
	LinkedList p1 = (*L)->next, p2 = (*L)->next, p3 = (*L)->next;
	if (p2 == NULL)
	{
		printf("链表为空，转置失败！\n");
		return error;
	}
	p2 = p2->next->next;
	p3 = p3->next;
	p1->next = NULL;
	while (p2 != NULL&&p3 != NULL)
	{
		//p2 = p2->next;
		
		(*L)->next = p3;
		p3->next = p1;
		p1 = p3;
		//p2移到下一个结点，p3跟着移动
		//if (p2->next != NULL)
			//p2 = p2->next;
		
		p3 = p2;
		p2 = p2->next;
	}
	(*L)->next = p3;
	p3->next = p1;
	return SUCCESS;
}

LNode* FiindMidNode(LinkedList L)
{
	assert(L);
	if (L == NULL && L->next == NULL)
	{
		printf("链表为空! \n");
		return NULL;
	}
	LinkedList slow = L, fast = L;
	while (fast->next->next != NULL && fast != NULL)
	{
		//当快指针移到表尾时慢指针正好在中间位置
		fast = fast->next->next;
		slow = slow->next;
	}
	assert(slow);
	slow = slow->next;
	return slow;
}

Status IsLoopList(LinkedList L)
{
	assert(L);
	if (L == NULL && L->next == NULL)
	{
		printf("链表为空，无法删除\n");
		return error;
	}
	LinkedList fast = L, slow = L;
	while (fast->next != NULL && slow->next != NULL)
	{
		slow = slow->next;
		if ((fast = fast->next->next) == NULL)
		{
			return error;
		}
		//如果两指针相遇，则为环
		if (fast == slow)
			return SUCCESS;
	}
	return error;
}



Status InitList_DuL(DuLinkedList* L)
{
	int num = 0;
	DuLinkedList DuList;
	DuLinkedList DuLp1, DuLp2;
	//分配动态存储空间
	DuList = (DuLinkedList)malloc(sizeof(DuLNode));
	DuLp1 = DuLp2 = (DuLinkedList)malloc(sizeof(DuLNode));

	//判断内存分配是否成功
	if (DuList == NULL)
	{
		printf("分配内存失败\n");
		return error;
	}
	DuList->prior = NULL;
	DuList->next = DuLp1;
	assert(DuLp1);
	DuLp1->prior = DuList;
	//作为头节点
	*L = DuList;
	printf("请输入数据：\n");
	assert(DuLp1);
	num = judge_int();
	DuLp1->data = num;

	while (DuLp1->data != 0)
	{
		DuLp2 = DuLp1;
		DuLp1 = (DuLinkedList)malloc(sizeof(DuLNode));
		DuLp2->next = DuLp1;
		assert(DuLp1);
		DuLp1->prior = DuLp2;
		printf("请输入数据：\n");
		assert(DuLp1);
		num = judge_int();
		DuLp1->data = num;

		//printf("%d\n", (*L)->data);
	}
	DuLp2->next = NULL;

	return SUCCESS;
}

void DestroyList_DuL(DuLinkedList* L)
{
	DuLinkedList temp;
	//遍历链表，逐个销毁
	while (*L != NULL)
	{
		temp = *L;
		*L = (*L)->next;
		//释放内存
		free(temp);
	}
}

Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q)
{
	assert(p);
	if (p == NULL)
	{
		printf("链表为空，无法插入！\n");
		return error;
	}
	else
	{
		DuLinkedList DuLcurrent = p;
		//当DuLcurrent是头结点，q插在头节点后面
		if (DuLcurrent->prior == NULL)
		{
			q->next = DuLcurrent->next;
			q->prior = DuLcurrent;
			DuLcurrent->next = q;
		}
		else
		{
			//DuLcurrent的上一个节点的next指向q
			DuLcurrent->prior->next = q;
			//q的prior指向DuLcurrent的上一个结点
			q->prior = DuLcurrent->prior;
			//DuLcurrent的prior指向q
			DuLcurrent->prior = q;
			//q的next指向DuLcurrent
			q->next = DuLcurrent;
			return SUCCESS;
		}
	}
}

Status InsertAfterList_DuL(DuLNode* p, DuLNode* q)
{
	
	assert(p);
	if (p == NULL)
	{
		printf("链表为空，无法插入！\n");
		return error;
	}
	
	else
	{
		DuLinkedList DuLcurrent = p;
		if (DuLcurrent->next == NULL)
		{
			DuLcurrent->next = q;
			q->next = NULL;
		}

		else
		{
			
			
			assert(p);
			//DuLcurrent下一个结点的prior指向q
			DuLcurrent->next->prior = q;
			//q的next指向DuLcurrent的下一个结点
			q->next = DuLcurrent->next;
			//DuLcurrent的next指向q
			DuLcurrent->next = q;
			//q的prior指向DuLcurrent
			q->prior = DuLcurrent;
		}
		
		return SUCCESS;
	}
	
}

Status DeleteList_DuL(DuLNode* p, ElemType e)
{
	
	assert(p);
	if (p == NULL && p->next == NULL)
	{
		printf("链表为空，无法删除\n");
		return error;
	}
	else
	{
		
		DuLinkedList posDuLNodeFront = p;
		DuLinkedList posDuLNode = p->next;
		while (posDuLNode->next != NULL)
		{
			//指针移到表尾也找不到数据
			if (posDuLNode->data == e)
			{
				//删除posDuLNode
				posDuLNodeFront->next = posDuLNode->next;
				posDuLNode->next->prior = posDuLNodeFront;
				free(posDuLNode);
				
				return SUCCESS;
			}

			//posNodeFront为posNode上一个结点
			posDuLNodeFront = posDuLNode;
			posDuLNode = posDuLNode->next;

		}
		printf("没有该数据，删除失败！\n");
		return error;

	}
	
}

void TraverseList_DuL(DuLinkedList L)
{
	//出错处理
	assert(L);
	if (L == NULL && L->next == NULL)
		return;
	DuLinkedList temp = L->next;

	while (temp != NULL)
	{
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

Status SearchList_DuL(DuLinkedList L, ElemType e)
{
	//出错处理
	assert(L);
	if (L == NULL && L->next == NULL)
		return error;
	DuLinkedList DuLSNode = (DuLinkedList)malloc(sizeof(DuLNode));
	DuLSNode = L;
	while (DuLSNode->next != NULL)
	{
		if (DuLSNode->data == e)
		{
			printf("查找成功，存在该数据！\n");
			return SUCCESS;
		}
		DuLSNode = DuLSNode->next;
	}

	return error;
}

DuLNode* FiindMidNode_DuL(DuLinkedList L)
{
	//出错处理
	assert(L);
	if (L == NULL && L->next == NULL)
	{
		printf("链表为空!\n");
		return NULL;
	}
	DuLinkedList DuLslow = L, DuLfast = L;
	while (DuLfast->next->next != NULL && DuLfast != NULL)
	{
		//当快指针移到表尾时慢指针正好在中间位置
		DuLfast = DuLfast->next->next;
		DuLslow = DuLslow->next;
	}
	assert(DuLslow);
	DuLslow = DuLslow->next;
	return DuLslow;
}

Status IsLoopList_DuL(DuLinkedList L)
{
	assert(L);
	if (L == NULL && L->next == NULL)
	{
		printf("链表为空!\n");
		return error;
	}
	DuLinkedList fast = L, slow = L;
	while (fast->next != NULL && slow->next != NULL)
	{
		//快指针走两步，慢指针走一步
		slow = slow->next;
		if ((fast = fast->next->next) == NULL)
		{
			return error;
		}
		//如果两指针相遇，则为环
		if (fast == slow)
			return SUCCESS;
	}
	return error;
}

void show(void)
{
	printf("\n\n\n\n单链表ADT\n\n");
	printf("\t1、创建空链表\n");
	printf("\t2、销毁链表\n");
	printf("\t3、插入结点\n");
	printf("\t4、删除结点\n");
	printf("\t5、遍历链表\n");
	printf("\t6、查找数据\n");
	printf("\t7、反转链表\n");
	printf("\t8、判断链表是否成环\n");
	printf("\t9、寻找中间结点\n");
	printf("\t10、退出\n");
	printf("\n请输入对应数字：");
}

void show_DuL(void)
{
	printf("\n\n\n\n双链表ADT\n\n");
	printf("\t1、创建空链表\n");
	printf("\t2、销毁链表\n");
	printf("\t3、向前插入结点\n");
	printf("\t4、向后插入结点\n");
	printf("\t5、删除结点\n");
	printf("\t6、遍历链表\n");
	printf("\t7、查找数据\n");
	printf("\t8、判断链表是否成环\n");
	printf("\t9、寻找中间结点\n");
	printf("\t10、退出\n");
	printf("\n请输入对应数字：");
}

void show_00(void)
{
	printf("\n\n\n\nMenu\n\n");
	printf("\t1、单链表ADT\n");
	printf("\t2、双链表ADT\n");
	printf("\t3、退出\n");
	printf("\n请输入对应数字：");
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

int main(void) 
{
	int choice, num = 0;
	
	LinkedList head = NULL;
	DuLinkedList DuLhead = NULL;
	DuLinkedList q = (DuLinkedList)malloc(sizeof(DuLNode));
	//printf("%d\n", num);
	
	do
	{
		show_00();
		choice = judge_int();
		system("cls");
		switch (choice)
		{
		case 1:
		{
			do
			{
				show();
				choice = judge_int();
				system("cls");
				switch (choice)
				{
				case 1:
				{
					if (InitList(&head))
					{
						printf("链表创建成功！\n");
					}
					else
					{
						printf("链表创建失败！\n");
					}
					break;
				}
				case 2:
				{
					DestroyList(&head);
					printf("链表销毁完成！\n");
					break;
				}
				case 3:
				{
					if (head == NULL)
					{
						printf("链表为空，请先创建链表！\n");
					}
					else
					{
						printf("请输入要插入数据：");
						scanf_s("%d", &num);
						if (InsertList(head, num))
						{
							printf("数据插入成功！\n");
						}
						else
						{
							printf("插入失败！\n");
						}
					}
					break;
				}
				case 4:
				{
					if (head == NULL)
					{
						printf("链表为空，请先创建链表！\n");
					}
					else
					{
						printf("请输入您想删除的数据：");
						scanf_s("%d", &num);

						if (DeleteList(head, num))
						{
							printf("数据删除成功！\n");
						}
						else
						{
							printf("删除失败！\n");
						}
					}
					break;
				}
				case 5:
				{
					if (head == NULL || head->next == NULL)
					{
						printf("链表为空，请先创建链表！\n");
					}
					else
					{
						TraverseList(head);
					}
					break;
				}
				case 6:
				{
					if (head == NULL)
					{
						printf("链表为空，请先创建链表！\n");
					}
					else
					{
						printf("请输入您要查找的数据：\n");
						scanf_s("%d", &num);
						if (SearchList(head, num))
						{
							printf("查找成功！\n");
						}
						else
						{
							printf("该数据不存在");
						}
					}
					break;
				}
				case 7:
				{
					if (head == NULL || head->next == NULL)
					{
						printf("链表为空，反转失败！\n");
					}
					else
					{
						if (ReverseList(&head))
							printf("反转成功！\n");
						else
							printf("反转失败！\n");
					}
					break;
				}
				case 8:
				{

					if (head == NULL || head->next == NULL)
					{
						printf("链表为空！\n");
					}
					else
					{
						if (IsLoopList(head))
							printf("链表成环！\n");
						else
							printf("链表不成环！\n");
					}
					break;
				}
				case 9:
				{

					if (head == NULL || head->next == NULL)
					{
						printf("链表为空！\n");
					}
					else
					{
						printf("链表中间值为：%d\n", (FiindMidNode(head))->data);
					}
					break;
				}
				case 10:
				{
					DestroyList(&head);
					break;
				}
				default:
				{
					printf("请重新输入数字！（1-10）\n");
					break;
				}
				}
			} while (choice != 10);
			break;
		}
		case 2:
		{
			do
			{
				show_DuL();
				choice = judge_int();
				system("cls");
				switch (choice)
				{
				case 1:
				{
					if (InitList_DuL(&DuLhead))
					{
						printf("链表创建成功！\n");
					}
					else
					{
						printf("链表创建失败！\n");
					}
					break;
				}
				case 2:
				{
					DestroyList_DuL(&DuLhead);
					printf("链表销毁完成！\n");
					break;
				}
				case 3:
				{
					if (DuLhead == NULL)
					{
						printf("链表为空，请先创建链表！\n");
					}
					else
					{
						printf("请输入要插入数据：");
						scanf_s("%d", &num);
						q->data = num;
						if (InsertBeforeList_DuL(DuLhead, q))
						{
							printf("数据插入成功！\n");
						}
						else
						{
							printf("插入失败！\n");
						}
					}
					break;
				}
				case 4:
				{
					if (DuLhead == NULL)
					{
						printf("链表为空，请先创建链表！\n");
					}
					else
					{
						printf("请输入要插入数据：");
						scanf_s("%d", &num);
						q->data = num;
						if (InsertAfterList_DuL(DuLhead, q))
						{
							printf("数据插入成功！\n");
						}
						else
						{
							printf("插入失败！\n");
						}
					}
					break;
				}
				case 5:
				{
					if (DuLhead == NULL)
					{
						printf("链表为空，请先创建链表！\n");
					}
					else
					{
						printf("请输入您想删除的数据：");
						scanf_s("%d", &num);
						//assert(Num);
						//*Num = num;
						if (DeleteList_DuL(DuLhead, num))
						{
							printf("数据删除成功！\n");
						}
						else
						{
							printf("删除失败！\n");
						}
					}
					break;
				}
				case 6:
				{
					if (DuLhead == NULL || DuLhead->next == NULL)
					{
						printf("遍历链表成功！\n");
					}
					else
					{
						TraverseList_DuL(DuLhead);
					}
					break;
				}
				case 7:
				{
					if (DuLhead == NULL)
					{
						printf("链表为空，请先创建链表！\n");
					}
					else
					{
						printf("请输入您要查找的数据：\n");
						scanf_s("%d", &num);
						if (SearchList_DuL(DuLhead, num))
						{

						}
						else
						{
							printf("该数据不存在");
						}
					}
					break;
				}
				case 8:
				{

					if (DuLhead == NULL || DuLhead->next == NULL)
					{
						printf("链表为空！\n");
					}
					else
					{
						if (IsLoopList_DuL(DuLhead))
							printf("链表成环！\n");
						else
							printf("链表不成环！\n");
					}
					break;
				}
				case 9:
				{

					if (DuLhead == NULL || DuLhead->next == NULL)
					{
						printf("链表为空！\n");
					}
					else
					{
						printf("链表中间值为：%d\n", (FiindMidNode_DuL(DuLhead))->data);
					}
					break;
				}
				case 10:
				{
					DestroyList_DuL(&DuLhead);
					break;
				}
				default:
				{
					printf("请重新输入数字！（1-10）\n");
					break;
				}
				}
			} while (choice != 10);
			break;
		}
		case 3:
		{
			break;
		}
		default:
		{
			printf("请重新输入数字！（1-3）\n");
			break;
		}
		}
	}while (choice != 3);
	
	return 0;
	
}


