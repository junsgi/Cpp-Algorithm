#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#define M 100010
using namespace std;
int check[M];
int n, m, a, ans = 1, MAX;
int arr[M];
int find(int node)
{
	if (check[node] == node)
		return check[node];
	check[node] = find(check[node]);
	return check[node];
}
void Union(int fx, int fy)
{
	if (fx < fy)
		check[fx] = fy;
	else
		check[fy] = fx;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) check[i] = i;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &a);
			if (a == 1) // 연결되어 있다면
			{
				int fx = find(i);
				int fy = find(j);
				if (fx != fy)
					Union(fx, fy);
			}
		}
	}
	for (int i = 1; i <= m; i++)
		scanf("%d", &arr[i]);
	for (int i = 2; i <= m; i++)
		if (find(arr[i - 1]) == find(arr[i])) ans++;
    
	if (ans == m) printf("YES");
	else printf("NO");
	return 0;
}
