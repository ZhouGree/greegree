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
	//���䶯̬�洢�ռ�
	list = (LinkedList)malloc(sizeof(LNode));
	p1 = p2 = (LinkedList)malloc(sizeof(LNode));
	
	//�ж��ڴ�����Ƿ�ɹ�
	if (list == NULL)
	{
		printf("�����ڴ�ʧ��\n");
		return error;
	}
	//list->next = NULL;
	list->next = p1;
	//��Ϊͷ�ڵ�
	*L = list;
	printf("���������ݣ�\n");
	assert(p1);
	num = judge_int();
	p1->data = num;
	
	while (p1->data != 0)
	{
		p2 = p1;
		p1 = (LinkedList)malloc(sizeof(LNode));
		p2->next = p1;
		printf("���������ݣ�\n");
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
	//���������������
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
		printf("����Ϊ�գ��޷�����\n");
		return error;
	}
	LinkedList current = p;
	LinkedList newNode = (LinkedList)malloc(sizeof(LNode));
	
	if (newNode == NULL)
	{
		printf("����ռ�ʧ�ܣ�\n");
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
			ǰ���Ͽ�,�в�ͨ*/
			//ʹcurrent�Ƶ������
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
		printf("����Ϊ�գ��޷�ɾ��\n");
		return error;
	}
	else
	{
		LinkedList posNodeFront = p;
		LinkedList posNode = p->next;
		while (posNode->next != NULL)
		{
			//ָ���Ƶ���βҲ�Ҳ�������
			if (posNode->data == e)
			{
				//ɾ��posNode
				//posNodeFront->next->data = posNode->next->data;
				posNodeFront->next = posNode->next;
				free(posNode);
				//posNode = NULL;
				//free(posNodeFront);

				return SUCCESS;
			}

			//posNodeFrontΪposNode��һ�����
			posNodeFront = posNode;
			posNode = posNode->next;

		}
		printf("û�и����ݣ�ɾ��ʧ�ܣ�\n");
		return error;
		
	}
}

