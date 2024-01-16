#pragma warning(disable:4996)
#include<stdio.h>
#define M 1000010
using namespace std;
int check[M];
int n, m, a, b, c, fb, fc, i;
int find(int node)
{
	if (check[node] == node)
		return check[node];
	// 경로 압축
	check[node] = find(check[node]);
	return check[node];
}
int main()
{
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) check[i] = i;
	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		if (a == 0)
		{
			fb = find(b);
			fc = find(c);
			if (b < c)
				check[fc] = fb;
			else
				check[fb] = fc;
		}
		else
		{
			if (find(b) == find(c))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}
