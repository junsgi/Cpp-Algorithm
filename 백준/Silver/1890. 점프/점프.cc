#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int n, graph[100][100], dire[2][2] = { {1, 0}, {0, 1} };
unsigned long long visit[100][100];
unsigned long long DFS(int x, int y)
{
	if (visit[x][y] != -1) return visit[x][y];
	visit[x][y] = 0;
	for (int i = 0; i < 2; i++)
	{
		int tx = x + dire[0][i] * graph[x][y];
		int ty = y + dire[1][i] * graph[x][y];
		if (!(0 <= tx && tx < n)) continue;
		if (!(0 <= ty && ty < n)) continue;
		visit[x][y] += DFS(tx, ty);
	}
	return visit[x][y];
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &graph[i][j]);

	fill(&visit[0][0], &visit[99][99], -1);
	visit[n - 1][n - 1] = 1;
	printf("%lld", DFS(0, 0));
	return 0;
}