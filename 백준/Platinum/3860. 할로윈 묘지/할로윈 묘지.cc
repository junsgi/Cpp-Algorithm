#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
#define M 1'000'000'000
using namespace std;
struct temp {
	long long st, ed, cost;
};
int n, m, g, t, a, b, c, d, e, graph[50][50], freq[50][50];
int dire[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
long long visit[1000];
vector<temp> arr;
int BellmanFord()
{
	visit[1] = 0;
	int res = 0;
	for (int i = 0; i < n * m; i++)
	{
		res = 0;
		for (int j = 0; j < (int)arr.size(); j++)
		{
			if (visit[arr[j].st] == M) continue;
			if (visit[arr[j].ed] > visit[arr[j].st] + arr[j].cost)
			{
				res = 1;
				visit[arr[j].ed] = visit[arr[j].st] + arr[j].cost;
			}
		}
	}
	return res;
}
int main()
{
	while (1)
	{
		scanf("%d%d", &n, &m);
		if (!(n + m)) break;
		for (int i = 0; i < 1000; i++)visit[i] = M;
		fill(&freq[0][0], &freq[49][49], 0);
		arr.clear();
		int cnt = 1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				graph[i][j] = cnt++;

		scanf("%d", &g);
		for (int i = 0; i < g; i++)
		{
			scanf("%d%d", &a, &b);
			graph[a][b] = 0;
		}
		scanf("%d", &t);
		for (int i = 0; i < t; i++)
		{
			scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
			freq[a][b] = 1;
			arr.push_back({ graph[a][b], graph[c][d], e });
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (freq[i][j]) continue;
				if (graph[i][j] == n * m) continue;
				if (!graph[i][j])continue;
				for (int k = 0; k < 4; k++)
				{
					int tx = dire[k][0] + i;
					int ty = dire[k][1] + j;
					if (!(0 <= tx && tx < n)) continue;
					if (!(0 <= ty && ty < m)) continue;
					if (!graph[tx][ty]) continue;
					arr.push_back({ graph[i][j], graph[tx][ty], 1 });
				}
			}
		}
		if (BellmanFord()) printf("Never\n");
		else visit[n * m] == M ? printf("Impossible\n") : printf("%lld\n", visit[n * m]);
	}
	return 0;
}
