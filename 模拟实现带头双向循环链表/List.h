#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdlib.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
	struct SListNode* _prev;

}SListNode;

typedef struct SList
{
	struct SListNode* _head;
}SList;

//初始化
void SListInit(SList* plt);

void SListDestory(SList* plt);

SListNode* BuySListNode(SLTDataType x);

//头插
void SListPushFront(SList* plt, SLTDataType x);

//头删
void SListPopfront(SList* plt);

void SListPushBack(SList* plt, SLTDataType x);

void SListPopBack(SList*plt);

SListNode* SListFind(SList* plt, SLTDataType x);

//在pos后插入
void SListInsertAfter(SListNode* pos, SLTDataType x);
//在pos前面插入
void SListNodeErase(SList*plt, SListNode* pos);
void SListNodeRemove(SList*plt, SLTDataType x);

void SListPrint(SList* plt);

void TestSList();

