#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m, DP[500][500];
int arr[500][500], dire[2][4] = { {-1, 1, 0, 0}, {0, 0, -1, 1} };

int DFS(int x, int y)
{
	if (DP[x][y] != -1) return DP[x][y];
	DP[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int tx = x + dire[0][i];
		int ty = y + dire[1][i];
		if (!(0 <= tx && tx < n)) continue;
		if (!(0 <= ty && ty < m)) continue;
		if (arr[x][y] <= arr[tx][ty]) continue;
		DP[x][y] += DFS(tx, ty);
	}
	return DP[x][y];
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) 
	{
		fill(DP[i], DP[i] + m, -1);
		for (int j = 0; j < m; j++)
			scanf("%d", &arr[i][j]);
	}
	DP[n - 1][m - 1] = 1;
	printf("%d", DFS(0, 0));
	return 0;
}