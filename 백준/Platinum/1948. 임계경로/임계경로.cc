#pragma warning(disable:4996)
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int n, m, edge[32100], ans[20000], t, v, e, st, ed, result = 0;
int heap[500000], len, visit[20000];
vector<pair<int, int>> graph[2][32100];
int max(int a, int b) { return a < b ? b : a; }
void up(int idx)
{
	if (idx / 2 <= 0) return;
	if (heap[idx / 2] > heap[idx])
	{
		int tmp = heap[idx];
		heap[idx] = heap[idx / 2];
		heap[idx / 2] = tmp;
		up(idx / 2);
	}
}
void down(int idx)
{
	int child = idx * 2;
	if (child > len) return;
	if (child + 1 <= len && heap[child] > heap[child + 1])
		child++;

	if (heap[idx] > heap[child])
	{
		int tmp = heap[idx];
		heap[idx] = heap[child];
		heap[child] = tmp;
		down(child);
	}
}
int BFS(int x)
{
	int cnt = 0;
	len = 0;
	heap[++len] = x;
	up(len);
	visit[x] = 1;
	while (len)
	{
		int node = heap[1];
		heap[1] = heap[len--];
		down(1);

		for (int i = 0; i < (int)graph[1][node].size(); i++)
		{
			int tnode = graph[1][node][i].first;
			int tcost = graph[1][node][i].second;
			if (tcost + ans[tnode] == ans[node])
			{
				if (!visit[tnode])
				{
					visit[tnode] = 1;
					heap[++len] = tnode;
					up(len);
				}
				cnt++;
			}
		}

	}
	return cnt;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &v, &e, &t);
		graph[0][v].push_back({ e, t });
		graph[1][e].push_back({ v, t });
		edge[e]++;
	}
	scanf("%d%d", &st, &ed);
	for (int i = 1; i <= n; i++)
	{
		if (edge[i] == 0)
		{
			heap[++len] = i;
			up(len);
		}
	}
	while (len)
	{
		int node = heap[1];
		heap[1] = heap[len--];
		down(1);
		for (int i = 0; i < (int)graph[0][node].size(); i++)
		{
			if (edge[graph[0][node][i].first] == 0) continue;

			// 다음 노드를 짓는 비용과 현재 노드까지의 비용 + 다음 노드 짓는데 드는 비용을 비교
			ans[graph[0][node][i].first] = max(ans[graph[0][node][i].first], ans[node] + graph[0][node][i].second);
			if (--edge[graph[0][node][i].first] == 0)
			{
				heap[++len] = graph[0][node][i].first;
				up(len);
			}
		}
	}
	printf("%d\n", ans[ed]);
	printf("%d", BFS(ed));
	return 0;
}