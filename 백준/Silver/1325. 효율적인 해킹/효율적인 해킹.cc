#pragma warning(disable:4996)
#include <stdio.h>
#include <vector>
using namespace std;
int v, e, vis = 0, cnt, visit[10001], freq[10001], MAX;
vector<int> graph[10001];
int max(int a, int b) { return a > b ? a : b; }
int DFS(int node, int depth)
{
	visit[node] = vis;
	MAX = max(MAX, ++cnt);

	for (int i = 0; i < (int)graph[node].size(); i++)
	{
		if (visit[graph[node][i]] != vis)
		{
			visit[graph[node][i]] = vis;
			DFS(graph[node][i], depth + 1);
		}
	}
	return cnt;
}
int main()
{

	scanf("%d%d", &v, &e);
	for (int i = 0; i < e; i++)
	{
		int st, ed;
		scanf("%d%d", &st, &ed);
		graph[ed].push_back(st);
	}
	for (int i = 1; i <= v; i++)
	{
		cnt = 0;
		visit[i] = ++vis;
		freq[i] = DFS(i, 1);
	}
	for (int i = 1; i <= v; i++)
	{
		if (freq[i] == MAX) printf("%d ", i);
	}
	return 1;
}