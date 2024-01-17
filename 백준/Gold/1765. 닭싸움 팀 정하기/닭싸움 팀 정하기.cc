#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
#define M 6000
using namespace std;
int n, m, check[M], x, y, cnt[M], ans;
vector<int> graph[M];
vector<int> tmp;
char s;
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

	if (fx > fy)
		check[fy] = fx;
	else check[fx] = fy;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) check[i] = i;
	for (int i = 0; i < m; i++)
	{
		scanf(" %c%d%d", &s, &x, &y);
		int flag = s == 'E' ? -1 : 1;
		graph[x].push_back(y * flag);
		graph[y].push_back(x * flag);

		if (s == 'F' && find(x) != find(y))
			Union(x, y);
	}
	for (int i = 1; i <= n; i++)
	{
		tmp.clear();
		for (int j = 0; j < (int)graph[i].size(); j++)
		{
			if (graph[i][j] < 0)
				tmp.push_back(-graph[i][j]);
		}
		for (int j = 1; j < (int)tmp.size(); j++)
			if (find(tmp[j - 1]) != find(tmp[j]))
				Union(tmp[j - 1], tmp[j]);
	}
	for (int i = 1; i <= n; i++)
		if (cnt[find(check[i])]++ == 0) ans++;
	printf("%d", ans);
	return 0;
}
