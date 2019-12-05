#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

void SListInit(SList* plt)//初始化
{
	assert(plt);
	SListNode* head = BuySListNode(-1);
	head->_next = head;
	head->_next = head;

	plt->_head = head;
}

void SListDestory(SList* plt)
{
	assert(plt);
	SListNode* cur = plt->_head->_next;
	SListNode* head = plt->_head;
	SListNode* next = NULL;
	while (cur != head)
	{
		next = cur->_next;
		free(cur);
		cur = next;
	}
	free(plt->_head);
	plt->_head = NULL;
}

SListNode* BuySListNode(SLTDataType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_next = NULL;
	newnode->_prev = NULL;
	newnode->_data = x;

	return newnode;
}

void SListPushFront(SList* plt, SLTDataType x)//头插
{
	assert(plt);
	SListNode* head = plt->_head;
	SListNode* next = head->_next;
	SListNode* newnode = BuySListNode(x);

	head->_next = newnode;
	newnode->_prev = head;

	newnode->_next = next;
	next->_prev = newnode;
}

void SListPopfront(SList* plt)//头删
{
	assert(plt  &&  plt->_head->_next);
	SListNode* head = plt->_head;
	SListNode* cur = plt->_head->_next;
	SListNode* next = cur->_next;

	head->_next = next;
	next->_prev = head;

	free(cur);

}

void SListPushBack(SList* plt, SLTDataType x)//尾插
{
	assert(plt  &&  plt->_head->_next);
	SListNode* head = plt->_head;
	SListNode* tail = head->_prev;

	SListNode* newnode = BuySListNode(x);
	tail->_next = newnode;
	newnode->_prev = tail;
	
	newnode->_next = head;
	head->_prev = newnode;
}

void SListPopBack(SList*plt)//尾删
{
	assert(plt&&  plt->_head->_next);
	SListNode* head = plt->_head;
	SListNode* tail = head->_prev;
	SListNode* prev = tail->_prev;

	free(tail);
	prev->_next = head;
	head->_prev = prev;
}

SListNode* SListFind(SList* plt, SLTDataType x)
{
	assert(plt);
	SListNode* head = plt->_head;
	SListNode* cur = head->_next;
	while (cur != head)
	{
		if (cur->_data==x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}

//在pos前插入
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode* prev = pos->_prev;
	SListNode* newnode = BuySListNode(x);
	prev->_next = newnode;
	newnode->_prev = prev;

	newnode->_next = pos;
	pos->_prev = newnode;
}

void SListNodeErase(SList*plt, SListNode* pos)
{
	assert(plt);
	SListNode* prev = pos->_prev;
	SListNode* next = pos->_next;
	free(pos);

	prev->_next = next;
	next->_prev = prev;
}

void  SListNodeRemove(SList*plt, SLTDataType x)
{
	SListNode* pos = SListFind(plt, x);
	if (pos)
	{
		SListNodeErase(plt, pos);
	}
}

void SListPrint(SList* plt)
{
	assert(plt);
	SListNode* cur = plt->_head->_next;
	SListNode* head = plt->_head;
	printf("<=head=>");
	while (cur !=head)
	{
		printf("<=%d=>", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

void TestSList()
{
	SList lt;
	SListInit(&lt);

	SListPushFront(&lt, 5);
	SListPushFront(&lt, 4);
	SListPushFront(&lt, 3);
	SListPushFront(&lt, 2);
	SListPushFront(&lt, 1);

	SListPrint(&lt);

	//SListPopfront(&lt);
	//SListPrint(&lt);

	//SListPopBack(&lt);
	//SListPrint(&lt);

	//SListPushBack(&lt,8);
	//SListPrint(&lt);

	SListFind(&lt, 3);


	SListNode* pos = NULL;
	pos = SListFind(&lt, 3);

	SListInsertAfter(pos, 7);
	SListPrint(&lt);

	SListNodeErase(&lt, pos);
	SListPrint(&lt);

	SListNodeRemove(&lt, 4);
	SListPrint(&lt);
}

