#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m, visit[1001], gender[1001], st, ed, c, ans[1001], check[1001], cnt;
char g;
struct temp {
	int st, ed, cost;
}arr[10001];
int cmp(temp x, temp y) {
	return x.cost < y.cost;
}
int find(int x)
{
	if (visit[x] == x) return x;
	return visit[x] = find(visit[x]);
}
void Union(int x, int y, int value)
{
	int fx = find(x);
	int fy = find(y);
	if (fx == fy) return;

	if (fx < fy)
	{
		visit[fy] = fx;
		ans[fx] = value + ans[fx] + ans[fy];
	}
	else
	{
		visit[fx] = fy;
		ans[fy] = value + ans[fy] + ans[fx];
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) 
	{
		visit[i] = i;
		scanf(" %c", &g);
		if (g == 'M')
			gender[i] = 1;
		else
			gender[i] = -1;
	}
	for (int i = 0; i < m; i++)
		scanf("%d%d%d", &arr[i].st, &arr[i].ed, &arr[i].cost);
	sort(arr, arr + m, cmp);
	for (int i = 0; i < m; i++)
	{
		if (gender[arr[i].st] != gender[arr[i].ed])
		{
			Union(arr[i].st, arr[i].ed, arr[i].cost);
			if (check[arr[i].st]++ == 0)cnt++;
			if (check[arr[i].ed]++ == 0)cnt++;
		}
	}
	if (cnt != n)
		printf("-1");
	else printf("%d", ans[1]);
	return 0;
}
