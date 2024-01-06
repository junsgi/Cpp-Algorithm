#pragma warning(disable:4996)
#include<stdio.h>
using namespace std;
int n, arr[1'000'000], temp[1'000'000];

void merge(int start, int end)
{
	if (end - start <= 0) return;

	int mid = (start + end) / 2;
	merge(start, mid);
	merge(mid + 1, end);

	int leftSt = start, leftEd = mid;
	int rightSt = mid + 1, rightEd = end;
	int idx = 0;
	while (leftSt <= leftEd  && rightSt <= rightEd)
	{
		if (arr[leftSt] > arr[rightSt])
			temp[idx++] = arr[rightSt++];
		else
			temp[idx++] = arr[leftSt++];
	}
	if (leftSt <= leftEd)
	{
		while (leftSt <= leftEd)
			temp[idx++] = arr[leftSt++];
	}
	else
	{
		while (rightSt <= rightEd)
			temp[idx++] = arr[rightSt++];
	}
	
	for (int i = 0, st = start; i < idx; i++, st++)
		arr[st] = temp[i];
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	merge(0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);
	return 0;
}

