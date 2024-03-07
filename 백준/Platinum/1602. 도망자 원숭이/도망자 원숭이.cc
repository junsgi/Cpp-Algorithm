#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
#define M 1'000'000'000
using namespace std;
int n, m, t;
int graph[501][501], check[501][501];
pair<int, int> dog[501];
int main()
{
	scanf("%d%d%d", &n, &m, &t);
	fill(&graph[0][0], &graph[500][500], M);
	for (int i = 0; i <= n; i++) graph[i][i] = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &dog[i].first);
		dog[i].second = i;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			check[i][j] = max(dog[i].first, dog[j].first);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		graph[a][b] = graph[b][a] = c;
	}
	sort(dog + 1, dog + n + 1);
	for (int k = 1; k <= n; k++)
	{
		int tran = dog[k].second;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == tran || j == tran) continue;
				if (graph[i][j] + check[i][j] > graph[i][tran] + graph[tran][j] + max(check[i][tran], check[tran][j]))
				{
					graph[i][j] = graph[i][tran] + graph[tran][j];
					check[i][j] = max(check[i][tran], check[tran][j]);
				}
			}
		}
	}
	for (int i = 0; i < t; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (graph[a][b] == M) printf("-1\n");
		else printf("%d\n", graph[a][b] + check[a][b]);
	}
	return 0;
}