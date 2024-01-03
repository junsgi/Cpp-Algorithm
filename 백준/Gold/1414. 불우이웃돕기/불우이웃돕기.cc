#pragma warning(disable:4996)
#include <stdio.h>
#define MAX 0x7fffffff
using namespace std;
int n, ans, graph[55][55], cost[55], visit[55], node = -1, min, sum;
char tmp;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j) graph[i][j] = MAX;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf(" %c", &tmp);
			int com = 0;
			if ('a' <= tmp)
				com = tmp - 96;
			else if ('A' <= tmp)
				com = tmp - 38;
			else com = MAX;
			if (com != MAX) ans += com;
			if (i != j && graph[i][j] > com)
				graph[i][j] = graph[j][i] = com;

		}
	}
	visit[1] = 1;
	min = MAX;
	for (int i = 1; i <= n; i++)
	{
		cost[i] = graph[1][i];
		if (visit[i] == 0 && min > cost[i])
		{
			min = cost[i];
			node = i;
		}
	}
	for (int i = 1; i < n; i++)
	{
		if (node == -1)
		{
			sum = ans + 1;
			break;
		}
		sum += min;
		min = MAX;
		int tnode = -1;
		visit[node] = 1;
		for (int j = 1; j <= n; j++)
		{
			if (!visit[j])
			{
				if (cost[j] > graph[node][j])
					cost[j] = graph[node][j];

				if (min > cost[j])
				{
					min = cost[j];
					tnode = j;
				}
			}
		}
		node = tnode;
	}
	printf("%d", ans - sum);
	return 0;
}