/*
1. 가장 큰 가중치와 두 번째로 큰 가중치를 구하여 정답을 갱신
2. 부모는 가장 큰 가중치만 사용하여 계산한다.
*/
#pragma warning(disable:4996)
#include<stdio.h>
#include<vector>
#define M 100'001
#define MAX(x,y) (((x)>(y)) ? (x):(y))
using namespace std;
int n, st, ed, c, visit[M], value[M], ans;
vector<pair<int, int>> graph[M];
void DFS(int node)
{
	visit[node] = 1;
	int first = 0, fn = 0, second = 0, sn = 0;
	for (int i = 0; i < (int)graph[node].size(); i++)
	{
		int tnode = graph[node][i].first;
		int tcost = graph[node][i].second;
		if (visit[tnode]) continue;
		DFS(tnode);
		if (first < value[tnode] + tcost)
		{
			if (first)
			{
				second = first;
				sn = fn;
			}
			first = value[tnode] + tcost;
			fn = tnode;
		}
		else if (second < value[tnode] + tcost)
		{
			second = value[tnode] + tcost;
			sn = tnode;
		}
	}
	ans = MAX(ans, first + second);
	value[node] = first;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d%d%d", &st, &ed, &c);
		graph[st].push_back({ ed, c });
		graph[ed].push_back({ st, c });
	}
	DFS(1);
	printf("%d", ans);
	return 0;
}
