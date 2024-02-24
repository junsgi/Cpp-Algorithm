#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#define M 1'000'000'000
using namespace std;
int n, m, graph[501][501], a, b, c, ans = M;
int main()
{
	scanf("%d%d", &n, &m);
	fill(&graph[0][0], &graph[500][500], M);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		graph[a][b] = c;
	}
	for (int c = 1; c <= n; c++)
	{
		for (int a = 1; a <= n; a++)
		{
			for (int b = 1; b <= n; b++)
			{
				graph[a][b] = min(graph[a][b], graph[a][c] + graph[c][b]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
		ans = min(ans, graph[i][i]);
	if (ans == M)
		ans = -1;
	printf("%d", ans);
	return 0;
}
