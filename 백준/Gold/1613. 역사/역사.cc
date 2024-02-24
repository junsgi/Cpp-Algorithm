#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#define M 1'000'000'000
using namespace std;
int n, m, graph[501][501], a, b, c, s;
int main()
{
	scanf("%d%d", &n, &m);
	fill(&graph[0][0], &graph[400][400], M);
	for (int i = 1; i <= n; i++)graph[i][i] = 0;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &a, &b);
		graph[a][b] = 1;
	}
	for (int c = 1; c <= n; c++)
	{
		for (int a = 1; a <= n; a++)
		{
			for (int b = 1; b <= n; b++)
			{
				if (a == b) continue;
				graph[a][b] = min(graph[a][b], graph[a][c] + graph[c][b]);
			}
		}
	}
	scanf("%d", &s);
	for (int i = 0; i < s; i++)
	{
		scanf("%d%d", &a, &b);
		if (graph[a][b] == M && graph[b][a] == M) printf("0\n");
		else if (graph[a][b] != M) printf("-1\n");
		else printf("1\n");
	}
	return 0;
}
