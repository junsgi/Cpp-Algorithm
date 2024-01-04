/*
중간 값은 중간 값보다 작은 값들 중에서 최댓값보다 커야하고
중간 값보다 큰 값들 중에서 최솟값보다 작아야한다.

최소 힙에는 max(mid, input)값을 삽입하고
최대 힙에는 min(mid, input)값을 삽입하여 
두 힙의 길이에 따라 mid값을 지정한다.

입력값이 들어오기 전 두 힙의 길이가 같다면 
 - 중간 값과 입력 값 중 가장 큰 값을 최소 힙에 작은 값을 최대 힙에 삽입
 - 최대 힙에는 항상 작은 수만 삽입되므로 최대 힙의 루트 값을 mid로 지정

입력값이 들어오기 전 두 힙의 길이가 다르다면
 - 중간 값과 입력 값 중 가장 큰 값을 최소 힙에 작은 값을 최대 힙에 삽입
 - 최대 힙의 길이가 더 길다면 최대 힙 루트 값을 mid로 지정
 - 최소 힙의 길이가 더 길다면 최소 힙 루트 값을 mid로 지정
*/

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
