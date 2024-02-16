#pragma warning(disable:4996)
#include<stdio.h>
#include<vector>
#include<queue>
#define MAX(x, y)( ((x)>(y)) ? (x) : (y) )
#define MIN(x, y)( ((x)<(y)) ? (x) : (y) )
#define M 0x7fffffff
using namespace std;
typedef pair<int, int> g;
struct q {
	int node, jew, cnt;
};
int n, m, k, J[101], visit[1 << 15][101];
vector<g> graph[1001];
queue<q> que;

int BFS()
{
	int ans = 0;
	que.push({ 1, 0, 0 });
	visit[0][1] = 1;

	if (J[1])
	{
		que.push({ 1, 1 << J[1], 1});
		visit[1 << J[1]][1] = 1;
	}
	while (!que.empty())
	{
		q tmp = que.front(); que.pop();
		int node = tmp.node;
		int jew = tmp.jew;
		int cnt = tmp.cnt;
		if (node == 1)
			ans = MAX(ans, cnt);
		for (int i = 0; i < (int)graph[node].size(); i++)
		{
			int tnode = graph[node][i].first;
			int limit = graph[node][i].second;
			if (cnt > limit) continue;

			// 보석을 줍는다.
			if (J[tnode] && !visit[jew | (1 << J[tnode])][tnode])
			{
				visit[jew | (1 << J[tnode])][tnode] = 1;
				que.push({ tnode, jew | (1 << J[tnode]), jew & (1 << J[tnode]) ? cnt : cnt + 1});
			}
			// 안 줍는다.
			if (!visit[jew][tnode])
			{
				visit[jew][tnode] = 1;
				que.push({ tnode, jew, cnt });
			}
		}
	}
	return ans;
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; i++)
	{
		int t;
		scanf("%d", &t);
		J[t] = i + 1;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}
	printf("%d", BFS());
	return 0;
}