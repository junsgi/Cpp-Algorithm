#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include<algorithm>
#define MAX(x,y)((x)<(y)?(y):(x))
using namespace std;
int dire[2][4] = { {-1, 1, 0, 0}, {0, 0, -1, 1} };
int n, m, k, DP[101][101][101], ans;
string graph[101], word;
int DFS(int x, int y, int idx)
{
	if (idx == word.size()) return DP[idx][x][y] = 1;
	if (DP[idx][x][y] != -1) return DP[idx][x][y];
	DP[idx][x][y] = 0;

	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int tx = x + dire[0][j] * i;
			int ty = y + dire[1][j] * i;
			if (!(0 <= tx && tx < n)) continue;
			if (!(0 <= ty && ty < m)) continue;
			if (graph[tx][ty] != word[idx]) continue;
			DP[idx][x][y] += DFS(tx, ty, idx + 1);
		}
	}
	return DP[idx][x][y];
}
int main()
{
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
		cin >> graph[i];
	cin >> word;
	fill(&DP[0][0][0], &DP[100][100][100], -1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (graph[i][j] == word[0])
			{
				ans += DFS(i, j, 1);
			}
		}
	}
	printf("%d", ans);
	return 0;
}