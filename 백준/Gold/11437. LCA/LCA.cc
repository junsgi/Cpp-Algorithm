#pragma warning(disable:4996)
#include<stdio.h>
#include<vector>
#include<string>
#define MAX 100'001
using namespace std;
int n, depth[MAX], pa[MAX];
int max(int a, int b) { return a < b ? b : a; }
int min(int a, int b) { return a > b ? b : a; }
vector<int> graph[MAX];
void DFS(int node)
{
	for (int i = 0; i < (int)graph[node].size(); i++)
	{
		if (depth[graph[node][i]] != -1) continue;
		depth[graph[node][i]] = depth[node] + 1;
		pa[graph[node][i]] = node;
		DFS(graph[node][i]);
	}
}
int main()
{
	scanf("%d", &n);
	fill(depth, depth + n + 1, -1);
	depth[1] = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int st, ed;
		scanf("%d%d", &st, &ed);
		graph[st].push_back(ed);
		graph[ed].push_back(st);
	}
	DFS(1);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int n1, n2;
		scanf("%d%d", &n1, &n2);

		while (depth[n1] != depth[n2])
		{
			if (depth[n1] < depth[n2])
				n2 = pa[n2];
			else
				n1 = pa[n1];
		}
		while (n1 != n2)
		{
			n1 = pa[n1];
			n2 = pa[n2];
		}
		printf("%d\n", n1);
	}
	return 0;
}