#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include<stdio.h>
#include<malloc.h>
#include<assert.h>

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;

typedef struct SList
{
	SListNode* _head;
}SList;

void SListInit(SList* plt);//��ʼ��
void SListDestory(SList* plt);//

SListNode* BuySList(SLTDataType x);
void SListPushFront(SList* plt, SLTDataType x);//ͷ��
void SListPopfront(SList* plt);//ͷɾ

void SListPushBack(SList* plt, SLTDataType x);
void SListPopBack(SList*plt);

SListNode* SListFind(SList* plt, SLTDataType x);

//��pos�����
void SListInsertAfter(SListNode* pos, SLTDataType x);
//��posǰ�����
void SListEraseAfter(SListNode* pos);
void SListNodeRemove(SList*plt, SLTDataType x);

void SListPrint(SList* plt);

void TestSList();
