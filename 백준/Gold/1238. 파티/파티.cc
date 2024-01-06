#pragma warning(disable:4996)
#include<stdio.h>
using namespace std;
int n, m, go[1'001][1'001], back[1'001][1'001], cost[1'000], visit[1'000], start;
int MAX = 100'000'000, ans[1'001];
/*
정방향일 때 파티 장소에서 탐색하면 파티장소에서 집으로 돌아가는데 최소비용이 구해짐
역방향일 때 파티 장소에서 탐색하면 집에서 파티장소로 가는데 최소비용이 구해짐
왔던길을 되돌아 가야하므로 역방향 그래프를 가진 배열을 하나 더 생성한다.
*/
void dijkstra(int graph[][1001])
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
		if (node == -1) return;
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
	scanf("%d%d%d", &n, &m, &start);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j) go[i][j] = back[i][j] = MAX;

	for (int i = 0; i < m; i++)
	{
		int st, ed, c;
		scanf("%d%d%d", &st, &ed, &c);
		go[st][ed] = back[ed][st] = c;
	}

	int result = 0;
	dijkstra(go);
	for (int i = 1; i <= n; i++)
		ans[i] = cost[i];

	dijkstra(back);
	for (int i = 1; i <= n; i++)
	{
		ans[i] += cost[i];
		if (result < ans[i])
			result = ans[i];
	}
	printf("%d", result);
	return 0;
}
