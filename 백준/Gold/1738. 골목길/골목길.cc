#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
#define M -1'000'000'000
using namespace std;
struct temp {
	int st, ed, cost;
}arr[20000];
int n, m, path[111], que[101], check[101], st = -1, ed = -1;
long long cost[1000];
vector<int> graph[111];
int BellmanFord()
{
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (cost[arr[j].st] == M) continue;
			if (cost[arr[j].ed] < cost[arr[j].st] + arr[j].cost)
			{
				cost[arr[j].ed] = cost[arr[j].st] + arr[j].cost;
				path[arr[j].ed] = arr[j].st;
				if (i == n - 1 && check[arr[j].ed]) res = 1; // 마지막에 영향을 주는 지점의 값이 바뀐다면 도착할 수 없음
			}
		}
	}
	return res;
}
void BFS() // 콘도에서부터 시작하여 시작점과 콘도사이에 영향을 주는 지점만 체크
{
    que[++ed] = n;
	check[n] = 1;
	while (st != ed)
	{
		int node = que[++st];
		for (int i = 0; i < (int)graph[node].size(); i++)
		{
			if (check[graph[node][i]])continue;
			que[++ed] = graph[node][i];
			check[que[ed]] = 1;
		}
	}
}
void d(int node)
{
	if (path[node] == -1)
	{
		printf("%d ", node);
		return;
	}
	d(path[node]);
	printf("%d ", node);
}
int main()
{
	scanf("%d%d", &n, &m);
	path[1] = -1;
	for (int i = 2; i <= n; i++) cost[i] = M;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &arr[i].st, &arr[i].ed, &arr[i].cost);
		graph[arr[i].ed].push_back(arr[i].st);
	}
	BFS();
	if (BellmanFord() || cost[n] == M) printf("-1");
	else d(n);
	return 0;
}
