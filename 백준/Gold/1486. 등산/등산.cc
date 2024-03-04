#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#define M (long long)100'000'000'000
using namespace std;
typedef long long ll;
int n, m, T, D, LEN, map[30][30], ans, dire[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
ll graph[26 * 26][26 * 26];
int main()
{
	scanf("%d%d%d%d", &n, &m, &T, &D);

	LEN = n * m;
	fill(&graph[0][0], &graph[666][666], M);
	for (int i = 0; i <= 25 * 25; i++) graph[i][i] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char temp;
			scanf(" %c", &temp);
			if (temp <= 'Z') map[i][j] = temp - 'A';
			else map[i][j] = temp - 'a' + 26;
			map[i][j] += (i * m + j) * 100;
		}
	}
	for (int i = 0; i < n; i++) // 그래프 구현
	{
		for (int j = 0; j < m; j++)
		{
			int node = map[i][j] / 100 + 1;
			int cost = map[i][j] % 100;
			for (int d = 0; d < 4; d++)
			{
				int tx = dire[d][0] + i;
				int ty = dire[d][1] + j;
				if (!(0 <= tx && tx < n)) continue;
				if (!(0 <= ty && ty < m)) continue;
				int tnode = map[tx][ty] / 100 + 1;
				int tcost = map[tx][ty] % 100;
				if (abs(cost - tcost) > T) continue;
				if (cost < tcost) graph[node][tnode] = (ll)((tcost - cost) * (tcost - cost));
				else graph[node][tnode] = 1;

			}
		}
	}

	for (int k = 1; k <= LEN; k++)
		for (int i = 1; i <= LEN; i++)
			for (int j = 1; j <= LEN; j++)
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]); // 모든 지점에서 모든 지점까지의 최소 시간을 구함
	for (int i = 1; i <= LEN; i++)
	{
		if (graph[1][i] == M || graph[i][1] == M) continue; // 갈 수 없는 곳이라면
		if (graph[1][i] + graph[i][1] <= D) // 갈 수 있는 거리라면
			ans = max(ans, map[(i - 1) / m][(i - 1) % m] % 100);
	}
	printf("%d", ans);
	return 0;
}
