#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#define M 500'000'000
using namespace std;
int n, graph[30][30], check[30][30], ans;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &graph[i][j]);
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				// 더 작은 값이 존재한다면 -1
				if (graph[i][j] > graph[i][k] + graph[k][j])
				{
					printf("-1");
					return 0;
				}
				if (i == k || j == k) continue;
				if (graph[i][j] == graph[i][k] + graph[k][j])
					check[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			if (!check[i][j]) ans += graph[i][j];
	}
	printf("%d", ans / 2);
	
	return 0;
}
