#pragma warning(disable:4996)
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int v, e, start, st, ed, c, len, visit[20001], MAX = 0x7fffffff / 2;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
vector<pair<int, int>> map[20010];
void up(int idx, pair<int, int> heap[])
{
	if (idx / 2 <= 0) return;
	if (heap[idx].first < heap[idx / 2].first)
	{
		pair<int, int> tmp = heap[idx];
		heap[idx] = heap[idx / 2];
		heap[idx / 2] = tmp;
		up(idx / 2, heap);
	}
}
void down(int idx, pair<int, int> heap[])
{
	if (idx * 2 > len) return;

	int child;
	if (heap[idx * 2].first < heap[idx * 2 + 1].first)
		child = idx * 2;
	else
		child = idx * 2 + 1;

	if (heap[idx].first > heap[child].first)
	{
		pair<int, int> tmp = heap[idx];
		heap[idx] = heap[child];
		heap[child] = tmp;
		down(child, heap);
	}
}
void dijstra()
{
	for (int i = 1; i <= v; i++) visit[i] = MAX;
	visit[start] = 0;
	//heap[++len] = { 0, start };up(len);
	heap.push({ 0, start });
	

	while (!heap.empty())
	{
		pair<int, int> tmp = heap.top();
		heap.pop();
		//heap[1] = heap[len--];
		//down(1);

		int cost, node;
		cost = tmp.first;
		node = tmp.second;
		if (visit[node] < cost) continue;

		for (int i = 0; i < (int)map[node].size(); i++)
		{
			if (visit[map[node][i].second] > visit[node] + map[node][i].first)
			{
				visit[map[node][i].second] = visit[node] + map[node][i].first;
				//heap[++len] = { visit[map[node][i].second], map[node][i].second };
				heap.push({ visit[map[node][i].second], map[node][i].second });
				//up(len);
			}
		}
	}
}

int main()
{
	scanf("%d%d%d", &v, &e, &start);
	for (int i = 0; i < e; i++)
	{
		scanf("%d%d%d", &st, &ed, &c);
		map[st].push_back(make_pair(c, ed));
	}
	dijstra();
	for (int i = 1; i <= v; i++)
	{
		if (visit[i] >= MAX) printf("INF\n");
		else printf("%d\n", visit[i]);
	}
	return 0;
}
