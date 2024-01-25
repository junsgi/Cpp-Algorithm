#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<pair<int, int>> graph[1001];
queue<pair<int, int>> que;
int n, m, visit[1001], edge[1001], path[1001];
void up(int idx);
void down(int idx);
void t(int node, int depth)
{
	if (depth > 0 && node == 1)
	{
		printf("1 ");
		return;
	}
	t(path[node], depth + 1);
	printf("%d ", node);
}
int main()
{
	scanf("%d%d", &n, &m);
	fill(path, path + n + 1, -1);
	for (int i = 0; i < m; i++)
	{
		int st, ed, cost;
		scanf("%d%d%d", &st, &ed, &cost);
		graph[st].push_back({ ed, cost });
		edge[ed]++;
	}
	que.push({ 1, 0 });
	while (!que.empty())
	{
		pair<int, int> tmp = que.front();
		que.pop();
		int node = tmp.first;
		int cost = tmp.second;
		if (node == 1 && cost > 0) continue;
		for (int i = 0; i < (int)graph[node].size(); i++)
		{
			int tnode = graph[node][i].first;
			int tcost = graph[node][i].second;

			if (edge[tnode] == 0) continue;
			if (visit[tnode] < tcost + cost)
			{
				visit[tnode] = tcost + cost;
				path[tnode] = node;
			}
			if (--edge[tnode] == 0)
				que.push({ tnode, visit[tnode]});
		}
	}
	printf("%d\n", visit[1]);
	t(1, 0);
	return 0;
}
