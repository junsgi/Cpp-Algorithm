#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
int n, visit[1001], ans;
pii arr[1001];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d", &arr[i].first, &arr[i].second);

	for (int i = n; i > 0; i--)
	{
		int value = -1, idx = 0;
		for (int j = 0; j < n; j++)
		{
			if (visit[j]) continue;
			if (i <= arr[j].first && value < arr[j].second)
			{
				value = arr[j].second;
				idx = j;
			}
		}
		if (value > 0)
		{
			ans += value;
			visit[idx] = 1;
		}
	}
	printf("%d", ans);
	return 0;
}