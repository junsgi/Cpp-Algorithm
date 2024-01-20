#pragma warning(disable:4996)
#include<stdio.h>
#include<vector>
using namespace std;
int n, m, edge[32100], v, e;
int heap[500000], len;
vector<int> graph[32100];
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
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &v, &e);
		edge[e]++;
		graph[v].push_back(e);
	}
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
		printf("%d ", node);
		heap[1] = heap[len--];
		down(1);

		for (int i = 0; i < (int)graph[node].size(); i++)
		{
			if (edge[graph[node][i]] == 0) continue;
			if (--edge[graph[node][i]] == 0)
			{
				heap[++len] = graph[node][i];
				up(len);
			}
		}
	}
	return 0;
}