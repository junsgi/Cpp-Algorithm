#pragma warning(disable:4996)
#include<stdio.h>
#include<queue>
#include<vector>
#define M 100'001
#define MIN(x,y) (((x)>(y)) ? (y):(x))
#define MAX(x,y) (((x)>(y)) ? (x):(y))
using namespace std;
int n, a, b, cnt, m, t, res1, res2;
int DP[18][M], Max[18][M], Min[18][M], depth[M];
vector<pair<int, int>> graph[M];
queue<int> que;
void BFS()
{
	que.push(1);
	depth[1] = 1;

	while (!que.empty())
	{
		int node = que.front();
		que.pop();

		for (int i = 0; i < (int)graph[node].size(); i++)
		{
			int tnode = graph[node][i].first;
			int tcost = graph[node][i].second;
			if (depth[tnode]) continue;
			depth[tnode] = depth[node] + 1;
			DP[0][tnode] = node;
			Max[0][tnode] = Min[0][tnode] = tcost;
			que.push(tnode);
		}
	}
}
int main()
{
	fill(&Min[0][0], &Min[17][M - 1], 2'000'000);
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d%d%d", &a, &b, &cnt);
		graph[a].push_back({ b, cnt });
		graph[b].push_back({ a, cnt });
	}
	BFS();
	cnt = 0;
	for (int i = 1; i <= n; i *= 2) cnt++;

	for (int i = 1; i <= cnt; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			DP[i][j] = DP[i - 1][DP[i - 1][j]];
			Max[i][j] = MAX(Max[i - 1][j], Max[i - 1][DP[i - 1][j]]);
			Min[i][j] = MIN(Min[i - 1][j], Min[i - 1][DP[i - 1][j]]);
		}
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		res1 = 2'000'000;
		res2 = 0;
		scanf("%d%d", &a, &b);
		if (depth[a] < depth[b])
		{
			t = a;
			a = b;
			b = t;
		}
		int jump = depth[a] - depth[b];

		for (int i = cnt; i >= 0; i--)
		{
			if (jump & (1 << i))
			{
				res1 = MIN(res1, Min[i][a]);
				res2 = MAX(res2, Max[i][a]);
				a = DP[i][a];
			}
		}

		for (int i = cnt; a != b && i >= 0; i--)
		{
			if (DP[i][a] != DP[i][b])
			{
				res1 = MIN(res1, MIN(Min[i][a], Min[i][b]));
				res2 = MAX(res2, MAX(Max[i][a], Max[i][b]));
				a = DP[i][a];
				b = DP[i][b];
			}
		}
		if (a != b)
		{
			res1 = MIN(res1, MIN(Min[0][a], Min[0][b]));
			res2 = MAX(res2, MAX(Max[0][a], Max[0][b]));
		}
		printf("%d %d\n", res1, res2);
	}
	return 0;
}