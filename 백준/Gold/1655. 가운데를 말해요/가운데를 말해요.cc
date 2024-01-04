#pragma warning(disable:4996)
#include <stdio.h>
using namespace std;
int maxHeap[100001], maxLen, minLen, n, mid, m, minHeap[100001], MAX, MIN;
void up(int idx, int heap[])
{
	if (idx / 2 <= 0) return;

	if (heap[idx / 2] > heap[idx])
	{
		int tmp = heap[idx];
		heap[idx] = heap[idx / 2];
		heap[idx / 2] = tmp;
		up(idx / 2, heap);
	}
}
void down(int idx, int heap[], int len)
{
	if (idx * 2 > len) return;
	int child = 0;
	if (heap[idx * 2] < heap[idx * 2 + 1])
		child = idx * 2;
	else
		child = idx * 2 + 1;

	if (heap[idx] > heap[child])
	{
		int tmp = heap[idx];
		heap[idx] = heap[child];
		heap[child] = tmp;
		down(child, heap, len);
	}
}

int main()
{
	scanf("%d", &n);
	scanf("%d", &mid);
	printf("%d\n", mid);
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d", &m);
		int MAX = m < mid ? mid : m;
		int MIN = m < mid ? m : mid;

		if (maxLen == minLen)
		{
			minHeap[++minLen] = MAX;
			up(minLen, minHeap);

			maxHeap[++maxLen] = -MIN;
			up(maxLen, maxHeap);

			mid = -maxHeap[1];
			maxHeap[1] = maxHeap[maxLen--];
			down(1, maxHeap, maxLen);
		}
		else
		{
			minHeap[++minLen] = MAX;
			up(minLen, minHeap);

			maxHeap[++maxLen] = -MIN;
			up(maxLen, maxHeap);

			if (minLen < maxLen)
			{
				mid = -maxHeap[1];
				maxHeap[1] = maxHeap[maxLen--];
				down(1, maxHeap, maxLen);
			}
			else
			{
				mid = minHeap[1];
				minHeap[1] = minHeap[minLen--];
				down(1, minHeap, minLen);
			}
		}
		printf("%d\n", mid);

	}
	return 0;
}