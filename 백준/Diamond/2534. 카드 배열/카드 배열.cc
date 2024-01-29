#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#define M 300001
#define MOD 1000000007
using namespace std;
vector<int> graph[2][M];
int n, k, p, edge[2][M], visit[M], heap[M * 5], len;
int path[M];
long long value[M] = {1, };
long long n1, n2, r;
void up(int idx);
void down(int idx);
int main()
{
	scanf("%d%d%d", &n, &k, &p);

	// n ^ i 를 미리 구해 놓음
	for (int i = 1; i < k; i++) value[i] = (value[i - 1] * n) % MOD;
	for (int i = 0; i < p; i++)
	{
		int st, ed;
		scanf("%d%d", &st, &ed);
		graph[0][st].push_back(ed); edge[0][ed]++;
		graph[1][ed].push_back(st); edge[1][st]++;
	}
	for (int i = 0; i < k; i++)
	{
		if (edge[0][i] == 0)
		{
			heap[++len] = i;
			up(len);
		}
	}
	int number = k;
	while (len)
	{
		int node = heap[1];
		heap[1] = heap[len--];
		down(1);
		n1 += ((--number) * value[node]) % MOD;
		n1 %= MOD;
		for (int i = 0; i < (int)graph[0][node].size(); i++)
		{
			int tnode = graph[0][node][i];
			if (--edge[0][tnode] == 0)
			{
				heap[++len] = tnode;
				up(len);
			}
		}
	}

	// 32410
	len = 0;
	for (int i = 0; i < k; i++)
	{
		visit[i] = 0;
		if (edge[1][i] == 0)
		{
			heap[++len] = i;
			up(len);
		}
	}
	number = n - k -1;
	while (len)
	{
		int node = heap[1];
		heap[1] = heap[len--];
		down(1);
		n2 += ((++number) * value[node]) % MOD;
		n2 %= MOD;
		for (int i = 0; i < (int)graph[1][node].size(); i++)
		{
			int tnode = graph[1][node][i];
			if (--edge[1][tnode] == 0)
			{
				heap[++len] = tnode;
				up(len);
			}
		}
	}
	printf("%lld", ((n2  + MOD)- n1) % MOD);
	return 0;
}
void change(int x, int y)
{
	int tmp = heap[x];
	heap[x] = heap[y];
	heap[y] = tmp;
}
void up(int idx)
{
	if (idx / 2 <= 0) return;
	if (heap[idx] < heap[idx / 2])
	{
		change(idx, idx / 2);
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
		change(idx, child);
		down(child);
	}
}

