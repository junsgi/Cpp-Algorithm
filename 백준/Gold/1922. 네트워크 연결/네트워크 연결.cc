#include<stdio.h>
#include <queue>
using namespace std;
struct compare{
	bool operator() (pair<int, int> i, pair<int, int> j)
	{
		return i.second > j.second;
	}
};
priority_queue <pair<int, int>, vector<pair<int, int>>, compare> que;
int n, m, ans, graph[1010][1010], cost[1010], visit[1010], MAX=0x7fffffff;


void spanning(int node)
{
	if(visit[node]) return;
	visit[node] = 1;
	int nxt_node = 0, min = MAX; 
	for(int i = 1 ; i <= n ; i++)
	{
		if (!visit[i] && cost[i] > graph[node][i])
			cost[i] = graph[node][i];

		if (!visit[i] && min > cost[i])
		{
			nxt_node = i;
			min = cost[i];
		}
	}

	spanning(nxt_node);
}

int main()
{
	fill(&graph[0][0], &graph[1009][1009], MAX);
	fill(&cost[0], &cost[1009], MAX);
	scanf("%d", &n);
	scanf("%d", &m);
	for(int i = 0 ; i < m ; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		graph[x][y] = graph[y][x] = z;
	}
	spanning(1);

	for(int i = 1 ; i <= n ; i++) 
	{
		if (cost[i] != MAX)
			ans += cost[i];
	}
	printf("%d", ans);
	return 0;
}
