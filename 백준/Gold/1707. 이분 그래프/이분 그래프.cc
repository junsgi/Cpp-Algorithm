#pragma warning(disable:4996)
#include<stdio.h>
#include <queue>
#include <vector>
using namespace std;
int n, visit[20001], v, e;
vector<int> graph[20001];
queue<int> que;

bool BFS(int node)
{
	que = queue<int>();
	que.push(node);
	visit[node] = 1;

	while (!que.empty())
	{
		int x = que.front();
		que.pop();

		for (int i = 0; i < (int)graph[x].size(); i++)
		{
			if (visit[x] == visit[graph[x][i]]) return false;
			if (visit[graph[x][i]] == 0)
				que.push(graph[x][i]);
			visit[graph[x][i]] = -visit[x];
		}
	}
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{

		scanf("%d%d", &v, &e);
		fill(visit, visit + v + 1, 0);
		for (int j = 1; j <= v; j++)
			graph[j].clear();
		for (int j = 0; j < e; j++)
		{
			int st, ed;
			scanf("%d%d", &st, &ed);
			graph[st].push_back(ed);
			graph[ed].push_back(st);

		}
		bool swi = true;
		for (int j = 1; j <= v; j++)
		{
			if (visit[j] == 0 )
			{
				if (!BFS(j))
				{
					swi = false;
					break;
				}
			}
		}
		if (swi) printf("YES\n");
		else printf("NO\n");
		

	}
	return 0;
}

