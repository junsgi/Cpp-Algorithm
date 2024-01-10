#pragma warning(disable:4996)
#include<stdio.h>
int n, m, a[100000], temp[100000], t;

void merge(int st, int ed)
{
	if (st == ed) return;
	int mid = (st + ed) / 2;
	merge(st, mid);
	merge(mid + 1, ed);

	int leftSt = st, leftEd = mid;
	int rightSt = mid + 1, rightEd = ed;
	int idx = 0;
	while (leftSt <= leftEd && rightSt <= rightEd)
	{
		if (a[leftSt] < a[rightSt])
			temp[idx++] = a[leftSt++];
		else
			temp[idx++] = a[rightSt++];
	}

	while (leftSt <= leftEd)
		temp[idx++] = a[leftSt++];
	while (rightSt <= rightEd)
		temp[idx++] = a[rightSt++];
	for (int i = 0; i < idx; i++)
		a[st + i] = temp[i];

}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	merge(0, n - 1);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &t);
		int left = 0, right = n - 1, mid = 0, ans = 0;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (a[mid] < t) left = mid + 1;
			else if (a[mid] > t) right = mid - 1;
			else
			{
				ans = 1;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

