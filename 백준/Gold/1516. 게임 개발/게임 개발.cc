#pragma warning(disable:4996)
#include<stdio.h>
#include<vector>
using namespace std;
int n, m, edge[32100], cost[501], ans[501], t;
int heap[500000], len;
vector<int> graph[32100];
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
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &m);
		cost[i] = m;
		while (1)
		{
			scanf("%d", &t);
			if (t == -1) break;
			edge[i]++;
			graph[t].push_back(i);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (edge[i] == 0)
		{
			ans[i] = cost[i];
			heap[++len] = i;
			up(len);
		}
	}

	while (len)
	{
		int node = heap[1];
		heap[1] = heap[len--];
		down(1);

		for (int i = 0; i < (int)graph[node].size(); i++)
		{
			if (edge[graph[node][i]] == 0) continue;
			// 다음 노드를 짓는 비용과 현재 노드까지의 비용 + 다음 노드 짓는데 드는 비용을 비교
			ans[graph[node][i]] = max(ans[graph[node][i]], ans[node] + cost[graph[node][i]]);
			if (--edge[graph[node][i]] == 0)
			{
				heap[++len] = graph[node][i];
				up(len);
			}
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d\n", ans[i]);
	return 0;
}