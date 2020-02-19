#include<iostream>
#include<assert.h>
using namespace std;

void BubbleSort(int *a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int flag = 0;
		for (int j = 0; j < n - 1; ++j)
		{
			if (a[j]>a[j + 1])
			{
				flag = 1;
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}

int PartSort1(int *a, int left, int right) //挖坑法
{
	int key = a[right];
	while (left < right)
	{
		while (left < right && a[left] <= key) //左边找比key大的元素
		{
			++left;
		}
		a[right] = a[left]; //左边找到比key大的数的时候，将它填充到key的位置

		while (left < right && a[right] >= key)  //右边找比key小的元素
		{
			--right;
		}
		a[left] = a[right]; //右边找到比key小的元素时，将它填充到a[left]的位置
	}
	//走到left和riht相遇的时候，把key填充到left的位置
	a[left] = key;
	return left;
}

void QuickSort1(int *a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int index = PartSort1(a, left, right); //递归思想
	QuickSort1(a, left, index - 1);
	QuickSort1(a, index + 1, right);
}

int PartSort2(int *a, int left, int right)//左右指针法
{
	int key = right;
	while (left < right)
	{
		while (left < right && a[left] <= a[key])
		{
			++left;
		}
		while (left<right && a[right] >= a[key])
		{
			--right;
		}
		int tmp = a[left];
		a[left] = a[right];
		a[right] = a[left];
	}
	int req = a[left];
	a[left] = a[key];
	a[key] = req;
	return left;
}

void QuickSort2(int *a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int index = PartSort2(a, left, right); //递归思想
	QuickSort2(a, left, index - 1);
	QuickSort2(a, index + 1, right);
}

int PartSort3(int *a, int left, int right) //前后指针法
{
	int cur = left;
	int div = left - 1;
	int key = right;
	while (cur < right)
	{
		if (a[cur]<a[key] && ++div != cur)
		{
			int tmp = a[cur];
			a[cur] = a[div];
			a[div] = tmp;
		}
		cur++;
	}
	++div;
	int tmp = a[div];
	a[div] = a[key];
	a[key] = tmp;
	return right;
}

int GetMind(int *a, int left, int right)
{
	assert(a);
	int mid = left + (right - left) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[right] < a[left])
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
		if (a[right] < a[mid])
		{
			return mid;
		}
		else if (a[right]>a[left])
		{
			return  left;
		}
		else
		{
			return right;
		}
	}
}
int PartSort4(int *a, int left, int right)
{
	int mid = GetMind(a, left, right);
	int key = mid;
	while (left < right)
	{
	 while (left < right && a[left] <= a[key])
	 {
		++left;
	 }
	 while (left<right && a[right]>= a[key])
	 {
		--right;
	 }
	 int tmp = a[left];
	 a[left] = a[right];
	 a[right] = tmp;
	}
	int tmp = a[left];
	a[left] = a[key];
	a[key] = tmp;
	return left;
}

void QuickSort4(int *a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int index = PartSort4(a, left, right); //递归思想
	QuickSort4(a, left, index - 1);
	QuickSort4(a, index + 1, right);
}

void Swap(int* x1, int* x2)
{
	int tmp = *x1;
	*x1 = *x2;
	*x2 = tmp;
}

//插入排序的思想就是要一直找到元素的合适位置才能停下来
void InsertSort(int *a, int n)
{
	for (int i = 0; i < n-1; ++i)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp<a[end])
			{
				//a[end + 1] = a[end];
				Swap(&a[end + 1], &a[end]);
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp; //插入位置为-1时
	}
}

void ShellSort(int* a, int n)//希尔排序
{
	int gap = n - 1;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp<a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
				a[end + gap] = tmp;
			}
		}	
	}
}

//每次找出一个最大和最小的数，分别交换到末尾和开头
void SelcetSort(int *a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int max = end;
		int min = begin;
		for (size_t i = begin; i <= end; ++i)
		{
			if (a[i]>=a[max])
			{
				max = i;
			}
			if (a[i] <= a[min])
			{
				min = i;
			}
		}
		if (max == begin) //如果第一个数就是最大的数
		{
			max = min;  //就把最大的下标移动到第一个数下边
		}
		Swap(&a[min],& a[begin]);
		Swap(&a[max], &a[end]);
		begin++;
		end--;
	}
}

void AdjustDown(int *a, int size, int root)
{
	int parent = root;
	int chrild = parent * 2 + 1;
	while (chrild < size)
	{
		if (chrild + 1 < size && a[chrild] < a[chrild + 1])
		{
			++chrild;
		}
		if (a[chrild] > a[parent])
		{
			Swap(&a[parent], &a[chrild]);
			parent = chrild;
			chrild = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int *a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0;--i)
	{
         AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);//将最小的元素交换到最上边
		AdjustDown(a, end, 0);
		--end;
	}
}

void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left == right)
		return;
	int mid = left + (right - left)/2;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1];
			++begin1;
		}
		else
		{
			tmp[i++] = a[begin2];
			++begin2;
		}
	}		
	   while (begin1<= end1)
		{
			tmp[i++] = a[begin1];
			++begin1;
		}
		while (begin2<= end2)
		{
			tmp[i++] = a[begin2];
			++begin2;
		}
		memcpy(a + left, left + tmp, sizeof(int)*(i - left));
}

void MergeSort(int*a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}

int main()
{
	int a[] = { 9, 3, 4, 2, 6, 7, 5, 8, 1 };
	int Vsize = sizeof(a) / sizeof(0);
	//BubbleSort(a, Vsize);
	QuickSort1(a, 0, Vsize- 1);
	//QuickSort2(a, 0, Vsize - 1);
	//QuickSort3(a, 0, Vsize - 1);
	//QuickSort4(a, 0, Vsize - 1);

	//InsertSort(a, Vsize);

	//ShellSort(a, Vsize);

	//SelcetSort(a, Vsize);

	//HeapSort(a, Vsize);

	//MergeSort(a, Vsize);
	for (int i = 0; i < Vsize; ++i)
	{
		cout << a[i];
	}
	system("pause");
	return 0;
}