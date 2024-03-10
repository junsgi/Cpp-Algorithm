#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#define M 500'000
using namespace std;
struct temp
{
	int st, ed, idx;
}arr[M * 2];
int n, m, t, check[M];
int cmp(temp x, temp y) { return x.st < y.st || x.st == y.st && x.ed > y.ed; }
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		arr[i].st = a; arr[i].ed = b; arr[i].idx = i;
		if (a > b)
			arr[i].ed = n + b;
		else // 노선을 하나 더 추가한다.
		{
			arr[t + m].st = n + a;
			arr[t + m].ed = n + b;
			arr[t + m].idx = i;
			t++;
		}
	}
	sort(arr, arr + m + t, cmp);
	int end = 0;
	for (int i = 0; i < m + t; i++)
	{
		// 가장 긴 노선을 제외한 모든 노선 제외
		if (arr[i].ed <= end) check[arr[i].idx] = 1;
		else end = arr[i].ed;
	}
	for (int i = 0; i < m; i++)
		if (!check[i]) printf("%d ", i + 1);
	return 0;
}
