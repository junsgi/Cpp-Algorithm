#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int n, idx, ans;
pair<int, int> arr[2000001];
int cmp(pair<int, int> x, pair<int, int> y)
{
	return x.first < y.first || (x.first == y.first && x.second > y.second);
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		arr[idx++] = { a, 1 };
		arr[idx++] = { b, -1 };
	}
	sort(arr, arr + (idx - 1), cmp);
	int sum = 0, x1= 5'000'000, y11=0;
	for (int i = 0; i < idx; i++)
	{
		sum += arr[i].second;
		x1 = min(x1, arr[i].first);
		y11 = max(y11, arr[i].first);
		if (sum == 0)
		{
			ans += y11 - x1;
			x1 = 5'000'000;
			y11 = 0;
			sum = 0;
		}
	}
	printf("%d", ans);
	return 0;
}