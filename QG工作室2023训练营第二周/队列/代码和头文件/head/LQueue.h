#pragma once
#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
//#include <windows.h>

//��ʽ���нṹ
typedef struct node
{
    void* data;                   //������ָ��
    struct node* next;            //ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
    Node* front;                   //��ͷ
    Node* rear;                    //��β
    size_t length;                 //���г���
} LQueue;

typedef enum
{
    FALSE = 0, TRUE = 1,
} Status;

extern char type;

typedef struct Data {
    void* data;
    char TYPE[20];
}Data;

void* getData(void *q ,char TYPE[]);
//��������
void InitLQueue(LQueue* Q);//��ʼ������
void DestoryLQueue(LQueue* Q);//���ٶ���
Status IsEmptyLQueue(const LQueue* Q);//�ж϶����Ƿ�Ϊ��
Status GetHeadLQueue(LQueue* Q, void* e);//��ȡ��ͷԪ��
int LengthLQueue(LQueue* Q);//ȷ�����г���
Status EnLQueue(LQueue* Q, void* data);//��Ӳ���
Status DeLQueue(LQueue* Q);//���Ӳ���
void ClearLQueue(LQueue* Q);//��ն���
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q));//��������
void LPrint(void* q);//��������


#endif 
