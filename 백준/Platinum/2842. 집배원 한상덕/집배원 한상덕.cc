#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#define M 1'000'000'000
using namespace std;
typedef pair<int, int> pii;
int n, sx, sy, height[50][50], box, visit[50][50], ans = M;
int dire[2][8] = { {-1, -1, -1, 0, 1, 1, 1, 0}, {-1, 0, 1, 1, 1, 0, -1, -1} };
int a = M, b = M;
char map[50][50];
queue<pii> que;
vector<int> arr;
int BFS(int s, int e)
{
	if (!(s <= height[sx][sy] && height[sx][sy] <= e))return 0;
	fill(&visit[0][0], &visit[49][49], 0);
	que = queue<pii>();
	que.push({ sx, sy });
	visit[sx][sy] = 1;
	int cnt = 0;
	int MIN = M, MAX = 0;
	while (!que.empty())
	{
		pii tmp = que.front(); que.pop();
		int x = tmp.first;
		int y = tmp.second;
		MIN = min(MIN, height[x][y]);
		MAX = max(MAX, height[x][y]);
		for (int i = 0; i < 8; i++)
		{
			int tx = x + dire[0][i];
			int ty = y + dire[1][i];
			if (!(0 <= tx && tx < n && 0 <= ty && ty < n)) continue;
			if (visit[tx][ty]) continue;
			if (!(s <= height[tx][ty] && height[tx][ty] <= e)) continue;
			if (map[tx][ty] == 'K') cnt++;
			MIN = min(MIN, height[tx][ty]);
			MAX = max(MAX, height[tx][ty]);
			if (cnt == box)
			{
				ans = min(ans, MAX - MIN);
				return 1;
			}
			que.push({ tx, ty });
			visit[tx][ty] = 1;
		}
	}
	return 0;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'P')
			{
				sx = i; sy = j;
			}
			if (map[i][j] == 'K') box++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &height[i][j]);
			arr.push_back(height[i][j]);
		}
	}
	sort(arr.begin(), arr.end());
	int left = 0, right = 1, LEN = (int)arr.size();
	while (left < LEN && right < LEN)
	{
		// 모두 배달했다면 최소 최대간격을 줄인다.
		if (BFS(arr[left], arr[right])) left++;
		else right++;;
	}
	printf("%d", ans);
	return 0;
}
