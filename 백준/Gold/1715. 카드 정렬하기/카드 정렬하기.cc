#include<stdio.h>
int n, heap[100001], len;

void up(int idx) // 삽입
{
	
	if (idx / 2 <= 0) // 범위를 벗어나면 return
		return;

	if(heap[idx] < heap[idx / 2]) // 부모노드가 더 크다면 교체
	{
		int t;
		t = heap[idx];
		heap[idx] = heap[idx / 2];
		heap[idx / 2] = t;
		up(idx / 2);
	}
}

void down(int idx) // 재정렬
{
	int t, tidx;
	tidx = idx * 2;
	if (tidx > len)
		return;

	// 범위를 벗어나지 않으면서 왼쪽 자식보다 오른쪽 자식이 더 작다면 오른쪽 자식 선택
	if (tidx + 1 <= len && heap[tidx] > heap[tidx + 1]) tidx++;


	// 자식 노드보다 현재 노드가 더 크다면
	if (heap[idx] > heap[tidx])
	{
		t = heap[idx];
		heap[idx] = heap[tidx];
		heap[tidx] = t;
		down(tidx);
	}
}


int main()
{
	scanf("%d", &n);
	int ans = 0;
	for(int i = 0; i < n ; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		heap[++len] = tmp;
		up(len);
	}

	while (len != 1)
	{
		int t1 = heap[1];
		heap[1] = heap[len--];
		down(1);

		int t2 = heap[1];
		heap[1] = heap[len--];
		down(1);

		heap[++len] = t1 + t2;
		ans += t1 + t2;
		up(len);
	}
	printf("%d", ans);
	return 0;
}