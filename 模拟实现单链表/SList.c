 #define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"

void SListInit(SList* plt)
{
	assert(plt);
	plt->_head = NULL;
}


//void SListNode* BuySList(SLTDataType x)
//{
//	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
//	newnode->_data = x;
//	newnode->_next = NULL;
//}

void SListPushFront(SList* plt, SLTDataType x)//ͷ��
{
	assert(plt);
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;

	newnode ->_next = plt->_head;
	plt->_head = newnode;

}

void SListPopfront(SList* plt)//ͷɾ
{
	assert(plt);
	if (plt->_head == NULL)
	{
		return;
	}
	else
	{
		SListNode* cur = plt->_head;
		plt->_head = cur->_next;
		free(cur);
		cur = NULL;
	}
}

void SListPushBack(SList* plt, SLTDataType x)//β��
{
	assert(plt);
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;

	//1.��
	//2.�ǿ�

	if (plt->_head == NULL)
	{
		plt->_head = newnode;
	}
	else
	{
		SListNode* cur = plt->_head;
		//��β
		while (cur->_next != NULL)
		{
			cur = cur->_next;
		}
		cur->_next=newnode;
	}
}

void SListPopBack(SList*plt)//βɾ
{
	assert(plt);
	SListNode* cur = plt->_head;
	if (cur == NULL)
	{
		return;
	}
	else if (cur->_next==NULL)
	{
		free(cur);
		plt->_head = NULL;
	}
	else
	{
		while (cur->_next->_next != NULL)
		{
			cur = cur->_next;
		}
		free(cur->_next);
		cur->_next = NULL;
	}

}

SListNode* SListFind(SList* plt, SLTDataType x)//����x
{ 
	assert(plt);
	SListNode* cur = plt->_head;
	while (cur!=NULL)
	{
		if (cur->_data == x)
		{
			//printf("�ҵ���\n");
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;

}

void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode* cur = pos->_next;
	SListNode*  newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;

	
	newnode->_next = cur;
    pos->_next=newnode;

}

void SListNodeRemove(SList*plt, SLTDataType x)
{
	assert(plt);
	SListNode* prev=NULL;
	SListNode* cur = plt->_head;
	while (cur != NULL)
	{
		if (cur->_data==x)
		  {
			if (prev == NULL)
			{
				plt->_head = cur->_next;//1,2(ɾ��1ʱ��preventΪ��)
			}
			else
			{
				prev->_next = cur->_next;
			}
			free(cur);
			cur = NULL;
			return;
		  }
		else
		 {
			prev = cur;
			cur = cur->_next;
		 }
	}
}

//void SListEraseAfter(SListNode* pos)
//{
//	if (pos->_next == NULL)
//	{
//		return NULL;
//	}
//	else
//	{
//		SListNode* next = pos->_next;
//		pos->_next = next->_next;
//		free(next);
//		next = NULL;
//	}
//}

void SListPrint(SList* plt)
{
	assert(plt);
	SListNode* cur = plt->_head;
	while (cur != NULL)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}



void TestSList()
{
	SList lt;
	SListInit(&lt);
	SListPushFront(&lt, 3);
	SListPushFront(&lt, 2);
	SListPushFront(&lt, 1);
	SListPushFront(&lt, 0);
	SListPrint(&lt);

	//SListPopfront(&lt, 3);
	//SListPrint(&lt);

	//SListPushBack(&lt, 4);
	//SListPrint(&lt);
	SListNode* pos = SListFind(&lt, 2);

	//SListPopBack(&lt);
	//SListPrint(&lt);

	/*SListEraseAfter(&lt);
	SListPrint(&lt);*/


	//SListNodeRemove(&lt, 2);
	//SListPrint(&lt); 

	SListInsertAfter(pos, 5);
	SListPrint(&lt);

}