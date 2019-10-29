#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
#include<string.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* _a;
	int _size;//¸öÊý
	int _capacity;//ÈÝÁ¿

}Heap;

void HeapInit(Heap* hp, HPDataType* a, int n);
void HeapDestory(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);

void HeapPop(Heap* hp);

HPDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);

//¶ÑÅÅÐò

void HeapSort(int *a, int n);

void Topk();

void HeapPrint(Heap* hp);
void TestHeap();