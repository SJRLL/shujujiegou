#define _CRT_SECURE_NO_WARNINGS 1

#include"Sort.h"

void InsertSort(int* a, int n)
{
	for (size_t i = 0; i < n - 1; ++i)//��һ���������������
	{
		int end = i;//���ʼ���бȽ�

		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end+1]=a[end];//���뵽�������С�ĺ���λ��   //Swap(&a[end + 1], &a[end]);
				--end;
				
			}
			else
			{
				break;
			}
		}

		a[end + 1] = tmp;///�����λ��Ϊ-1ʱ

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
		
		for (size_t i = begin; i < end; ++i)//����һ�飬�ҳ�������С����
		{
			if (a[i] > a[max])
				max = i;
			if (a[i] <= a[min])
				min = i;
		}
	    
		if (max==begin)//�����һ��������������
		{
			max = min;//��max���±��ƶ�����һ������ָ����
		}
		Swap(&a[min], &a[begin]);//����С�����ݷ����ͷ��������Ѱ�Ҵ�С�ķ��ڿ�ͷ����һλ


		Swap(&a[max], &a[end]);//���������ݷ���β����������Ѱ�Ҵδ�ķ���ĩβ�ĵ�ǰһλ
		    begin++;
			end--;
	}
	
}


void AdjustDown(int* a, int size,int root)//���µ����㷨�����򣬽����
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
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)//����
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0],&a[end]);//����С�����������
		AdjustDown(a, end, 0);
		end--;
	}
}

void BubbleSort(int* a, int n)//����
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
		while (left < right && a[left] <= a[key])//����ұ�key�����
			++left;

		while (left < right && a[right]>=a[key])//�ұ��ұ�keyС����
			--right;

		Swap(&a[left], &a[right]);
	}
	Swap(&a[key], &a[left]);//��left��right����ʱ������key��left
	return left;
}

void QuickSort1(int* a, int left, int right)//����ָ�뷨
{
	if (right <= left)
		return;
	int index = PartSort(a, left, right);//�ݹ�˼��
	QuickSort1(a, left, index - 1);
	QuickSort1(a, index + 1, right);

}


int PartSort2(int* a, int left, int right)
{
	int key = a[right];//��key��ס���λ��
	while (left < right)
	{
		while (left < right && a[left] <= key)//����ұ�key���
			++left;
		a[right] = a[left];//�ҵ������key������ݣ��key���ڵ�λ�ã��ճ����λ��

		while(left < right && a[right] >= key)//�ұ��ұ�keyС��
			--right;
		a[left] = a[right]; //�ҵ������keyС�����ݣ��left���ڵ�λ�ã��ճ����λ��
	}

	 a[left] = key;//��left��right����ʱ����key�leftλ��
	return left;
}

void QuickSort2(int* a, int left, int right)//����ָ�뷨
{
	if (right <= left)
		return;
	int index = PartSort2(a, left, right);//�ݹ�˼��
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
	int index = PartSort3(a, left, right);//�ݹ�˼��
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