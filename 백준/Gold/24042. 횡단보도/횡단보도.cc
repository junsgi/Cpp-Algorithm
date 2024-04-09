#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
#include <vector>
#define M 1'000'000'000'000L
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
struct temp {
	int node; ll value;
};
vector<pii> graph[100'001];
vector<temp> heap;
int n, m;
ll check[100'001];
void up(int idx);
void down(int idx);

ll dijkstra()
{
	heap.push_back({ 1, 0 });

	while ((int)heap.size() != 1)
	{
		temp tmp = heap[1];
		heap[1] = heap[(int)heap.size() - 1];
		down(1);
		heap.pop_back();

		int node = tmp.node;
		ll value = tmp.value;
		if (node == n) continue;
		if (check[node] < value) continue;
		for (int i = 0; i < (int)graph[node].size(); i++)
		{
			int tnode = graph[node][i].first;
			int tt = graph[node][i].second;

			ll v = tt - value % m;
			if (v < 0) v += m;

			ll tvalue = value + v + 1;
			if (check[tnode] < tvalue) continue;
			check[tnode] = tvalue;
			heap.push_back({ tnode, tvalue });
			up((int)heap.size() - 1);
		}
	}
	return check[n];
}

int main()
{
	heap.push_back({});
	scanf("%d%d", &n, &m);
	fill(check + 2, check + n + 1, M);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a].push_back({ b, i });
		graph[b].push_back({ a, i });
	}
	printf("%lld", dijkstra());
	return 0;
}

void change(int x, int y)
{
	temp t = heap[x];
	heap[x] = heap[y];
	heap[y] = t;
}

void up(int idx)
{
	int p = idx / 2;
	if (!p) return;
	if (heap[idx].value < heap[p].value)
	{
		change(idx, p);
		up(p);
	}
}

void down(int idx)
{
	int child = idx * 2;
	if (child >= (int)heap.size()) return;
	if (child + 1 < (int)heap.size() && heap[child].value > heap[child + 1].value)
		child++;

	if (heap[idx].value > heap[child].value)
	{
		change(idx, child);
		down(child);
	}
}