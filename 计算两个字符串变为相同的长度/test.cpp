#define _CRT_SECURE_NO_WARNINGS 1


#include<stdlib.h>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int changestring(string& s1, string& s2)
{
	int m = s1.size();
    int n = s2.size();
	int a = 1, b = 1, c = 1;
	vector<vector<int>> vv(m + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= m; ++i)
	{
		vv[i][0] = b*i;
	}

	for (int i = 1; i <= n; ++i)
	{
		vv[0][i] = c * 1;
	}


	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int one = vv[i - 1][j] + a;
			int two = vv[i][j - 1] + b;
			int three = vv[i - 1][j - 1];

			if (s1[i - 1] != s2[j - 1])
				three++;

			vv[i][j] = min(one, min(two, three));
		}
	}

	return vv[m][n];
}



int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		cout << changestring(s1, s2)<<endl;
	}
	system("pause");
	return 0;
}
