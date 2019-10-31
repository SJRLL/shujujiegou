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

void SListInit(SList* plt);//初始化
void SListDestory(SList* plt);//

SListNode* BuySList(SLTDataType x);
void SListPushFront(SList* plt, SLTDataType x);//头插
void SListPopfront(SList* plt);//头删

void SListPushBack(SList* plt, SLTDataType x);
void SListPopBack(SList*plt);

SListNode* SListFind(SList* plt, SLTDataType x);

//在pos后插入
void SListInsertAfter(SListNode* pos, SLTDataType x);
//在pos前面插入
void SListEraseAfter(SListNode* pos);
void SListNodeRemove(SList*plt, SLTDataType x);

void SListPrint(SList* plt);

void TestSList();
