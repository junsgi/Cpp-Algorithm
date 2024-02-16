#pragma warning(disable:4996)
#include<stdio.h>
#include<vector>
#define MAX(x, y)( ((x)>(y)) ? (x) : (y) )
#define MIN(x, y)( ((x)<(y)) ? (x) : (y) )
#define M 1'000'000'000
using namespace std;
int n, visit[1 << 17][17];
int graph[17][17];

int DFS(int node, int status)
{
	if (visit[status][node])
		return visit[status][node];
	if (status == (1 << n) - 1)
		return graph[node][0] ? graph[node][0] : M;
	visit[status][node] = M;
	for (int i = 0; i < n; i++)
	{
		int tnode = i;
		int cost = graph[node][i];

		if (status & (1 << tnode)) continue;
		if (graph[node][tnode] == 0) continue;
		visit[status][node] =
			MIN(visit[status][node], DFS(tnode, status | (1 << tnode)) + cost);
	}
	return visit[status][node];
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &graph[i][j]);
	printf("%d", DFS(0, 1));
	return 0;
}