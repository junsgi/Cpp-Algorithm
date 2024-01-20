#pragma warning(disable:4996)
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int n, m, edge[32100], v, e;
queue<int> que;
vector<int> graph[32100];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &v, &e);
		edge[e]++;
		graph[v].push_back(e);
	}
	for (int i = 1; i <= n; i++)
		if (edge[i] == 0)
			que.push(i);
	while (!que.empty())
	{
		int node = que.front();
		printf("%d ", node);
		que.pop();

		for (int i = 0; i < (int)graph[node].size(); i++)
		{
			if (edge[graph[node][i]] == 0) continue;
			if (--edge[graph[node][i]] == 0)
				que.push(graph[node][i]);
		}
	}
	return 0;
}