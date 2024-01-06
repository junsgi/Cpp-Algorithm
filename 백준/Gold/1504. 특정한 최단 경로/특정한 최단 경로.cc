#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int n, m, graph[1'001][1'001], cost[1'000], visit[1'000], v1, v2;
int MAX = 500'000'000, ans1, ans2;
void dijkstra(int start)
{

	for (int i = 1; i <= n; i++)
	{
		cost[i] = MAX;
		visit[i] = 0;
	}
	cost[start] = 0;
	visit[start] = 1;
	int node = start, tnode, min;
	for (int i = 1; i < n; i++)
	{
		if (node == -1)
			return;
		min = MAX;
		tnode = -1;
		visit[node] = 1;
		for (int j = 1; j <= n; j++)
		{
			if (!visit[j])
			{
				if (cost[j] > cost[node] + graph[node][j])
					cost[j] = cost[node] + graph[node][j];

				if (min > cost[j])
				{
					min = cost[j];
					tnode = j;
				}
			}
		}
		node = tnode;
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j) graph[i][j] = MAX;

	for (int i = 0; i < m; i++)
	{
		int st, ed, c;
		scanf("%d%d%d", &st, &ed, &c);
		graph[st][ed] = graph[ed][st] = c;
	}
	scanf("%d%d", &v1, &v2);
	// 1 -> v1, v2
	dijkstra(1);
	ans1 += cost[v1];
	ans2 += cost[v2];

	// v1 -> v2
	dijkstra(v1);
	ans1 += cost[v2];

	// v2 -> v1
	dijkstra(v2);
	ans2 += cost[v1];


	// v1 -> N
	dijkstra(v2);
	ans1 += cost[n];

	// v2 -> N
	dijkstra(v1);
	ans2 += cost[n];

	int ans = ans1 < ans2 ? ans1 : ans2;
	printf("%d", ans >= MAX ? -1 : ans);
	return 0;
}
