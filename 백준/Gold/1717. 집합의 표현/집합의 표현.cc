#pragma warning(disable : 6031)

#include <stdio.h>
#define M 1000010
int p[M];
int find(int x) // 부모를 찾는다
{
	if (p[x] == x) return p[x];
	p[x] = find(p[x]);
	return p[x];
}
int main()
{

	int i, j, a, b, n, m, k, x, y;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) p[i] = i;
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &k, &a, &b);
		if (k == 0)
		{
			x = find(a);
			y = find(b);
			if (x != y)  // 다른 집합이면 합쳐준다
				p[y] = x;
		}
		else
		{
			if (find(a) == find(b)) // 같은 집합이면 yes,아니면 no 출력
				printf("YES\n");
			else
				printf("NO\n");
		}

	}
	return 0;
}