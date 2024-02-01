#pragma warning(disable:4996)
#include<stdio.h>
long long temp[2001], arr[2001];
int n, ans;
void merge(int st, int ed)
{
	if (ed - st <= 0) return;
	int mid = (st + ed) / 2;
	merge(st, mid);
	merge(mid + 1, ed);

	int leftSt = st, leftEd = mid;
	int rightSt = mid + 1, rightEd = ed;
	int idx = 0;
	while (leftSt <= leftEd && rightSt <= rightEd)
	{
		if (arr[leftSt] < arr[rightSt])
			temp[idx++] = arr[leftSt++];
		else
			temp[idx++] = arr[rightSt++];
	}
	while (leftSt <= leftEd)
		temp[idx++] = arr[leftSt++];
	while (rightSt <= rightEd)
		temp[idx++] = arr[rightSt++];
	for (int i = 0; i < idx; i++)
		arr[st + i] = temp[i];
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &arr[i]);
	merge(0, n - 1);
	for (int i = 0; i < n; i++)
	{
		long long num = arr[i];
		int p1 = 0, p2 = n - 1;

		while (p1 != p2)
		{
			if (p1 == i || p2 == i)
				p1 == i ? p1++ : p2--;
			else
			{
				if (arr[p1] + arr[p2] == num)
				{
					ans++;
					break;
				}
				else if (arr[p1] + arr[p2] < num)
					p1++;
				else
					p2--;
			}
			
		}
	}
	printf("%d", ans);
	return 0;
}
