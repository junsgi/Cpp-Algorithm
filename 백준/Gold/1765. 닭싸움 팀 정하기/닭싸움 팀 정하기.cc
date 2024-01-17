/*
나랑 원수 사이의 친구들끼리는 서로 친한 친구임
*/
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
		graph[x].push_back(y * flag); // 원수 사이면 음수로 표현
		graph[y].push_back(x * flag);

		if (s == 'F' && find(x) != find(y)) // 친한 친구들끼리는 그룹화 한다.
			Union(x, y);
	}
	for (int i = 1; i <= n; i++) // 1번 친구부터 n번 친구까지
	{
		tmp.clear();
		for (int j = 0; j < (int)graph[i].size(); j++) 
		{
			if (graph[i][j] < 0) // 원수 친구를 만났다면 일단 저장
				tmp.push_back(-graph[i][j]);
		}
		
		for (int j = 1; j < (int)tmp.size(); j++)
			if (find(tmp[j - 1]) != find(tmp[j])) // 원수 친구들끼리는 친한 친구이니 그룹화한다.
				Union(tmp[j - 1], tmp[j]);
	}
	for (int i = 1; i <= n; i++)
		if (cnt[find(check[i])]++ == 0) ans++; // 그룹 세기
	printf("%d", ans);
	return 0;
}
