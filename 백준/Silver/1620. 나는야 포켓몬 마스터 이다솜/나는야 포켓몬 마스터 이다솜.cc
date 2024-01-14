#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define M 100'009
using namespace std;
int a, b;
vector<int> Hash[M];
char name[M][50], t[50];
int Key(char a[])
{
	int r = 1, result = 0;
	for (int i = 0; a[i]; i++)
	{
		int t = a[i] <= 'Z' ? a[i] - 64 : a[i] - 70;
		result = (result + t * r) % M;
		r = r * 31 % M;
	}
	return result % M;
}
int numKey(char a[])
{
	int result = 0;
	for (int i = 0; a[i]; i++)
	{
		result = result * 10 + a[i] - '0';
	}
	return result;
}
int main()
{
	scanf("%d%d", &a, &b);
	for (int i = 1; i <= a; i++)
	{
		scanf("%s", name[i]);
		Hash[Key(name[i])].push_back(i);
		/*
		*	  key     value
		Hash< string, int  >
		*/
	}
	for (int i = 0; i < b; i++)
	{
		scanf("%s", t);
		if ('0' <= t[0] && t[0] <= '9')
			printf("%s\n", name[numKey(t)]);
		else
		{
			int k = Key(t);
			for (int j = 0; j < (int)Hash[k].size(); j++)
			{
				if (strcmp(t, name[Hash[k][j]]) == 0)
				{
					printf("%d\n", Hash[k][j]);
					break;
				}
			}
		}
	}
	return 0;
}
