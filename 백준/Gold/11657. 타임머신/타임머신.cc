/*
순회를 총 V - 1번하면 최단거리가 구해짐
마지막으로 한 번 순회했을 때 값이 달라진다면 음수 사이클 존재

*/
#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
struct temp {
	long long st, ed, cost;
}arr[6000];
int n, m, a, b, c;
long long visit[501], MAX = 1'000'000'000;
int BellmanFord()
{
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		res = 1;
		for (int j = 0; j < m; j++)
		{
			if (visit[arr[j].st] == MAX) continue;
			if (visit[arr[j].ed] > visit[arr[j].st] + arr[j].cost)
			{
				visit[arr[j].ed] = visit[arr[j].st] + arr[j].cost;
				res = 0;
			}
		}

	}
	return res;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 2; i <= n; i++) visit[i] = MAX;
	for (int i = 0; i < m; i++)
		scanf("%lld%lld%lld", &arr[i].st, &arr[i].ed, &arr[i].cost);
	if (BellmanFord())
	{
		for (int i = 2; i <= n; i++)
			printf("%lld\n", visit[i] == MAX ? -1 : visit[i]);
	}
	else printf("-1");
	return 0;
}
