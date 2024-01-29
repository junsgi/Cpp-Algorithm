#pragma warning(disable:4996)
#include<stdio.h>
#include<vector>
#define M 100'001
using namespace std;
int n, st, ed, pa[M];
vector<int> graph[M];
void DFS(int node)
{
	for (int i = 0; i < (int)graph[node].size(); i++)
	{
		int tnode = graph[node][i];
		if (pa[tnode]) continue;
		pa[tnode] = node;
		DFS(tnode);
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d%d", &st, &ed);
		graph[st].push_back(ed);
		graph[ed].push_back(st);
	}
	pa[1] = 1;
	DFS(1);
	for (int i = 2; i <= n; i++)
		printf("%d\n", pa[i]);

	return 0;
}