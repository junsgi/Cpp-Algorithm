#pragma warning(disable:4996)
#include<stdio.h>
#include<queue>
#define M 1'000'000'000
using namespace std;
struct temp {
	int x, y, KEY;
}t;
int n, m, sx, sy, visit[1 << 6][60][60];
int dire[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
char graph[60][60];
queue<temp> que;

int BFS()
{
	que.push({ sx, sy, 0 });
	visit[0][sx][sy] = 1;

	while (!que.empty())
	{
		t = que.front();
		que.pop();
		int x = t.x;
		int y = t.y;
		int KEY = t.KEY;
		for (int i = 0; i < 4; i++)
		{
			int tx = x + dire[i][0];
			int ty = y + dire[i][1];
			int tk = KEY;

			if (!(0 <= tx && tx < n)) continue;
			if (!(0 <= ty && ty < m)) continue;
			if (graph[tx][ty] == '1') return visit[KEY][x][y];
			if ('a' <= graph[tx][ty] && graph[tx][ty] <= 'z')
			{
				tk |= (1 << (graph[tx][ty] - 'a'));
				if (!visit[tk][tx][ty])
				{
					visit[tk][tx][ty] = visit[KEY][x][y] + 1;
					que.push({ tx, ty, tk });
				}
			}
			else if ('A' <= graph[tx][ty] && graph[tx][ty] <= 'Z')
			{
				if (tk & (1 << (graph[tx][ty] - 'A')) && !visit[tk][tx][ty])
				{
					visit[tk][tx][ty] = visit[KEY][x][y] + 1;
					que.push({ tx, ty, tk });
				}
			}
			else if (graph[tx][ty] == '.' && !visit[tk][tx][ty])
			{
				visit[tk][tx][ty] = visit[KEY][x][y] + 1;
				que.push({ tx, ty, tk });
			}
		}
	}

	return -1;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", &graph[i]);
		for (int j = 0; graph[i][j]; j++)
		{
			if (graph[i][j] == '0')
			{
				graph[i][j] = '.';
				sx = i;
				sy = j;
			}
		}
	}
	printf("%d", BFS());
	return 0;
}