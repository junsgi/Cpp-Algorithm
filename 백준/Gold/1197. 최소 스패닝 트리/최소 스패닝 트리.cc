#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#define M 100010
using namespace std;
int check[M];
int n, m, a, b, c;
long long ans;
struct temp {
	int st, ed, cost;
}t;
temp arr[M];
int cmp(temp x, temp y) { return x.cost < y.cost; }
int find(int node)
{
	if (check[node] == node)
		return check[node];
	check[node] = find(check[node]);
	return check[node];
}
void Union(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	if (fx < fy)
		check[fx] = fy;
	else
		check[fy] = fx;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) check[i] = i;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		arr[i] = { a, b, c };
	}
	sort(arr, arr + m, cmp);
	for (int i = 0; i < m; i++)
	{
		int st = arr[i].st;
		int ed = arr[i].ed;
		int cost = arr[i].cost;
		if (find(st) != find(ed))
		{
			Union(st, ed);
			ans += cost;
		}
	}
	printf("%lld", ans);
	return 0;
}
