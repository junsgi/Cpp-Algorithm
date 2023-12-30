#include<stdio.h>
int n, heap[100001], len;

void up(int idx)
{
	
	if (idx / 2 <= 0)
		return;
	if(heap[idx] < heap[idx / 2])
	{
		int t;
		t = heap[idx];
		heap[idx] = heap[idx / 2];
		heap[idx / 2] = t;
		up(idx / 2);
	}
}

void down(int idx)
{
	int t, tidx;
	tidx = idx * 2;
	if (tidx > len)
		return;

	if (tidx + 1 <= len && heap[tidx] > heap[tidx + 1]) tidx++;
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

	for(int i = 0; i < n ; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		if (tmp == 0)
		{
			if (len == 0) printf("0\n");
			else 
			{
				printf("%d\n", heap[1]);
				heap[1] = heap[len--];
				down(1);
			}
		}
		else
		{
			heap[++len] = tmp;
			up(len);
		}
	}
	return 0;
}