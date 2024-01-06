/*
시작 점에서 부터 모든 정점의 최단 거리를 구한다.
도착지점에서부터
 (도착지점과 연결된 정점 까지의 최단거리 + 연결된 정점에서 도착 지점의 거리 ==  도착지점 최단거리 )
 위 식이 성립되면 최단거리로 들어오는 간선이므로 간선을 잘라낸다

 BFS 알고리즘으로 모든 최단 거리 간선을 잘라낸다.
*/

#pragma warning(disable:4996)
#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
int v, e, st, ed, graph[1'001][1'001], cost[1'000], visit[1'000];
int MAX = 500'000'000;
queue<int> que;
void dijkstra(int start)
{
	for (int i = 0; i < v; i++)
	{
		cost[i] = MAX;
		visit[i]  = 0;
	}
	cost[start] = 0;
	visit[start] = 1;
	int node = start, tnode, min;
	for (int i = 1; i < v; i++)
	{
		if (node == -1)
			return;
		min = MAX;
		tnode = -1;
		visit[node] = 1;
		for (int j = 0; j < v; j++)
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
void BFS()
{
	que.push(ed);
	while (!que.empty())
	{
		int tmp = que.front();
		que.pop();

		for (int i = 0; i < v; i++)
		{
			if (i != tmp && cost[i] + graph[i][tmp] == cost[tmp])
			{
				graph[i][tmp] = MAX;
				que.push(i);
			}
		}
	}
}
int main()
{
	while (1)
	{
		scanf("%d%d", &v, &e);
		if (v + e == 0) break;
		scanf("%d%d", &st, &ed);
		for (int i = 0; i < v; i++)
			for(int j = 0 ; j < v ; j++)
				if (i != j)graph[i][j] = MAX;
		for (int i = 0; i < e; i++)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			graph[a][b] = c;
		}
		dijkstra(st);
		BFS();
		dijkstra(st);
		printf("%d\n", cost[ed] >= MAX ? -1 : cost[ed]);
	}
	return 0;
}
