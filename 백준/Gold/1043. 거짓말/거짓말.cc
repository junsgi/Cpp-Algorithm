#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#define M 100
using namespace std;
int check[M];
int n, m, f, ans, tmp, know;
int arr[51][M];
int find(int node)
{
	if (check[node] == node)
		return check[node];
	check[node] = find(check[node]);
	return check[node];
}
void Union(int fx, int fy)
{
	if (fx == fy) return;

	if (fx > fy)
		check[fy] = fx;
	else check[fx] = fy;
}
int main()
{
	scanf("%d%d%d", &n, &m, &f);
	for (int i = 1; i <= n; i++) check[i] = i;

	for (int i = 0; i < f; i++)
	{
		scanf("%d", &arr[0][i]);
		know = arr[0][i];
		if (i > 0)
			Union(find(arr[0][i]), find(arr[0][i - 1]));
	}



	bool swi = false;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &arr[i][0]);
		swi = false;
		for (int j = 1; j <= arr[i][0]; j++)
		{
			scanf("%d", &arr[i][j]);
			if (!swi && find(know) == find(arr[i][j]))
				swi = true;
		}

		for (int j = 1; j <= arr[i][0]; j++)
		{
			if (!swi && j >= 2) // 진실을 모르는 사람들끼리 묶음
				Union(find(arr[i][j - 1]), find(arr[i][j]));
			else if (swi) // 진실을 아는 사람들 그룹에 포함시킨다.
				Union(find(know), find(arr[i][j]));
		}
	}
	for (int i = 0; i < m; i++)
	{
		swi = false;
		for (int j = 1; j <= arr[i][0]; j++)
		{
			if (find(know) == find(arr[i][j]))
			{
				swi = true;
				break;
			}
		}
		if (!swi)ans++;
	}
	printf("%d", ans);
	return 0;
}