#pragma warning(disable:4996)
#include<stdio.h>
#include<vector>
#define M 30'001
#define MAX(x,y) (((x)>(y)) ? (x):(y))
#define MIN(x,y) (((x)>(y)) ? (y):(x))
using namespace std;
int n, m, t, st, ed, depth[M], visit[17][M], ans, que[M], DP[17][M];
int cnt;
vector<int> graph[M], arr;
void BFS()
{
	st = ed = -1;
	que[++ed] = 1;
	visit[0][1] = 1;
	while (st != ed)
	{
		int node = que[++st];
		for (int i = 0; i < (int)graph[node].size(); i++)
		{
			int tnode = graph[node][i];
			if (visit[0][tnode])continue;
			visit[0][tnode] = 1;
			depth[tnode] = depth[node] + 1;
			DP[0][tnode] = node;
			que[++ed] = tnode;
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d%d", &st, &ed);
		graph[st].push_back(ed);
		graph[ed].push_back(st);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &st);
		arr.push_back(st);
	}

	BFS();
	for (int i = 1; i < n; i *= 2) cnt++;
	visit[0][1] = 0;
	for (int i = 1; i <= cnt; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			DP[i][j] = DP[i - 1][DP[i - 1][j]];
			visit[i][j] = visit[i - 1][j] + visit[i - 1][DP[i - 1][j]];
		}
	}
	for (int i = 1 ; i < m ; i++)
	{
		int n1 = arr[i - 1];
		int n2 = arr[i];
		if (depth[n1] < depth[n2]) { t = n1; n1 = n2; n2 = t; }

		int jump = depth[n1] - depth[n2];
		// n1 점프
		for (int j = cnt; j >= 0; j--)
		{
			if (jump & (1 << j))
			{
				ans += visit[j][n1];
				n1 = DP[j][n1];
			}
		}

		for (int j = cnt; j >= 0; j--)
		{
			if (DP[j][n1] != DP[j][n2])
			{
				ans += visit[j][n1];
				ans += visit[j][n2];
				n1 = DP[j][n1];
				n2 = DP[j][n2];
			}
		}
		if (n1 != n2)
			ans += visit[0][n1] + visit[0][n2];
	}
	printf("%d", ans);
	return 0;
}