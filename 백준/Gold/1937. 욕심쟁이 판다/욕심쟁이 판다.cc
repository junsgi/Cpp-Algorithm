#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int n, ans;
int DP[501][501], arr[501][501], dire[2][4] = { {-1, 1, 0, 0}, {0, 0, -1, 1} };
int max(int a, int b) { return a < b ? b : a; }
int min(int a, int b) { return a > b ? b : a; }

int DFS(int x, int y)
{
	if (DP[x][y])
		return DP[x][y];
	DP[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int tx = x + dire[0][i];
		int ty = y + dire[1][i];
		if (!(0 < tx && tx <= n)) continue;
		if (!(0 < ty && ty <= n)) continue;
		if (arr[x][y] >= arr[tx][ty]) continue;
		DP[x][y] = max(DP[x][y], DFS(tx, ty) + 1);
	}
	return DP[x][y];
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &arr[i][j]);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (DP[i][j] == 0)
				DFS(i, j);
			ans = max(ans, DP[i][j]);
		}
	}
	printf("%d", ans);
	return 0;
}