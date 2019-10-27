#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
using namespace std;
typedef char* String;

//得到next数组
void Get_Next(String T, int *next)
{
	int j, k;
	j = 0;
	k = -1;
	next[0] = -1;
	while (j < strlen(T))
	{
		if (k == -1 || T[j] == T[k])
		{
			j++;
			k++;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
}

//KMP算法
int KMP(String S, String T, int *next)
{
	int i = 0, j = 0;
	Get_Next(T, next);
	int slen = strlen(S);
	int tlen = strlen(T);

	while (i < slen && j < tlen)
	{
		if (j == -1 || S[i] == T[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j == tlen)
	{
		return i - tlen;
	}
	else
	{
		return -1;
	}
}

void main()
{
	cout << "next就是输入的那一串字符每一个字符多对应的下标 " << endl;
	int N;
	cout << "请输入你想测试的次数：" << endl;
	cin >> N;
	while (N--)
	{
		cout << endl;
		cout << "请输入一串字符：" << endl;
		char S[255];
		char T[255];
		cin >> S >> T;
		int next[255];
		int i = 1;
		//cout << strlen(S) << endl;
		Get_Next(T, next);
		cout << "模式每一个字符对应的next的值为:" << endl;
		for (i = 0; i < strlen(T); i++)
		{
			printf("%d ", next[i]);
		}
		cout << endl;
		cout << "匹配出现的位置：" << KMP(S, T, next) << endl;

	}
	cout << endl;
	system("pause");
}