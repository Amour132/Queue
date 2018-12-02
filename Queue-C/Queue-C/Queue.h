#pragma once

#include <stdio.h>
#include <assert.h>
#include <malloc.h>
typedef int QDateType;
typedef struct QueueNode
{
	QDateType date;
	struct QueueNode *next;
}QueueNode;
typedef struct Queue
{
	QueueNode *head; //��ͷ
	QueueNode *tail; //��β
}Queue;
void QueueInit(Queue *pq); //���еĳ�ʼ��
void QueueDestory(Queue *pq); //���е�����
void QueuePush(Queue *pq, QDateType x); //��β������
void QueuePop(Queue *pq); //��ͷ������
QDateType QueueFront(Queue *pq); //��ͷ����
QDateType QueueBack(Queue *pq); //��β����
size_t QueueSize(Queue *pq); //���д�С
int QueueEmpty(Queue *pq); //�����Ƿ�Ϊ��
QueueNode *BuyQueueNode(QDateType x); //����һ���µĽڵ�
void TestQueue();
