#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int n, idx;
pair<int, int> arr[2000001];
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
	sort(arr, arr + idx);
	int sum = 0, ans = 0;
	for (int i = 0; i < idx; i++)
	{
		sum += arr[i].second;
		ans = max(ans, sum);
	}
	printf("%d", ans);
	return 0;
}