#define _CRT_SECURE_NO_WARNINGS 1

#include"queue.h"


void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_tail = pq->_front = NULL;
}

void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	pq->_front = NULL;
}

QueueNode* BuyQueueNode(QUDataType x)
{
	    QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
		newnode->_data = x;
		newnode->_next = NULL;

		return newnode;
}

void QueuePop(Queue* pq)//队头删除数据
{
	assert(pq);
	QueueNode* del = NULL;
	if (pq->_front == NULL)
	{
		return;
	}
	if (pq->_front == pq->_tail)
	{
		pq->_tail = NULL;
	}
	del = pq->_front;
	pq->_front = pq->_front->_next;
	free(del);
}

void QueuePush(Queue* pq, QUDataType x)//队尾插入数据
{
    assert(pq);
	if (pq->_front == NULL)
	{
		pq->_front = pq->_tail = BuyQueueNode(x);
		return;
	}
	pq->_tail->_next = BuyQueueNode(x);
	
	pq->_tail = pq->_tail->_next;
}

void QueuePrint(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_front;
	while (cur != NULL)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

QUDataType QueueFront(Queue* pq)
{
	assert(pq);
	return pq->_front->_data;

}

QUDataType QueueBack(Queue* pq)
{
	assert(pq);
	return pq->_tail->_data;
}

int QueueEmpty(Queue* pq)
{
	if (pq->_front != NULL)
	{
		return 1;
	}
	return 0;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_front;
	int size = 0;
	while (cur)
	{
		size++;
		cur = cur->_next;
	}
	return size;
}

void TestQueue()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	QueuePrint(&q);


	//QueuePop(&q);
	//QueuePrint(&q);

	//QueueFront(&q);

	//QueueBack(&q);
	//

	//int b=QueueSize(&q);
	//printf("%d ", b);


	int a=QueueEmpty(&q);
	printf("%d ", a);

	
}