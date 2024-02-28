#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
struct temp {
	int num, value, sweeping;
};
int n, m, a, b, c, p[100'001];
vector<temp> arr;
int cmp(temp x, temp y)
{
	return x.value < y.value || (x.value == y.value && x.sweeping > y.sweeping);
}
int find(int node)
{
	if (p[node] == node) return node;
	return p[node] = find(p[node]);
}
void Union(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	if (fx == fy) return;
	if (fx < fy) p[fy] = fx;
	else p[fx] = fy;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i++) p[i] = i;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		arr.push_back({ i, a, 1 });
		arr.push_back({ i, b, -1 });

	}
	sort(arr.begin(), arr.end(), cmp);
	int sum = 1;
	for (int i = 1; i < (int)arr.size(); i++)
	{
		sum += arr[i].sweeping;
		if (sum > 1)
			Union(arr[i].num, arr[i - 1].num);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &a, &b);
		if (find(a) != find(b)) printf("0\n");
		else printf("1\n");
	}
	return 0;
}