#pragma warning(disable:4996)
#include<stdio.h>
#include<vector>
#include<queue>
#define MAX 100'001
using namespace std;
int n, visit[MAX], DP[30][MAX], cnt;
vector<int> graph[MAX];
void BFS()
{
	queue<int> que;
	que.push(1);
	visit[1] = 1;

	while (!que.empty())
	{
		int node = que.front();
		que.pop();

		for (int i = 0; i < (int)graph[node].size(); i++)
		{
			int tnode = graph[node][i];
			if (visit[tnode]) continue;
			visit[tnode] = visit[node] + 1;
			DP[0][tnode] = node;
			que.push(tnode);
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		int st, ed;
		scanf("%d%d", &st, &ed);
		graph[st].push_back(ed);
		graph[ed].push_back(st);
	}
	BFS();
	for (int i = 1; i <= n; i *= 2) cnt++;

	for (int i = 1; i <= cnt; i++)
		for (int j = 1; j <= n; j++)
			DP[i][j] = DP[i - 1][DP[i - 1][j]];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int n1, n2, t = 0;
		scanf("%d%d", &n1, &n2);
		if (visit[n1] < visit[n2])
		{
			t = n1; 
			n1 = n2; 
			n2 = t;
		}

		// n1 노드는 t만큼 올라가야됨
		// 만약 t가 5일 때 이진수로 표현하면 101임
		// 4번 1번 건너뛰면 됨 (logn)
		t = visit[n1] - visit[n2];
		for (int j = 0; j <= cnt; j++)
		{
			if (t & (1 << j))
				n1 = DP[j][n1];
		}

		if (n1 == n2)
		{
			printf("%d\n", n1);
			continue;
		}

		for (int j = cnt; j >= 0; j--)
		{
			if (DP[j][n1] != DP[j][n2])
			{
				n1 = DP[j][n1];
				n2 = DP[j][n2];
			}
		}
		printf("%d\n", DP[0][n1]);
	}
	return 0;
}