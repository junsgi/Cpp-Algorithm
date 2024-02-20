#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int n, arr[3001], value[3001], ins[4][3001];
int CCW(int a, int b, 
		int c, int d, 
		int e, int f)
{
	int t1 = a * d + c * f + e * b;
	int t2 = c * b + e * d + a * f;
	int res = t1 - t2;
	if (res < 0) return -1;
	if (res > 0) return 1;
	return 0;
}
int find(int node)
{
	if (arr[node] == node)
		return node;
	return arr[node] = find(arr[node]);
}
void Union(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	if (fx == fy) return;
	if (fx < fy)
	{
		arr[fy] = fx;
		value[fx] += value[fy];
	}
	else
	{
		arr[fx] = fy;
		value[fy] += value[fx];
	}
}
int check(int i, int j)
{
	int res1 = CCW(ins[0][i], ins[1][i], ins[2][i], ins[3][i], ins[0][j], ins[1][j]) *
		CCW(ins[0][i], ins[1][i], ins[2][i], ins[3][i], ins[2][j], ins[3][j]);
	int res2 = CCW(ins[0][j], ins[1][j], ins[2][j], ins[3][j], ins[0][i], ins[1][i]) *
		CCW(ins[0][j], ins[1][j], ins[2][j], ins[3][j], ins[2][i], ins[3][i]);
	if (res1 == 0 && res2 == 0)
	{
		return
			min(ins[0][i], ins[2][i]) <= max(ins[0][j], ins[2][j]) &&
			min(ins[0][j], ins[2][j]) <= max(ins[0][i], ins[2][i]) &&
			min(ins[1][i], ins[3][i]) <= max(ins[1][j], ins[3][j]) &&
			min(ins[1][j], ins[3][j]) <= max(ins[1][i], ins[3][i]);
	}
	if (res1 <= 0 && res2 <= 0) return 1;
	return 0;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		arr[i] = i;
		value[i] = 1;
		scanf("%d%d%d%d", &ins[0][i], &ins[1][i], &ins[2][i], &ins[3][i]);
	}

	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++)
			if (check(i, j))
				Union(i, j);

	int ans = 0, group = 0;
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] == i) group++;
		ans = max(ans, value[i]);
	}
	printf("%d\n%d", group, ans);
	return 0;
}
