/*
모든 정점 => 모든 정점의 최단거리
다이나믹 기법
음수 간선 허용
음수 사이클은 허용 안 됨
*/
#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#define M 1'000'000'000
using namespace std;
int n, m, graph[101][101], a, b, c, ans = M, s = M;
int main()
{
	scanf("%d%d", &n, &m);
	fill(&graph[0][0], &graph[100][100], M);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &a, &b);
		graph[a][b] = graph[b][a] = 1;
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
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = 1; j <= n; j++) if (graph[i][j] != M) sum += graph[i][j];
		if (0 < sum && sum < s )
		{
			s = sum;
			ans = i;
		}
	}
	printf("%d", ans);
	return 0;
}
