#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

void Swap(int* p1, int* p2)
{
	int temp = 0;
	temp = * p1;
	*p1 = *p2;
	*p2 = temp;
}

void AdjustDown(HPDataType* a, size_t n,size_t parent)//向下调整
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		//选小的那个孩子
		if (child + 1 <n && a[child + 1] < a[child])
		{
			++child;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent=child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}


void AdjustUp(HPDataType* a, size_t n)
{
	int child = n ;
	int parent = (child - 1 - 1) / 2;
	while (child> 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1 - 1) / 2;
		}
		else
		{
			break;
		}
	}
}


void HeapInit(Heap* hp, HPDataType* a, int n)//建小堆
{
	assert(hp &&   a);
	hp->_a = malloc(sizeof(HPDataType)*n);

	memcpy(hp->_a, a, sizeof(HPDataType)*n);
	hp->_size = n;
	hp->_capacity = n;
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}

}

void HeapPrint(Heap* hp)
{
	int i = 0;
	for (i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}

void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->_size = 0;
	hp->_capacity = 0;
}

void ChackCapacity(Heap* hp)
{
	if (hp->_size == hp->_capacity)
	{
		size_t newcapacity=hp->_capacity ==0?2: hp->_capacity* 2;
		hp->_a = (HPDataType*)realloc(hp->_a, sizeof(HPDataType)*hp->_capacity);
		hp->_capacity = newcapacity;
	}
}
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	ChackCapacity(hp);
	hp->_a[hp->_size] = x;
	++hp->_size;
	AdjustUp(hp->_a, hp->_size);
}

void HeapPop(Heap* hp)
{
	assert(hp);
	int i = 0;
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);//交换第一个和最后一个
	hp->_size--;//最后一个不计入堆里
	for (i = (hp->_size - 2) / 2; i >= 0; --i)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
}

HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_a[0];;
}

int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}

int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->_size == 0 ? 0 : 1;
}

//堆排序

void HeapSort(int *a, int n)
{
	int i = 0;
	int end = n - 1;
	assert(a);
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

/*void Topk()
{
	Heap hp;
	size_t i = 0;
	const size_t N = 100000;
	const size_t k = 10;
	size_t* a = (size_t *)malloc(sizeof(size_t)*N);

}*/

void TestHeap()
{
	int a[] = { 2, 7, 3, 9, 4, 6, 8, 1, 5 };
	Heap hp;
	int b = sizeof(a) / sizeof(a[0]);
	HeapInit(&hp, a, b);
	HeapPrint(&hp);


	/*HeapPush(&hp, 11);
	HeapPrint(&hp);*/
	//int c = 0;
	//c = HeapTop(&hp);

	HeapSort(a, sizeof(a) / sizeof(a[0]));
	int i = 0;
	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