void TraverseList (LinkedList L)
{
	assert(L);
	if (L == NULL && L->next == NULL)
	{
		printf("����Ϊ�գ��޷����룡\n");
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
			printf("���ҳɹ������ڸ����ݣ�\n");
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
	//p2��������p3��p2һ�£���p3����ת�ã���p2��������ȷ��p3��һ�ε�λ�ã�p1��p3ת�ú����λ��
	LinkedList p1 = (*L)->next, p2 = (*L)->next, p3 = (*L)->next;
	if (p2 == NULL)
	{
		printf("����Ϊ�գ�ת��ʧ�ܣ�\n");
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
		//p2�Ƶ���һ����㣬p3�����ƶ�
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
		printf("����Ϊ��! \n");
		return NULL;
	}
	LinkedList slow = L, fast = L;
	while (fast->next->next != NULL && fast != NULL)
	{
		//����ָ���Ƶ���βʱ��ָ���������м�λ��
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
		printf("����Ϊ�գ��޷�ɾ��\n");
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
		//�����ָ����������Ϊ��
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
	//���䶯̬�洢�ռ�
	DuList = (DuLinkedList)malloc(sizeof(DuLNode));
	DuLp1 = DuLp2 = (DuLinkedList)malloc(sizeof(DuLNode));

	//�ж��ڴ�����Ƿ�ɹ�
	if (DuList == NULL)
	{
		printf("�����ڴ�ʧ��\n");
		return error;
	}
	DuList->prior = NULL;
	DuList->next = DuLp1;
	assert(DuLp1);
	DuLp1->prior = DuList;
	//��Ϊͷ�ڵ�
	*L = DuList;
	printf("���������ݣ�\n");
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
		printf("���������ݣ�\n");
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
	//���������������
	while (*L != NULL)
	{
		temp = *L;
		*L = (*L)->next;
		//�ͷ��ڴ�
		free(temp);
	}
}

Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q)
{
	assert(p);
	if (p == NULL)
	{
		printf("����Ϊ�գ��޷����룡\n");
		return error;
	}
	else
	{
		DuLinkedList DuLcurrent = p;
		//��DuLcurrent��ͷ��㣬q����ͷ�ڵ����
		if (DuLcurrent->prior == NULL)
		{
			q->next = DuLcurrent->next;
			q->prior = DuLcurrent;
			DuLcurrent->next = q;
		}
		else
		{
			//DuLcurrent����һ���ڵ��nextָ��q
			DuLcurrent->prior->next = q;
			//q��priorָ��DuLcurrent����һ�����
			q->prior = DuLcurrent->prior;
			//DuLcurrent��priorָ��q
			DuLcurrent->prior = q;
			//q��nextָ��DuLcurrent
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
		printf("����Ϊ�գ��޷����룡\n");
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
			//DuLcurrent��һ������priorָ��q
			DuLcurrent->next->prior = q;
			//q��nextָ��DuLcurrent����һ�����
			q->next = DuLcurrent->next;
			//DuLcurrent��nextָ��q
			DuLcurrent->next = q;
			//q��priorָ��DuLcurrent
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
		printf("����Ϊ�գ��޷�ɾ��\n");
		return error;
	}
	else
	{
		
		DuLinkedList posDuLNodeFront = p;
		DuLinkedList posDuLNode = p->next;
		while (posDuLNode->next != NULL)
		{
			//ָ���Ƶ���βҲ�Ҳ�������
			if (posDuLNode->data == e)
			{
				//ɾ��posDuLNode
				posDuLNodeFront->next = posDuLNode->next;
				posDuLNode->next->prior = posDuLNodeFront;
				free(posDuLNode);
				
				return SUCCESS;
			}

			//posNodeFrontΪposNode��һ�����
			posDuLNodeFront = posDuLNode;
			posDuLNode = posDuLNode->next;

		}
		printf("û�и����ݣ�ɾ��ʧ�ܣ�\n");
		return error;

	}
	
}

void TraverseList_DuL(DuLinkedList L)
{
	//������
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
	//������
	assert(L);
	if (L == NULL && L->next == NULL)
		return error;
	DuLinkedList DuLSNode = (DuLinkedList)malloc(sizeof(DuLNode));
	DuLSNode = L;
	while (DuLSNode->next != NULL)
	{
		if (DuLSNode->data == e)
		{
			printf("���ҳɹ������ڸ����ݣ�\n");
			return SUCCESS;
		}
		DuLSNode = DuLSNode->next;
	}

	return error;
}

DuLNode* FiindMidNode_DuL(DuLinkedList L)
{
	//������
	assert(L);
	if (L == NULL && L->next == NULL)
	{
		printf("����Ϊ��!\n");
		return NULL;
	}
	DuLinkedList DuLslow = L, DuLfast = L;
	while (DuLfast->next->next != NULL && DuLfast != NULL)
	{
		//����ָ���Ƶ���βʱ��ָ���������м�λ��
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
		printf("����Ϊ��!\n");
		return error;
	}
	DuLinkedList fast = L, slow = L;
	while (fast->next != NULL && slow->next != NULL)
	{
		//��ָ������������ָ����һ��
		slow = slow->next;
		if ((fast = fast->next->next) == NULL)
		{
			return error;
		}
		//�����ָ����������Ϊ��
		if (fast == slow)
			return SUCCESS;
	}
	return error;
}

void show(void)
{
	printf("\n\n\n\n������ADT\n\n");
	printf("\t1������������\n");
	printf("\t2����������\n");
	printf("\t3��������\n");
	printf("\t4��ɾ�����\n");
	printf("\t5����������\n");
	printf("\t6����������\n");
	printf("\t7����ת����\n");
	printf("\t8���ж������Ƿ�ɻ�\n");
	printf("\t9��Ѱ���м���\n");
	printf("\t10���˳�\n");
	printf("\n�������Ӧ���֣�");
}

void show_DuL(void)
{
	printf("\n\n\n\n˫����ADT\n\n");
	printf("\t1������������\n");
	printf("\t2����������\n");
	printf("\t3����ǰ������\n");
	printf("\t4����������\n");
	printf("\t5��ɾ�����\n");
	printf("\t6����������\n");
	printf("\t7����������\n");
	printf("\t8���ж������Ƿ�ɻ�\n");
	printf("\t9��Ѱ���м���\n");
	printf("\t10���˳�\n");
	printf("\n�������Ӧ���֣�");
}

void show_00(void)
{
	printf("\n\n\n\nMenu\n\n");
	printf("\t1��������ADT\n");
	printf("\t2��˫����ADT\n");
	printf("\t3���˳�\n");
	printf("\n�������Ӧ���֣�");
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
						printf("�������ɹ���\n");
					}
					else
					{
						printf("������ʧ�ܣ�\n");
					}
					break;
				}
				case 2:
				{
					DestroyList(&head);
					printf("����������ɣ�\n");
					break;
				}
				case 3:
				{
					if (head == NULL)
					{
						printf("����Ϊ�գ����ȴ�������\n");
					}
					else
					{
						printf("������Ҫ�������ݣ�");
						scanf_s("%d", &num);
						if (InsertList(head, num))
						{
							printf("���ݲ���ɹ���\n");
						}
						else
						{
							printf("����ʧ�ܣ�\n");
						}
					}
					break;
				}
				case 4:
				{
					if (head == NULL)
					{
						printf("����Ϊ�գ����ȴ�������\n");
					}
					else
					{
						printf("����������ɾ�������ݣ�");
						scanf_s("%d", &num);

						if (DeleteList(head, num))
						{
							printf("����ɾ���ɹ���\n");
						}
						else
						{
							printf("ɾ��ʧ�ܣ�\n");
						}
					}
					break;
				}
				case 5:
				{
					if (head == NULL || head->next == NULL)
					{
						printf("����Ϊ�գ����ȴ�������\n");
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
						printf("����Ϊ�գ����ȴ�������\n");
					}
					else
					{
						printf("��������Ҫ���ҵ����ݣ�\n");
						scanf_s("%d", &num);
						if (SearchList(head, num))
						{
							printf("���ҳɹ���\n");
						}
						else
						{
							printf("�����ݲ�����");
						}
					}
					break;
				}
				case 7:
				{
					if (head == NULL || head->next == NULL)
					{
						printf("����Ϊ�գ���תʧ�ܣ�\n");
					}
					else
					{
						if (ReverseList(&head))
							printf("��ת�ɹ���\n");
						else
							printf("��תʧ�ܣ�\n");
					}
					break;
				}
				case 8:
				{

					if (head == NULL || head->next == NULL)
					{
						printf("����Ϊ�գ�\n");
					}
					else
					{
						if (IsLoopList(head))
							printf("����ɻ���\n");
						else
							printf("�����ɻ���\n");
					}
					break;
				}
				case 9:
				{

					if (head == NULL || head->next == NULL)
					{
						printf("����Ϊ�գ�\n");
					}
					else
					{
						printf("�����м�ֵΪ��%d\n", (FiindMidNode(head))->data);
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
					printf("�������������֣���1-10��\n");
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
						printf("�������ɹ���\n");
					}
					else
					{
						printf("������ʧ�ܣ�\n");
					}
					break;
				}
				case 2:
				{
					DestroyList_DuL(&DuLhead);
					printf("����������ɣ�\n");
					break;
				}
				case 3:
				{
					if (DuLhead == NULL)
					{
						printf("����Ϊ�գ����ȴ�������\n");
					}
					else
					{
						printf("������Ҫ�������ݣ�");
						scanf_s("%d", &num);
						q->data = num;
						if (InsertBeforeList_DuL(DuLhead, q))
						{
							printf("���ݲ���ɹ���\n");
						}
						else
						{
							printf("����ʧ�ܣ�\n");
						}
					}
					break;
				}
				case 4:
				{
					if (DuLhead == NULL)
					{
						printf("����Ϊ�գ����ȴ�������\n");
					}
					else
					{
						printf("������Ҫ�������ݣ�");
						scanf_s("%d", &num);
						q->data = num;
						if (InsertAfterList_DuL(DuLhead, q))
						{
							printf("���ݲ���ɹ���\n");
						}
						else
						{
							printf("����ʧ�ܣ�\n");
						}
					}
					break;
				}
				case 5:
				{
					if (DuLhead == NULL)
					{
						printf("����Ϊ�գ����ȴ�������\n");
					}
					else
					{
						printf("����������ɾ�������ݣ�");
						scanf_s("%d", &num);
						//assert(Num);
						//*Num = num;
						if (DeleteList_DuL(DuLhead, num))
						{
							printf("����ɾ���ɹ���\n");
						}
						else
						{
							printf("ɾ��ʧ�ܣ�\n");
						}
					}
					break;
				}
				case 6:
				{
					if (DuLhead == NULL || DuLhead->next == NULL)
					{
						printf("��������ɹ���\n");
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
						printf("����Ϊ�գ����ȴ�������\n");
					}
					else
					{
						printf("��������Ҫ���ҵ����ݣ�\n");
						scanf_s("%d", &num);
						if (SearchList_DuL(DuLhead, num))
						{

						}
						else
						{
							printf("�����ݲ�����");
						}
					}
					break;
				}
				case 8:
				{

					if (DuLhead == NULL || DuLhead->next == NULL)
					{
						printf("����Ϊ�գ�\n");
					}
					else
					{
						if (IsLoopList_DuL(DuLhead))
							printf("����ɻ���\n");
						else
							printf("�����ɻ���\n");
					}
					break;
				}
				case 9:
				{

					if (DuLhead == NULL || DuLhead->next == NULL)
					{
						printf("����Ϊ�գ�\n");
					}
					else
					{
						printf("�����м�ֵΪ��%d\n", (FiindMidNode_DuL(DuLhead))->data);
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
					printf("�������������֣���1-10��\n");
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
			printf("�������������֣���1-3��\n");
			break;
		}
		}
	}while (choice != 3);
	
	return 0;
	
}


