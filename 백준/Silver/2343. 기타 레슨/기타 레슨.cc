#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m, ans=0x7fffffff;
int arr[100001];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int le = 1, ri = 1'000'000'100, mid = 0;
	while (le <= ri)
	{
		mid = (le + ri) / 2;
		int cnt = 0, sum = 0, swi = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] <= mid)
			{
				sum += arr[i];
				if (sum >= mid)
				{
					cnt++;
					if (sum == mid) sum = 0;
					else sum = arr[i];
				}
			}
			else 
			{
				swi = 1;
				break;
			}

		}
		if (sum) cnt++;
		if (swi || cnt > m)
			le = mid + 1;
		else
			ri = mid - 1;
	}
	printf("%d", le);

	return 0;
}
