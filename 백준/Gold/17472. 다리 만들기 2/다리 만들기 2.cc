#pragma warning(disable:4996)
#include <stdio.h>
#include <queue>
using namespace std;
int n, m, graph[15][15], visit[15][15], dire[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int map[101][101], MAX = 0x7fffffff, ans, nodeLen;
int cost[101], freq[101];
struct temp 
{
	int x, y, area;
};
struct result {
	int cnt, area;
};
queue<temp> que;
int MIN(int a, int b) { return a < b ? a : b; }

pair<result, result> draw(int x, int y)
{
	int vx, vy, hx, hy, area = graph[x][y];
	bool v = true, h = true;
	result vr = {}, hr = {};
	vx = hx = x; vy = hy = y;
	vx += 1; hy += 1;

	while (v || h)
	{
		if (v && 0 <= vx && vx < n)
		{
			if (graph[vx][y] == 0) vr.cnt++;
			else if (graph[vx][y] != area)
			{
				vr.area = graph[vx][y];
				if (vr.cnt < 2) vr.cnt = MAX;
				v = false;
			}
			else v = false;
			vx++;
		}
		else
			v = false;

		if (h && 0 <= hy && hy < m)
		{
			if (graph[x][hy] == 0) hr.cnt++;
			else if (graph[x][hy] != area)
			{
				hr.area = graph[x][hy];
				if (hr.cnt < 2) hr.cnt = MAX;
				h = false;
			}
			else h = false;
			hy++;
		}
		else
			h = false;
	}
	if (vr.cnt <= 1 || vr.area == 0) vr.cnt = MAX;
	if (hr.cnt <= 1 || hr.area == 0) hr.cnt = MAX;
	return {vr, hr};
}

void DFS(int x, int y, int area)
{
	if (!(0 <= x && x < n && 0 <= y && y < m) ||
		visit[x][y] == 1 ||
		graph[x][y] == 0) return;
	
	visit[x][y] = 1;
	graph[x][y] = area;
	for (int i = 0; i < 4; i++)
		DFS(x + dire[i][0], y + dire[i][1], area);
}

void prim()
{
	int node = 1, min = MAX, tnode = -1;
	freq[1] = 1;
	for (int i = 1; i <= nodeLen; i++)
	{
		cost[i] = map[1][i];
		if (!freq[i] && min > cost[i])
		{
			min = cost[i];
			node = i;
		}
	}
	for (int i = 1; i < nodeLen; i++)
	{
        if (node == -1)
		{
			ans = -1;
			return;
		}
		min = MAX; ans += cost[node]; freq[node] = 1;tnode = -1;

		for (int j = 1; j <= nodeLen; j++)
		{
			if (node != j && !freq[j])
			{
				if (cost[j] > map[node][j])
					cost[j] = map[node][j];

				if (min > cost[j])
				{
					min = cost[j];
					tnode = j;
				}
			}
		}
		node = tnode;
        
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &graph[i][j]);
	int area = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (graph[i][j] == 1 && !visit[i][j])
				DFS(i, j, area++);

	nodeLen = area - 1;
	for (int i = 1; i <= nodeLen; i++)
		for (int j = 1; j <= nodeLen; j++)
			if (i != j) map[i][j] = MAX;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) 
		{
			if (graph[i][j] != 0)
			{
				pair<result, result> res = draw(i, j);
				if (map[graph[i][j]][res.first.area] > res.first.cnt)
					map[graph[i][j]][res.first.area] = map[res.first.area][graph[i][j]] = res.first.cnt;

				if (map[graph[i][j]][res.second.area] > res.second.cnt)
					map[graph[i][j]][res.second.area] = map[res.second.area][graph[i][j]] = res.second.cnt;
			}
		}
	}
	prim();
	printf("%d", ans == 0 ? -1 : ans);

	return 0;
}
