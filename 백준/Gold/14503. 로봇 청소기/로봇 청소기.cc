#pragma warning(disable:4996)
#include <stdio.h>
using namespace std;
int n, m, graph[55][55], rx, ry, rd, ans;
int dire[2][4] = { {0, 1, 0, -1}, {-1, 0, 1, 0} };
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
int dirty(int x, int y, int d)
{
	for (int i = 1; i <= 4; i++)
	{
		int td = (d + i) % 4;
		int tx = x + dire[0][td];
		int ty = y + dire[1][td];
		
		if (!(0 <= tx && tx < n && 0 <= ty && ty < m))
			continue;
		// 벽이거나 깨끗하다면
		if (graph[tx][ty] >= 1)
			continue;

		return td;
	}
	
	return -1;
}
void DFS(int x, int y, int d)
{
	if (graph[x][y] == 0)
	{
		graph[x][y] = 2;
		ans++;
	}
	int tx = 0;
	int ty = 0;
	int td = dirty(x, y, d);
	if (td != -1)
	{
		// 반시계 90도 회전
		d = td;
		tx = x + dire[0][d];
		ty = y + dire[1][d];
		DFS(tx, ty, d);
	}
	else
	{
		tx = x + -dire[0][d];
		ty = y + -dire[1][d];
		if (!(0 <= tx && tx < n && 0 <= ty && ty < m) ||
			graph[tx][ty] == 1)
			return;
		DFS(tx, ty, d);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	scanf("%d%d%d", &rx, &ry, &rd);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &graph[i][j]);
	DFS(rx, ry, 3 - rd);
	printf("%d", ans);
	return 0;
}