/*
희소배열 
2의 멱승 단위로 부모의 정보를 저장
[0] 부모
[1] 부모의 부모
[2] 부모의 ** 2
[3] 부모의 ** 3
*/
#pragma warning(disable:4996)
#include<stdio.h>
#include<vector>
#include<queue>
#define M 100'001
using namespace std;
int n, visit[M], energy[M], weight[20][M];
int DP[20][M], cnt;
vector<pair<int, int>> graph[M];
queue<int> que;
int MAX(int a, int b) { return a < b ? b : a; }
void BFS()
{
	visit[1] = 1;
	que.push(1);

	while (!que.empty())
	{
		int node = que.front();
		que.pop();

		for (int i = 0; i < (int)graph[node].size(); i++)
		{
			int tnode = graph[node][i].first;
			int tcost = graph[node][i].second;
			if (visit[tnode]) continue;
			DP[0][tnode] = node;
			weight[0][tnode] = tcost;
			visit[tnode] = visit[node] + 1;
			que.push(tnode);
		}
	}

}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &energy[i]);
	for (int i = 0; i < n - 1; i++)
	{
		int st, ed, c;
		scanf("%d%d%d", &st, &ed, &c);
		graph[st].push_back({ ed, c });
		graph[ed].push_back({ st, c });
	}
	BFS();
	
	for (int k = 1; k <= n; k *= 2) cnt++;

	// 희소배열 생성
	for (int i = 1; i <= cnt ; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			// 부모의 * (2 ^ i)를 구함
			DP[i][j] = DP[i - 1][DP[i - 1][j]];

			// 부모의 * (2 ^ i)까지 가는데 가중치
			weight[i][j] = weight[i - 1][j] + weight[i - 1][DP[i - 1][j]];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		int u = i;
		for (int j = cnt; j >= 0; j--)
		{
			// i번 개미가 2 ^ j 번째 부모까지 갈 수 있다면
			if (energy[i] >= weight[j][u])
			{
				energy[i] -= weight[j][u]; // 에너지 감소
				u = DP[j][u]; // 위치 이동
			}
		}
		if (u == 0) u++;
		printf("%d\n", u);
	}
	return 0;
}