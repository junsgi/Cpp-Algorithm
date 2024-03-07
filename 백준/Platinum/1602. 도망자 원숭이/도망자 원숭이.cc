/*
1. 멍멍이는 지점중 한 곳에서 머무른다.
2. 원숭이는 최대한 짧은 거리로 이동
3. 멍멍이는 특정 최대한 시간이 오래 걸리게
*/
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
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		graph[a][b] = graph[b][a] = c;
	}

	// i -> j 방향으로 원숭이가 지나갈 때 
	// 가장 오랫동안 방해할 수 있는 시간 선택
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			check[i][j] = max(dog[i].first, dog[j].first);

	// 그리디 알고리즘
	// 원숭이는 늑대가 가장 적게 방해하는 지점부터 경유하여 이동한다.
	sort(dog + 1, dog + n + 1);

	// 플로이드 워셜
	// 원숭이는 최대한 짧은 거리로만 이동
	// 원숭이 이동 경로에 항상 멍멍이가 괴롭힐 수 있는 최악의 시간으로 계산
	for (int k = 1; k <= n; k++)
	{
		// 멍멍이 위치
		int tran = dog[k].second;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				// 경유하는 곳이 같다면 continue
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
