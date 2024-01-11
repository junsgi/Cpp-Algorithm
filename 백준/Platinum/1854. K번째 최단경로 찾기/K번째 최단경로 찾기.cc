#pragma warning(disable:4996)
#include<stdio.h>
#include<vector>
using namespace std;
int len, v, e, k;
long long MAX = 0x7fffffff, visit[1001];
vector<pair<int, int>> graph[10001];
vector<long long> result[1001];
pair<int, long long> heap[4'000'000];

void up(int idx)
{
	if (idx / 2 <= 0) return;
	
	if (heap[idx].second < heap[idx / 2].second)
	{
		pair<int, long long> tmp = heap[idx];
		heap[idx] = heap[idx / 2];
		heap[idx / 2] = tmp;
		up(idx / 2);
	}
}
void down(int idx)
{
	if (idx * 2 > len) return;
	int child = idx * 2;
	if (child + 1 <= len && heap[child].second > heap[child + 1].second)
		child++;
	if (heap[idx].second > heap[child].second)
	{
		pair<int, long long> tmp = heap[idx];
		heap[idx] = heap[child];
		heap[child] = tmp;
		down(child);
	}
}

void up2(int idx, vector<long long> &heap)
{
	if (idx / 2 <= 0) return;
	
	if (heap[idx] > heap[idx / 2])
	{
		long long tmp = heap[idx];
		heap[idx] = heap[idx / 2];
		heap[idx / 2] = tmp;
		up2(idx / 2, heap);
	}
}

void down2(int idx, vector<long long> &heap, int size)
{
	if (idx * 2 > size) return;
	int child = idx * 2;
	if (child + 1 <= size && heap[child] < heap[child + 1])
		child++;

	if (heap[idx] < heap[child])
	{
		long long tmp = heap[idx];
		heap[idx] = heap[child];
		heap[child] = tmp;
		down2(child, heap, size);
	}
}
void dijkstra()
{
	for (int i = 1; i <= v; i++)
		result[i].push_back(0);
	result[1].push_back(0);

	heap[++len] = { 1, 0 };
	up(len);

	while (len)
	{
		pair<int, long long> tmp = heap[1];
		heap[1] = heap[len--];
		down(1);

		int cur_node = tmp.first;
		long long cur_cost = tmp.second;
		for (int i = 0; i < (int)graph[cur_node].size(); i++)
		{
			int next_node = graph[cur_node][i].first;
			long long new_cost = (long long)graph[cur_node][i].second + cur_cost;		
			int rlen = result[next_node].size() - 1;

			if (rlen < k)
			{
				heap[++len] = { next_node, new_cost };
				up(len);

				result[next_node].push_back(new_cost);
				up2(rlen + 1, result[next_node]);
			}
			else if (result[next_node][1] > new_cost)
			{
				heap[++len] = { next_node, new_cost };
				up(len);

				result[next_node][1] = result[next_node][rlen];
				result[next_node][rlen] = -MAX;
				down2(1, result[next_node], rlen);


				result[next_node].push_back(new_cost);
				up2(rlen + 1, result[next_node]);
			}
		}
	}
}
int main()
{
	scanf("%d%d%d", &v, &e, &k);
	for (int i = 0; i < e; i++)
	{
		int st, ed, co;
		scanf("%d%d%d", &st, &ed, &co);
		graph[st].push_back({ ed, co });
	}
	dijkstra();
	for (int i = 1; i <= v; i++)
	{
		int cnt = 0, rlen = (int)result[i].size() - 1;
		long long ans = -1;
		if (rlen >= k)
			ans = result[i][1];
		printf("%lld\n", ans);
	}
	return 0;
}