#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>


typedef  int QUDataType;

typedef struct QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;

typedef struct Queue
{
	QueueNode* _front;//��ͷ
	QueueNode* _tail;//��β
}Queue;


void QueueInit(Queue* pq);

void QueueDestory(Queue* pq);

QueueNode* BuyQueueNode(QUDataType x);

void QueuePush(Queue* pq, QUDataType x);
void QueuePop(Queue* pq);

QUDataType QueueFront(Queue* pq);
QUDataType QueueBack(Queue* pq);

int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);

void QueuePrint(Queue* pq);

void TestQueue();
