#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
#define M 201
#define MIN(x,y) (((x)>(y)) ? (y):(x))
using namespace std;
struct temp
{
	int c[3];
}t;
int visit[M][M][M], dire[6][2] = { {0, 1}, {0, 2}, {1, 0}, {1, 2}, {2, 0}, {2, 1} };
int check[M], st = -1, ed = -1, cup[3];
temp que[M * M * M];
vector<int> answer;
int main()
{
	scanf("%d%d%d", &cup[0], &cup[1], &cup[2]);
	visit[0][0][cup[2]] = 1;
	t.c[0] = 0;
	t.c[1] = 0;
	t.c[2] = cup[2];

	que[++ed] = t;
	while (st != ed)
	{
		t = que[++st];
		if (!t.c[0] && !check[t.c[2]])
			answer.push_back(t.c[2]);

		for (int i = 0; i < 6; i++)
		{
			temp COPY = t;
			if (!COPY.c[dire[i][0]]) continue;
			if (COPY.c[dire[i][1]] == cup[dire[i][1]]) continue;

			int volumn = MIN(COPY.c[dire[i][0]], cup[dire[i][1]] - COPY.c[dire[i][1]]);
			COPY.c[dire[i][0]] -= volumn;
			COPY.c[dire[i][1]] += volumn;
			if (visit[COPY.c[0]][COPY.c[1]][COPY.c[2]]) continue;
			visit[COPY.c[0]][COPY.c[1]][COPY.c[2]] = 1;
			que[++ed] = COPY;
		}
	}
	sort(answer.begin(), answer.end());
	for (int i : answer) printf("%d ", i);
	return 0;
}
