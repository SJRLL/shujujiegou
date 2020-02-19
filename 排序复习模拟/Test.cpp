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

int PartSort1(int *a, int left, int right) //�ڿӷ�
{
	int key = a[right];
	while (left < right)
	{
		while (left < right && a[left] <= key) //����ұ�key���Ԫ��
		{
			++left;
		}
		a[right] = a[left]; //����ҵ���key�������ʱ�򣬽�����䵽key��λ��

		while (left < right && a[right] >= key)  //�ұ��ұ�keyС��Ԫ��
		{
			--right;
		}
		a[left] = a[right]; //�ұ��ҵ���keyС��Ԫ��ʱ��������䵽a[left]��λ��
	}
	//�ߵ�left��riht������ʱ�򣬰�key��䵽left��λ��
	a[left] = key;
	return left;
}

void QuickSort1(int *a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int index = PartSort1(a, left, right); //�ݹ�˼��
	QuickSort1(a, left, index - 1);
	QuickSort1(a, index + 1, right);
}

int PartSort2(int *a, int left, int right)//����ָ�뷨
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
	int index = PartSort2(a, left, right); //�ݹ�˼��
	QuickSort2(a, left, index - 1);
	QuickSort2(a, index + 1, right);
}

int PartSort3(int *a, int left, int right) //ǰ��ָ�뷨
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
	int index = PartSort4(a, left, right); //�ݹ�˼��
	QuickSort4(a, left, index - 1);
	QuickSort4(a, index + 1, right);
}

void Swap(int* x1, int* x2)
{
	int tmp = *x1;
	*x1 = *x2;
	*x2 = tmp;
}

//���������˼�����Ҫһֱ�ҵ�Ԫ�صĺ���λ�ò���ͣ����
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
		a[end + 1] = tmp; //����λ��Ϊ-1ʱ
	}
}

void ShellSort(int* a, int n)//ϣ������
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

//ÿ���ҳ�һ��������С�������ֱ𽻻���ĩβ�Ϳ�ͷ
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
		if (max == begin) //�����һ��������������
		{
			max = min;  //�Ͱ������±��ƶ�����һ�����±�
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
		Swap(&a[0], &a[end]);//����С��Ԫ�ؽ��������ϱ�
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