#define _CRT_SECURE_NO_WARNINGS 1

#include"Sort.h"

void InsertSort(int* a, int n)
{
	for (size_t i = 0; i < n - 1; ++i)//让一段无序的数组有序
	{
		int end = i;//从最开始进行比较

		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end+1]=a[end];//插入到比他大和小的合适位置   //Swap(&a[end + 1], &a[end]);
				--end;
				
			}
			else
			{
				break;
			}
		}

		a[end + 1] = tmp;///插入的位置为-1时

	}
}

void ShellSort(int* a, int n)
{
	int gap = 0;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (size_t i = 0; i < n - gap; ++i)//
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end] = a[end + gap];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + 1] = tmp;
		}
	}
	
}


 Swap(int* x1, int* x2)
{
	int tmp = *x1;
	*x1 = *x2;
	*x2 = tmp;
}

void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n-1;
	

	while (begin < end)
	{
		int min  = begin;
	    int max = end;
		
		for (size_t i = begin; i < end; ++i)//遍历一遍，找出最大和最小的数
		{
			if (a[i] > a[max])
				max = i;
			if (a[i] <= a[min])
				min = i;
		}
	    
		if (max==begin)//如果第一个数就是最大的数
		{
			max = min;//把max的下标移动到第一个数下指向它
		}
		Swap(&a[min], &a[begin]);//把最小的数据放在最开头，在依次寻找次小的放在开头的下一位


		Swap(&a[max], &a[end]);//把最大的数据放在尾部，再依次寻找次大的放在末尾的的前一位
		    begin++;
			end--;
	}
	
}


void AdjustDown(int* a, int size,int root)//向下调整算法，升序，建大堆
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 <size && a[child + 1] < a[child])
		{
			++child;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
		
	}
}

void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)//建堆
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0],&a[end]);//将最小的数换到最顶部
		AdjustDown(a, end, 0);
		end--;
	}
}

void BubbleSort(int* a, int n)//升序
{
	int end = n - 1;
	while (end>=0)
	{
		for (int i = 0; i < end; ++i)
		{
			if (a[i]>a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
			}
		}
		--end;
	}
}

int GetMid(int* a, int left, int right)
{
	assert(a);
	int mid = left + (right - left) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left]>a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left]<a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

int PartSort(int* a, int left,int right)
{
	//int mid = GetMid(a, left, right);
	//Swap(&a[mid], &a[right]);
	int key =right;
	while (left < right)
	{
		while (left < right && a[left] <= a[key])//左边找比key大的数
			++left;

		while (left < right && a[right]>=a[key])//右边找比key小的数
			--right;

		Swap(&a[left], &a[right]);
	}
	Swap(&a[key], &a[left]);//当left和right相遇时，交换key和left
	return left;
}

void QuickSort1(int* a, int left, int right)//左右指针法
{
	if (right <= left)
		return;
	int index = PartSort(a, left, right);//递归思想
	QuickSort1(a, left, index - 1);
	QuickSort1(a, index + 1, right);

}


int PartSort2(int* a, int left, int right)
{
	int key = a[right];//用key记住这个位置
	while (left < right)
	{
		while (left < right && a[left] <= key)//左边找比key大的
			++left;
		a[right] = a[left];//找到这个比key大的数据，填到key所在的位置，空出这个位置

		while(left < right && a[right] >= key)//右边找比key小的
			--right;
		a[left] = a[right]; //找到这个比key小的数据，填到left所在的位置，空出这个位置
	}

	 a[left] = key;//当left和right相遇时，把key填到left位置
	return left;
}

void QuickSort2(int* a, int left, int right)//左右指针法
{
	if (right <= left)
		return;
	int index = PartSort2(a, left, right);//递归思想
	QuickSort2(a, left, index - 1);
	QuickSort2(a, index + 1, right);

}

int PartSort3(int* a, int left, int right)
{
	int cur = left;
	int prev = left - 1;
	int key = a[right];
	while (cur< right)
	{
		if (a[cur] < key  && ++prev != cur)
		{
			
			Swap(&a[prev], &a[cur]);
		}
		++cur;
	}

	++prev;
	Swap(&a[prev],&a[right]);

	return prev;
}

void QuickSort3(int* a, int left, int right)
{
	if (right <= left)
		return;
	int index = PartSort3(a, left, right);//递归思想
	QuickSort3(a, left, index - 1);
	QuickSort3(a, index + 1, right);
}

void _MergeSort(int* a, int* tmp, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	int mid = begin + (end - begin) / 2;

	_MergeSort(a, tmp, begin, mid);
	_MergeSort(a, tmp, mid + 1, end);

	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;
	int index = 0;

	while (begin <= end1 && begin <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}

	for (int i = 0; i < index; ++i)
	{
		a[begin + i] = tmp[i];
	}
}

void Mergesort(int*a, int n)
{
	int* tmp = (int*)(malloc)(sizeof(int)*n);
	_MergeSort(a, tmp, 0, n - 1);
	free(tmp);
}

void PrintSort(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}



void TestSort()
{
	int a[] = {9,3,4,2,6,7,5,8,1 };
	int num = sizeof(a) / sizeof(0);
	//InsertSort(a, num);
	//PrintSort(a, num);

	//ShellSort(a, num);
	//PrintSort(a, num);

	//SelectSort(a, num);
	//PrintSort(a, num);

	//HeapSort(a, num);
	//PrintSort(a, num);

	//BubbleSort(a, num);
	//PrintSort(a, num);

	//int num2 = GetMid(a, 0, num - 1);
	//printf("%d\n", num2);

	//QuickSort1(a,0, num-1);
	//PrintSort(a, num);

	//QuickSort2(a, 0, num - 1);
	//PrintSort(a, num);

	//QuickSort3(a, 0, num - 1);
	//PrintSort(a, num);

	Mergesort(a, num);
	PrintSort(a, num);

}