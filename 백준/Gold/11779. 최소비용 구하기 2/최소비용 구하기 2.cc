#pragma warning(disable:4996)
#include<stdio.h>
using namespace std;
int n, m, graph[1'001][1'001], cost[1'000], visit[1'000], dire[1'000], start, end;
int MAX = 0x7fffffff / 2, cnt = 1;

void dijkstra()
{
	for (int i = 1; i <= n; i++)
		cost[i] = MAX;
	cost[start] = 0;
	int node = start, min = MAX;
	int tnode = -1;
	for (int i = 0; i < n - 1; i++)
	{
		if (node == -1) return;
		min = MAX;
		visit[node] = 1;
		tnode = -1;
		for (int j = 1; j <= n; j++)
		{
			// 바로 j로 가는게 더 비용이 적은지 현재 노드를 경유로해서 가는 것이 비용이 적게 드는지 확인
			if (!visit[j] && cost[j] > cost[node] + graph[node][j])
			{
				cost[j] = cost[node] + graph[node][j];
				dire[j] = node;
			}
			if (!visit[j] && min > cost[j])
			{
				min = cost[j];
				tnode = j;
			}
		}
		node = tnode;
	}
}

void k(int idx, int depth)
{
	if (idx == start)
	{
		printf("%d\n", depth);
		printf("%d ", start);
		return;
	}
	k(dire[idx], depth + 1);
	printf("%d ", idx);
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j)graph[i][j] = MAX;

	for (int i = 0; i < m; i++)
	{
		int st, ed, c;
		scanf("%d%d%d", &st, &ed, &c);
		if (graph[st][ed] > c)
			graph[st][ed] = c;
	}
	scanf("%d%d", &start, & end);
	dijkstra();

	printf("%d\n", cost[end]);
	k(end, 1);
	return 0;
}
